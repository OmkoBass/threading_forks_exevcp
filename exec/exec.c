#include <stdio.h>
#include <unistd.h>

int main()
{
    //Pass the name of the exe and args
    char *args[] = {"./toRun.exe", NULL};
    
    //Execvp runs the other program
    execvp(args[0], args);

    //Done
    printf("Done!\n");

    return 0;
}
