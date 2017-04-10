#ifndef COMARCITECTURE_MYTERM_H
#define COMARCITECTURE_MYTERM_H

enum Colors
{
    WHITE = 7,
    LIGHT_GREY = 247,
    GREY = 237,
    BLACK = 0,
    RED = 124,
    GREEN = 41,
    BLUE = 20,
    YELLOW = 184,
};

int MT_ClrScr();
int MT_GotoXY(int x, int y);
int MT_GetScreenSize(int *rows, int *columns);

int MT_SetFgColor(enum Colors color);
int MT_SetBgColor(enum Colors color);
int MT_ResetColors();

#endif //COMARCITECTURE_MYTERM_H
