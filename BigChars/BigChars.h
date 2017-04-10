#ifndef COMARCITECTURE_BIGCHARS_H
#define COMARCITECTURE_BIGCHARS_H

#include <MyTerm.h>

int BC_PrintA(char *str);
int BC_Box(int x1, int y1, int x2, int y2);
int BC_PrintBigChar(int *big, int x, int y, enum Colors fgcolor, enum Colors bgcolor);
int BC_SetBigCharPos(int *big, int x, int y, short int value);
int BC_GetBigCharPos(int *big, int x, int y, short int *value);
int BC_BigCharWrite(int fd, int *big, int count);
int BC_BigCharRead(int fd, int *big, int need_count, int *count);

#endif