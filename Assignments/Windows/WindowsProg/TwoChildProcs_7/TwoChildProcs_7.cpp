#include "pch.h"
#include<windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

int _tmain(int argc, TCHAR *argv[]) {
	PROCESS_INFORMATION pi1,pi2;
	STARTUPINFO si1,si2;
	UINT uExitCode = 1;

	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));

	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&si2, sizeof(pi2));

	if (argc != 3) {
		printf("Usage: %S [cmdline] , enter 2 child processess names\n", argv[0]);
		return 1;
	}
	LPCWSTR lpApplicationName_1 = argv[1];

	// Start the child process 1. 

	if (!CreateProcess(lpApplicationName_1,   //No module name (use command line)
		NULL,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si1,            // Pointer to STARTUPINFO structure
		&pi1)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		printf("CreateProcess failed (%d). For the process : %S\n", GetLastError(),argv[1]);
		return 1;
	}


	LPCWSTR lpApplicationName_2 = argv[2];

	// Start the child process 2. 

	if (!CreateProcess(lpApplicationName_2,   //No module name (use command line)
		NULL,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si2,            // Pointer to STARTUPINFO structure
		&pi2)           // Pointer to PROCESS_INFORMATION structure
		);
	{
		printf("CreateProcess failed (%d). For the process : %S\n", GetLastError(), argv[2]);
		return 1;
	}


	/*TerminateProcess(pi1.hProcess, uExitCode);
	TerminateProcess(pi2.hProcess,uExitCode);*/


	wcout << "Process_ID of process - " << argv[1] << " : " << GetProcessId(pi1.hProcess);
	wcout << "Process_ID of process - " << argv[2] << " : " << GetProcessId(pi2.hProcess);


}