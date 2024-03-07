#include <windows.h>
#include <stdio.h>
int main() {
    STARTUPINFO si={0};
    PROCESS_INFORMATION pi={0};
    
    if (!CreateProcess(NULL,   
                       "cmd /c code .",
                       NULL,     
                       NULL,     
                       FALSE,    
                       CREATE_NO_WINDOW,        
                       NULL,     
                       NULL,     
                       &si,      
                       &pi))     
    {
        printf("CreateProcess failed (%ld).\n", GetLastError());
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

