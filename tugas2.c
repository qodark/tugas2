#include <stdio.h>
#include <windows.h>
int main(VOID)
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  /* allocate memory */
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));
  
    /* create child proses */
    if (!CreateProses(NULL, /*use command line */
    "C:\\WINDOWS\\system32\\mspaint.exe", /* command */
    NULL, /* don't inherit process handle */
    NULL, /* don't inherit thread handle */
    FALSE, /* disable handle inheritance */
    0, /* no creation flags */
    NULL, /* use parent's environment blocj */
    NULL, /* use parent's existing directory */
    &si,
    &pi))
      {
      fprintf(stderr, "Create Process Failed");
      return -1;
      }
 /* parent will wait for the child to complete */
 WaitForSingleObject(pi.hProses, INFINITE);
 printf("Child Complete");
 printf("14201218 - Qodar Khairudin");
   /* close handles */
   CloseHandle(pi.hProcess);
   CloseHandle(pi.hThread);
   }
