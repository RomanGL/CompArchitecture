#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <memory.h>

#include "MyTerm.h"

int MT_GetScreenSize(int *rows, int *columns)
{
    struct winsize ws;
    if (!ioctl(1, TIOCGWINSZ, &ws))
    {
        *rows = ws.ws_row;
        *columns = ws.ws_col;
        return 0;
    }
    else
        return -1;
}

int MT_ClrScr()
{
    char *data;
    data = "\E[H\E[2J";

    int size = strlen(data) * sizeof(char);
    return MT_WriteIntoTerm(data, size);
}

int MT_GotoXY(int x, int y)
{
    char data[30];
    sprintf(data, "\E[%d;%dH", x, y);

    int size = strlen(data) * sizeof(char);
    return MT_WriteIntoTerm(&data, size);
}

int MT_SetFgColor(enum Colors color)
{
    char data[30];
    sprintf(data, "\e[38;5;%dm", color);

    int size = strlen(data) * sizeof(char);
    return MT_WriteIntoTerm(&data, size);
}

int MT_SetBgColor(enum Colors color)
{
    char data[30];
    sprintf(data, "\e[48;5;%dm", color);

    int size = strlen(data) * sizeof(char);
    return MT_WriteIntoTerm(&data, size);
}

int MT_ResetColors()
{
    char *data = "\e[m";
    int size = strlen(data) * sizeof(char);
    return MT_WriteIntoTerm(data, size);
}

int MT_WriteIntoTerm(char *data, int size)
{
    if (write(STDOUT_FILENO, data, strlen(data)) < size)
        return -1;

    return 0;
}
