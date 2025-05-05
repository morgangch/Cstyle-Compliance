/*
** EPITECH PROJECT, 2025
** Workshop-CStyle
** File description:
** ex_04
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *get_error_message(int err)
{
    switch (err) {
        case 0:
            return "No error.";
        case 1:
            return "Memory allocation failed.";
        case 2:
            return "Input string is empty.";
        case 3:
            return "Input string is too long.";
        case 4:
        default:
            return "Unknown error.";
    }
}

int validate_input(const char *input)
{
    if (!input || input[0] == '\0')
        return 2;
    if (strlen(input) > 64)
        return 3;
    return 0;
}

int duplicate_input(const char *input, char **out)
{
    int check = validate_input(input);

    if (check != 0)
        return check;
    *out = malloc(strlen(input) + 1);
    if (!*out)
        return 1;
    strcpy(*out, input);
    return 0;
}

int main(void)
{
    const char *test_cases[] = {"Hello World!", "",
        "This string is way too long. This string is way too long. This "
        "string is way too long.",
        NULL};

    for (int i = 0; i < 4; i++) {
        char *copy = NULL;
        int err = duplicate_input(test_cases[i], &copy);

        if (err != 0) {
            printf(
                "Error with input #%d: %s\n", i + 1, get_error_message(err));
        } else {
            printf("Copy #%d: %s\n", i + 1, copy);
            free(copy);
        }
    }
    return 0;
}
