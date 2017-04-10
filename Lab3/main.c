#include <stdio.h>
#include "MyTerm.h"

int main()
{
    MT_SetFgColor(RED);
    MT_SetBgColor(GREY);

    MT_ClrScr();

    MT_GotoXY(2, 5);

    int r, c;
    MT_GetScreenSize(&r, &c);
    printf("Size: %dx%d\n", r, c);

    MT_ResetColors();
    return 0;
}