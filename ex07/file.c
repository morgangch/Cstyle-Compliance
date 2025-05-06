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

int get_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int get_average(void)
{
    return (7);
}

int main(int ac, char **av, char **env)
{
    int i = get_strlen(av[1] == NULL ? "NULL" : av[1]) == 4 ? 0 : 1;
    int j = i == 0 ? 0 : get_average();
    char *str = malloc(sizeof(char) * 100);

    if (str == NULL) {
        return (84);
    }
    i == 0 ? strcpy(str, "Hello") : strcpy(str, "World");
    printf("%s\n", str);
}