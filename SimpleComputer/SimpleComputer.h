#ifndef COMARCITECTURE_SIMPLECOMPUTER_H
#define COMARCITECTURE_SIMPLECOMPUTER_H

#define MEMORY_SIZE 100

typedef enum
{
    FLG_OVERFLOW = 0x1, // 1
    FLG_ZERO_DIVISION = 0x2, // 2
    FLG_MEMORY_FAULT = 0x4, // 4
    FLG_TICK_IGNORE = 0x8, // 8
    FLG_WRONG_COMMAND = 0x10 // 16
} Flg_T;

typedef struct
{
    int accum;
    int count;
    int flg;
} Reg_T;

enum SC_Error
{
    ADDRESS_ERROR = 1,
    FILE_ERROR,
    REG_ERROR,
    COMMAND_ERROR,
};

int SC_MemoryInit();

int SC_MemorySet(int address, int value);
int SC_MemoryGet(int address, int *value);

int SC_MemorySave(char *fileName);
int SC_MemoryLoad(char *fileName);

int SC_RegInit();
int SC_RegSet(int regist, int value);
int SC_RegGet(int regist, int *value);

int SC_CommandEncode(int command, int operand, int *value);
int SC_CommandDecode(int value, int *command, int *operand);

#endif //COMARCITECTURE_SIMPLECOMPUTER_H
