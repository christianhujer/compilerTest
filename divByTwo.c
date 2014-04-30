// Compiler test case to see whether the compiler is replacing a division by two with a shift.
// The best thing a compiler can do is replace this with a shift.
// The second best thing a compiler can do is use a div instruction.
// The worst thing a compiler can do is call a generic division function just to divide by two.
// The expected machine code for this module is:
// foo
//      ASR #1, R0
//      RTS
// If no shift by constant is available:
// foo
//      MOV #1, R1
//      ASR R1, R0
//      RTS
// Or at least
// foo
//      MOV #2, R1
//      DIV R0, R1, R0
//      RTS
// But certainly not
// foo
//      MOV #2, R1
//      JMP div
// Or even worse
// foo
//      MOV #2, R1
//      JSR div
//      RTS
int foo(int n)
{
    return n / 2;
}
