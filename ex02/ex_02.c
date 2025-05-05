/*
** EPITECH PROJECT, 2025
** Workshop-CStyle
** File description:
** ex_02
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void process_values(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            for (int j = 0; j < size; j++) {
                if (arr[j] % 3 == 0) {
                    if (arr[i] + arr[j] > 50) {
                        while (arr[i] > 0) {
                            if (arr[j] > 0) {
                                printf("i: %d, j: %d -> %d\n", i, j,
                                    arr[i] + arr[j]);
                                arr[i]--;
                                arr[j]--;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(void)
{
    int array[] = {12, 15, 8, 9, 22, 30};
    int size = sizeof(array) / sizeof(array[0]);

    process_values(array, size);
    return 0;
}
