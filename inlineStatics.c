// Compiler test case to see whether the compiler is inlining small static functions well.
// Inlining small static functions reduces footprint and increases performance at the same time.
// The expected machine code for this module is:
// main
//      MOV #15, R0
//      RTS
static int foo(void)
{
    return 5;
}

static int bar(void)
{
    return 10;
}

int main(void)
{
    return foo() + bar();
}
