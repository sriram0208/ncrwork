
#include "pch.h"
#include<windows.h>
#include <iostream>
#include<tchar.h>
using namespace std;

int _tmain(int argc, TCHAR *argv[]) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (argc != 2)
	{
		printf("Usage: %S [cmdline] , enter child process module\n", argv[0]);
		return 1;
	}
	LPCWSTR lpApplicationName = argv[1];
	// Start the child process. 
	if (!CreateProcess(lpApplicationName,   //No module name (use command line)
		NULL,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return 1;
	}

	// Wait until child process exits.
	WaitForSingleObject(pi.hProcess, INFINITE);

	wcout<<"Child Process_ID : "<<GetProcessId(pi.hProcess)<<endl;
	wcout << "Child Thread_ID : " << GetProcessId(pi.hThread) << endl;
	wcout << "Current Process_ID : " << GetCurrentProcessId() << endl;
	wcout << "Current Thread_ID : " << GetCurrentThreadId() << endl;
	wcout << "Process_ID of thread : " << GetProcessIdOfThread(pi.hThread) << endl;


	return 0;
}
