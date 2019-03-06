#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>
#include<stdio.h>
#define BUFFER_SIZE 100
int _tmain(int argc, TCHAR *argv[]) {

	HANDLE hExistingfile;
	hExistingfile = CreateFile(					//Creating File for reading
		argv[1],
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hExistingfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(TEXT("Terminal failure: Unable to open file \"%s\" to read.\n"), argv[1]);
		return 1;
	}

	BOOL bErrorReport;
	char readBuffer[BUFFER_SIZE] = { 0 };
	LPDWORD lpNoOfBytesRead = 0;

	bErrorReport = ReadFile(
		hExistingfile,
		readBuffer,
		BUFFER_SIZE - 1,
		lpNoOfBytesRead,
		NULL
	);

	if (FALSE == bErrorReport) {
		printf("Terminal failure: Unable to read from file.\n GetLastError=%08x\n", GetLastError());
		CloseHandle(hExistingfile);
		return 1;
	}

	printf("%s\n", readBuffer);

	getchar();
}