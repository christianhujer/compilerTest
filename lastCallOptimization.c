// Compiler test case to see whether the compiler is performing last call optimization.
// Last call optimization reduces stack consumption, increases footprint and increases performance.
// The expected machine code for this module is, assuming -O2 -Os:
// bar
//      LD  x, R0
//      INC R0
//      ST  R0, x
//      RTS
// foo
//      LD  y, R0
//      INC R0
//      ST  R0, y
//      JMP bar
// main
//      JMP foo
int x = 0;
int y = 0;

int bar(void)
{
    x++;
    return x;
}

int foo(void)
{
    y++;
    return bar();
}

int main(void)
{
    return foo();
}
