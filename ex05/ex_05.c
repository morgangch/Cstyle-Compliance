/*
** EPITECH PROJECT, 2025
** Workshop-CStyle
** File description:
** ex_05
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int func1(char **args, char *my_env[])
{
    int i = 0;

    while (args[i] != NULL) {
        if (strcmp(args[i], "exit") == 0) {
            printf("Exiting shell...\n");
            return 1;
        }
        i++;
    }
    return 0;
}

int func2(char **args, char *my_env[])
{
    int i = 0;

    while (args[i] != NULL) {
        if (strcmp(args[i], "cd") == 0) {
            printf("Changing directory...\n");
            return 1;
        }
    }
    return 0;
}

int func3(char **args, char *my_env[])
{
    int i = 0;

    while (args[i] != NULL) {
        if (strcmp(args[i], "env") == 0) {
            printf("Displaying environment variables...\n");
            return 1;
        }
    }
    return 0;
}

int func4(char **args, char *my_env[])
{
    int i = 0;

    while (args[i] != NULL) {
        if (strcmp(args[i], "setenv") == 0) {
            printf("Setting environment variable...\n");
            return 1;
        }
    }
    return 0;
}

int lib_comm(char **args, char *my_env[])
{
    int i = 0;

    i += func1(args, my_env);
    i += func2(args, my_env);
    i += func3(args, my_env);
    if (i == 0)
        i += func4(args, my_env);
    return i;
}

int seak_comm(char *my_env[], char **args)
{
    if (args[0] == NULL)
        return 0;
    if (lib_comm(args, my_env) == 0) {
        printf("mysh: command not found: %s\n", args[0]);
        return 84;
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    int res = 0;
    char **new_args = malloc(sizeof(char *) * 2);
    new_args[0] = av[1];
    new_args[1] = NULL;

    if (ac != 2) {
        fprintf(stderr, "Usage: ./mysh cmd\n");
        return 84;
    }
    res = seak_comm(env, new_args);
    if (res == 84) {
        fprintf(stderr, "Error: command not found\n");
        return 84;
    }
}
