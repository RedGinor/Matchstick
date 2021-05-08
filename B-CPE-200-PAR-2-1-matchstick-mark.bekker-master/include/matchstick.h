/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** headers for matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdbool.h>

void print_turn(char *player, int match, int line);
void print_grid(bool **grid, int size);
bool remove_stick(bool **grid, int size, int pos, int sticks);
bool print_end(bool **grid, int size, bool end);
bool ia_move(bool **grid, int size, int moves);
bool end_game(bool **grid, int size);
bool **make_stick_grid(int size);
int get_error(int error, int move);
int get_sticks(bool **grid, int size, int pos);
int launch_game(int size, int moves);

#endif
