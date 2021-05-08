/*
** EPITECH PROJECT, 2021
** ia_move
** File description:
** makes ia moves
*/

#include <matchstick.h>
#include <stdlib.h>
#include "ib.h"

bool odd_total_sticks(bool **grid, int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
        total += get_sticks(grid, size, i + 1);
    return (total % 2);
}

int get_max_sticks(bool **grid, int size, int moves, int pos)
{
    int l0 = get_sticks(grid, size, pos);
    int l1 = get_sticks(grid, size, pos - 1);
    int sticks = l0 - l1;

    sticks -= (l0 > 1 && sticks == l0);
    if (sticks > 1 && odd_total_sticks(grid, size) && (sticks % 2))
        sticks--;
    sticks *= !(sticks > moves);
    sticks += (sticks == 0);
    return (sticks);
}

bool ia_move(bool **grid, int size, int moves)
{
    int pos = size;
    int l0 = get_sticks(grid, size, pos);
    int l1 = get_sticks(grid, size, pos - 1);
    int sticks = 0;

    print_grid(grid, size);
    ib_putstr("\nAI's turn...\n");
    while (pos > 0 && l1 > 0 && (l0 <= l1 || l0 == 1)) {
        pos--;
        l0 = get_sticks(grid, size, pos);
        l1 = get_sticks(grid, size, pos - 1);
    }
    sticks = get_max_sticks(grid, size, moves, pos);
    remove_stick(grid, size, pos, sticks);
    print_turn("AI", sticks, pos);
    return (0);
}