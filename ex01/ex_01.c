/*
** EPITECH PROJECT, 2025
** Workshop-CStyle
** File description:
** ex_01
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int g(int t, int u)
{
    return t * u;
}

int a(int t, int u)
{
    return t + u;
}

int h(int t, int u)
{
    return t - u;
}

bool k(int i)
{
    return i > 0;
}

char *f(char *s1, char const *s2)
{
    int i = 0;

    for (; s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return s1;
}
