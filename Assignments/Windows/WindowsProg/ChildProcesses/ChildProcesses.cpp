
#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>

void CreateChildProcess(TCHAR *);

void CreateChildProcess(TCHAR tProcName[])
// Create a child process that uses the previously created pipes for STDIN and STDOUT.
{
	PROCESS_INFORMATION piProcInfo;
	STARTUPINFO siStartInfo;
	BOOL bSuccess = FALSE;

	// Set up members of the PROCESS_INFORMATION structure. 

	ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));

	// Set up members of the STARTUPINFO structure. 
	// This structure specifies the STDIN and STDOUT handles for redirection.

	ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
	siStartInfo.cb = sizeof(STARTUPINFO);

	// Create the child process. 

	bSuccess = CreateProcess((LPCWSTR)tProcName,
		NULL,     // command line 
		NULL,          // process security attributes 
		NULL,          // primary thread security attributes 
		TRUE,          // handles are inherited 
		0,             // creation flags 
		NULL,          // use parent's environment 
		NULL,          // use parent's current directory 
		&siStartInfo,  // STARTUPINFO pointer 
		&piProcInfo);  // receives PROCESS_INFORMATION 

	 // If an error occurs, exit the application. 
	if (!bSuccess) {
		printf("CreateProcess failed (%d).\n", GetLastError());
		return;
	}
	else
	{
		// Close handles to the child process and its primary thread.
		// Some applications might keep these handles to monitor the status
		// of the child process, for example. 

		CloseHandle(piProcInfo.hProcess);
		CloseHandle(piProcInfo.hThread);
	}
}
int _tmain(int argc, TCHAR *argv[]) {
	CreateChildProcess(argv[1]);
//	CreateChildProcess(argv[2]);
}