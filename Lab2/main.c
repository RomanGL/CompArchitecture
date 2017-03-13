#include <stdio.h>
#include "SimpleComputer.h"

int main() {
    SC_MemoryInit();
    SC_RegInit();

    SC_RegSet(FLG_TICK_IGNORE, 1);
    SC_MemorySet(32, 1997);
    SC_RegSet(FLG_TICK_IGNORE, 1);

    int data;
    int regd, regt;

    SC_RegGet(FLG_MEMORY_FAULT, &regd);
    SC_RegGet(FLG_TICK_IGNORE, &regt);
    SC_MemoryGet(32, &data);

    printf("data = %d\nregd = %d\nregt = %d\n", data, regd, regt);
    SC_MemorySave("memory.txt");
    SC_MemoryLoad("memory.txt");

    int val;
    SC_CommandEncode(76, 150, &val);
    printf("val = %d\n", val);

    int com, op;
    SC_CommandDecode(val, &com, &op);
    printf("com = %d\nop = %d\n", com, op);

    return 0;
}