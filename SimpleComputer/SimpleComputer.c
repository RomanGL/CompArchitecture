#include <stdlib.h>
#include "SimpleComputer.h"

#define MEMORY_SIZE 100

int *memory;

int SC_MemoryInit()
{
    memory = calloc(MEMORY_SIZE, sizeof(int));
    return 1;
}

int SC_MemorySet(int address, int value);
int SC_MemoryGet(int address, int *value)
{
    *value = memory[address];
    return 1;
}

int SC_MemorySave(char *fileName);
int SC_MemoryLoad(char *fileName);

int SC_RegInit();
int SC_RegSet(int register, int value);
int SC_RegGet(int register, int *value);

int SC_CommandEncode(int command, int operand, int *value);
int SC_CommandDecode(int value, int *command, int *operand);