#include <unistd.h>
#include <stdio.h>
#include <memory.h>
#include "MyGUI.h"
#include "MyTerm.h"
#include "BigChars.h"
#include "SimpleComputer.h"

int digit[18][2] = {{0x4242423C, 0x3C424242},  // 0
                    {0x48506040, 0x40404040},  // 1
                    {0x2042423C, 0x7E020418},  // 2
                    {0x3840423C, 0x3C424040},  // 3
                    {0x7E424478, 0x40404040},  // 4
                    {0x3E02027E, 0x3C424040},  // 5
                    {0x3E02423C, 0x3C424242},  // 6
                    {0x2040407E, 0x10101010},  // 7
                    {0x3C42423C, 0x3C424242},  // 8
                    {0x7C42423C, 0x3C424040},  // 9
                    {0x66663C18, 0x66667E7E},  // A
                    {0x3E66663E, 0x3E666666},  // B
                    {0x0202423C, 0x3C420202},  // C
                    {0x4444443E, 0x3E444444},  // D
                    {0x3E02027E, 0x7E020202},  // E
                    {0x1E02027E, 0x02020202},  // F
                    {0x7E181800, 0x0018187E},  // +
                    {0x00181800, 0x00181800}}; // :

void MG_MemoryBox()
{
    MT_SetBgColor(GREY);
    MT_SetFgColor(YELLOW);
    BC_Box(1, 1, 12, 63);
    MT_GotoXY(0, 28);
    write(STDOUT_FILENO, " Memory ", 8 * sizeof(char));
    MT_SetFgColor(GREEN);
    int k = 0;
    for (int j = 3; j < 63; j += 6)
    {
        for (int i = 2; i < 12; ++i)
        {
            MT_GotoXY(i, j);
            char buf[6];
            int val;
            SC_MemoryGet(k++, &val);
            sprintf(buf, "%04x", val);
            write(STDOUT_FILENO, buf , 6 * sizeof(char));
        }
    }
    MT_GotoXY(33, 0);
}

void MG_AccumBox()
{
    MT_SetBgColor(GREY);
    MT_SetFgColor(YELLOW);
    BC_Box(1, 64, 3, 39);
    MT_GotoXY(1, 77);
    write(STDOUT_FILENO, " accumulator ", 13 * sizeof(char));
    MT_SetFgColor(GREEN);
    MT_GotoXY(2, 80);
    char buf[5];
    int val;
    SC_AccumGet(&val);
    sprintf(buf, "%04x", val);
    write(STDOUT_FILENO, buf, 5 * sizeof(char));
    MT_GotoXY(33, 0);
}

void MG_CounterBox()
{
    MT_SetBgColor(GREY);
    MT_SetFgColor(YELLOW);
    BC_Box(4, 64, 3, 39);
    MT_GotoXY(4, 73);
    write(STDOUT_FILENO, " instructionCounter ", 20 * sizeof(char));
    MT_SetFgColor(GREEN);
    MT_GotoXY(5, 80);
    char buf[5];
    int val;
    SC_CountGet(&val);
    sprintf(buf, "%04x", val);
    write(STDOUT_FILENO, buf, 5 * sizeof(char));
    MT_GotoXY(33, 0);
}

void MG_OperationBox()
{
    MT_SetBgColor(GREY);
    MT_SetFgColor(YELLOW);
    BC_Box(7, 64, 3, 39);
    MT_GotoXY(7, 78);
    write(STDOUT_FILENO, " Operation ", 11 * sizeof(char));
    MT_SetFgColor(GREEN);
    MT_GotoXY(8, 79);
    write(STDOUT_FILENO, "+00 : 00", 8 * sizeof(char));
    MT_GotoXY(33, 0);
}

void MG_FlagBox()
{
    MT_SetBgColor(GREY);
    MT_SetFgColor(YELLOW);
    BC_Box(10, 64, 3, 39);
    MT_GotoXY(10, 79);
    write(STDOUT_FILENO, " Flags ", 7 * sizeof(char));
    MT_SetFgColor(GREEN);
    MT_GotoXY(11, 79);
    write(STDOUT_FILENO, "O E V M", 7 * sizeof(char));
    MT_GotoXY(33, 0);
}

void MG_KeyBox()
{
    MT_SetBgColor(GREY);
    MT_SetFgColor(YELLOW);
    BC_Box(13, 64, 12, 39);
    MT_GotoXY(13, 67);
    write(STDOUT_FILENO, " Keys ", 7 * sizeof(char));
    MT_SetFgColor(GREEN);
    char *str[7] = {"l - load", "s - save", "r - run", "t - step", "i - reset", "F5 - accumulator", "F6 - instructionCounter"};
    for (int i = 0; i < 7; i++)
    {
        MT_GotoXY(15 + i, 66);
        write(STDOUT_FILENO, str[i], strlen(str[i]));
    }
    MT_GotoXY(33, 0);
}

void MG_BcBox()
{
    MT_SetBgColor(GREY);
    MT_SetFgColor(YELLOW);
    BC_Box(13, 1, 12, 63);
    for (int i = 0; i < 6; i++)
    {
        int digit1[2] = {digit[1][2 * i], digit[1][2 * i + 1]};
        BC_PrintBigChar(digit1, BC_X, BC_START + i * BC_STEP, GREEN, GREY);
    }
    MT_GotoXY(33, 0);
}

void MG_Init()
{
    MG_MemoryBox();
    MG_AccumBox();
    MG_CounterBox();
    MG_OperationBox();
    MG_FlagBox();
    MG_KeyBox();
    MG_BcBox();
}