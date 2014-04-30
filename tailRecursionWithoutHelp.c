// Compiler test case to see whether the compiler is looping tail recursion even if there is no hint.
// Looping tail recursion reduces stack consumption and increases footprint at the same time.
// The footprint remains either unchanged or goes down as well.
// The expected machine code for this module is:
// nogauss
//      MOV R0, R1
//      CLR R0
//      TST R1
//      BLE .exit
// .loop
//      ADD R1, R0
//      DEC R1
//      JLE .loop
// .exit
//      RTS
// main
//      MOV #210, R0
//      RTS

int nogauss(int n)
{
    return n <= 0 ? 0 : n + nogauss(n - 1);
}

int main(void)
{
    return nogauss(20);
}
