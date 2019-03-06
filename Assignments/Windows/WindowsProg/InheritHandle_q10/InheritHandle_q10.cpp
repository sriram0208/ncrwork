
#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>
#include<stdio.h>
int _tmain(int argc, TCHAR *argv[]) {

	HANDLE hNewfile;
	char Buffer[] = "Hello! This is sriram!!";
	DWORD dwNoOfBytes = (DWORD)strlen(Buffer);
	DWORD dwBytesWritten;
	BOOL bErrorReport;
	LPSECURITY_ATTRIBUTES sa;
	sa->nLength = sizeof(SECURITY_ATTRIBUTES);
	sa->lpSecurityDescriptor = NULL;
	sa->bInheritHandle = TRUE;

	hNewfile = CreateFile(					//Creating File
		argv[1],
		GENERIC_READ | GENERIC_WRITE,
		0,
		sa,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hNewfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(TEXT("Terminal failure: Unable to open file \"%s\" for write.\n"), argv[1]);
		return 1;
	}
	PROCESS_INFORMATION piProcInfo;
	STARTUPINFO siStartInfo;
	BOOL bSuccess = FALSE;

	ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
	siStartInfo.cb = sizeof(STARTUPINFO);

	// Create the child process. 

	bSuccess = CreateProcess(argv[2],
		(TCHAR *)hNewfile,     // command line 
		NULL,          // process security attributes 
		NULL,          // primary thread security attributes 
		TRUE,          // handles are inherited 
		0,             // creation flags 
		NULL,          // use parent's environment 
		NULL,          // use parent's current directory 
		&siStartInfo,  // STARTUPINFO pointer 
		&piProcInfo);  // receives PROCESS_INFORMATION 

	if (!bSuccess)
		_tprintf(TEXT("Process creation failed\n"));

}