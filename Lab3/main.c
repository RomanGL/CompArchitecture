#include <stdio.h>
#include "MyTerm.h"

int main()
{
    MT_ClrScr();

    MT_GotoXY(2, 5);

    MT_SetFgColor(RED);
    MT_SetBgColor(GREY);

    int r, c;
    MT_GetScreenSize(&r, &c);
    printf("Size: %dx%d\n", r, c);

    MT_ResetColors();
    return 0;
}