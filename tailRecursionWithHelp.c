// Compiler test case to see whether the compiler is looping tail recursion.
// Looping tail recursion reduces stack consumption and increases footprint at the same time.
// The footprint remains either unchanged or goes down as well.
// The expected machine code for this module is:
// nogauss
//      TST R0
//      BEQ .L2
// .L1
//      ADD R0, R1
//      DEC R0
//      BNE .L1
//      MOV R1, R0
// .L2
//      RTS
// main
//      MOV #210, R0
//      RTS

static int nogaussR(int n, int sum)
{
    return n <= 0 ? sum : nogaussR(n - 1, sum + n);
}

int nogauss(int n)
{
    return nogaussR(n, 0);
}

int main(void)
{
    return nogauss(20);
}
