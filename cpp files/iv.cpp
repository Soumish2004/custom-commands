#include <windows.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    char command[] = "cmd /c ";
    char cmdd[100];

    sprintf(cmdd, "%s iverilog %svp -o %s",command, argv[1], argv[1]);
    if (!CreateProcess(NULL,   
                       cmdd, 
                       NULL,    
                       NULL,   
                       FALSE,  
                       NORMAL_PRIORITY_CLASS,      
                       NULL,   
                       NULL,   
                       &si,    
                       &pi))   
    {
        printf("CreateProcess failed (%lu).\n", GetLastError());
        return 1;
    }
    return 0;
}
