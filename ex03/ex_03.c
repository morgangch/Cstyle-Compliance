/*
** EPITECH PROJECT, 2025
** Workshop-CStyle
** File description:
** ex_03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user_s {
    char name[32];
    int age;
    int score;
} user_t;

typedef struct group_s {
    user_t *users;
    int count;
} group_t;

void init_user(user_t *user, const char *name, int age, int score)
{
    strncpy(user->name, name, 31);
    user->name[31] = '\0';
    user->age = age;
    user->score = score;
}

void init_group(group_t *group, int count)
{
    group->users = malloc(sizeof(user_t) * count);
    group->count = count;
    for (int i = 0; i < count; i++) {
        char name[32];
        snprintf(name, 32, "User%d", i + 1);
        init_user(&group->users[i], name, 18 + (i % 5), (i * 7 + 3) % 100);
    }
}

void display_user(const user_t *user)
{
    printf("%s (age %d): %d points\n", user->name, user->age, user->score);
}

void display_group(const group_t *group)
{
    for (int i = 0; i < group->count; i++)
        display_user(&group->users[i]);
}

void sort_group_by_name(group_t *group)
{
    for (int i = 0; i < group->count - 1; i++) {
        for (int j = i + 1; j < group->count; j++) {
            if (strcmp(group->users[i].name, group->users[j].name) > 0) {
                user_t tmp = group->users[i];
                group->users[i] = group->users[j];
                group->users[j] = tmp;
            }
        }
    }
}

void sort_group_by_score(group_t *group)
{
    for (int i = 0; i < group->count - 1; i++) {
        for (int j = i + 1; j < group->count; j++) {
            if (group->users[i].score < group->users[j].score) {
                user_t tmp = group->users[i];
                group->users[i] = group->users[j];
                group->users[j] = tmp;
            }
        }
    }
}

user_t *find_best_user(const group_t *group)
{
    if (!group || group->count == 0)
        return NULL;
    user_t *best = &group->users[0];
    for (int i = 1; i < group->count; i++) {
        if (group->users[i].score > best->score)
            best = &group->users[i];
    }
    return best;
}

void free_group(group_t *group)
{
    free(group->users);
    group->users = NULL;
    group->count = 0;
}

int main(void)
{
    group_t group;
    init_group(&group, 6);

    printf("=== Users ===\n");
    display_group(&group);

    sort_group_by_score(&group);
    printf("\n=== Sorted by score ===\n");
    display_group(&group);

    sort_group_by_name(&group);
    printf("\n=== Sorted by name ===\n");
    display_group(&group);

    user_t *best = find_best_user(&group);
    if (best)
        printf("\nBest user: %s with %d points\n", best->name, best->score);

    free_group(&group);
    return 0;
}
