#ifndef COMARCITECTURE_SIMPLECOMPUTER_H
#define COMARCITECTURE_SIMPLECOMPUTER_H

int SC_MemoryInit();

int SC_MemorySet(int address, int value);
int SC_MemoryGet(int address, int *value);

int SC_MemorySave(char *fileName);
int SC_MemoryLoad(char *fileName);

int SC_RegInit();
int SC_RegSet(int register, int value);
int SC_RegGet(int register, int *value);

int SC_CommandEncode(int command, int operand, int *value);
int SC_CommandDecode(int value, int *command, int *operand);

#endif //COMARCITECTURE_SIMPLECOMPUTER_H
