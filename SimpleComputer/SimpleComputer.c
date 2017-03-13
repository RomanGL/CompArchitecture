#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "SimpleComputer.h"

Reg_T reg;
int memory[MEMORY_SIZE];

int SC_MemoryInit()
{
    memset(memory, 0, MEMORY_SIZE * sizeof(int));
    return 0;
}

int SC_MemorySet(int address, int value)
{
    if ((address < MEMORY_SIZE) && (address >= 0))
        memory[address] = value;
    else
    {
        SC_RegSet(FLG_MEMORY_FAULT, 1);
        return ADDRESS_ERROR;
    }
    return 0;
}

int SC_MemoryGet(int address, int *value)
{
    if ((address < MEMORY_SIZE) && (address >= 0))
        *value = memory[address];
    else
    {
        SC_RegSet(FLG_MEMORY_FAULT, 1);
        return ADDRESS_ERROR;
    }
    return 0;
}


int SC_MemorySave(char *fileName)
{
    FILE *ptrsave = fopen(fileName, "wb");
    if (ptrsave !=  NULL)
    {
        fwrite(memory, sizeof(int), MEMORY_SIZE, ptrsave);
        fclose(ptrsave);
    } else return FILE_ERROR;
    return 0;
}

int SC_MemoryLoad(char *fileName)
{
    FILE *ptrload = fopen(fileName, "rb");
    if (ptrload != NULL)
    {
        fread(memory, sizeof(int), MEMORY_SIZE, ptrload);
        fclose(ptrload);
    } else return FILE_ERROR;
    return 0;
}


int SC_RegInit()
{
    reg.accum = 0;
    reg.count = 0;
    reg.flg = 0;
    return 0;
}

int SC_RegSet(int regist, int value)
{
    if (value == 1)
    {
        switch (regist)
        {
            case FLG_OVERFLOW:
            case FLG_ZERO_DIVISION:
            case FLG_MEMORY_FAULT:
            case FLG_TICK_IGNORE:
            case FLG_WRONG_COMMAND:
                reg.flg |= regist;
                break;
            default:
                return REG_ERROR;
        }
    }
    else if (value == 0)
    {
        switch (regist)
        {
            case FLG_OVERFLOW:
            case FLG_ZERO_DIVISION:
            case FLG_MEMORY_FAULT:
            case FLG_TICK_IGNORE:
            case FLG_WRONG_COMMAND:
                reg.flg &= ~regist;
                break;
            default:
                return REG_ERROR;
        }
    }
    else
        return REG_ERROR;
    return 0;
}

int SC_RegGet(int regist, int *value)
{
    switch (regist)
    {
        case FLG_OVERFLOW:
        case FLG_ZERO_DIVISION:
        case FLG_MEMORY_FAULT:
        case FLG_TICK_IGNORE:
        case FLG_WRONG_COMMAND:
            *value = (reg.flg & regist) > 0 ? 1 : 0;
            break;
        default:
            return REG_ERROR;
    }
    return 0;
}


int SC_CommandEncode(int command, int operand, int *value)
{
    int16_t tmp = 0;
    tmp |= command;
    tmp <<= 7;
    tmp |= operand;
    tmp |= 0 << 14;
    *value = tmp;
    return 0;
}

int SC_CommandDecode(int value, int *command, int *operand)
{
    if ((value & (1 << 14)) != 0)
    {
        SC_RegSet(FLG_WRONG_COMMAND, 1);
        return COMMAND_ERROR;
    }
    *operand = value & 0x7f;
    *command = value >> 7;
    return 0;
}