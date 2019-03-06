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

	hNewfile = CreateFile(					//Creating File
		argv[1],
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hNewfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(TEXT("Terminal failure: Unable to open file \"%s\" for write.\n"), argv[1]);
		return 1;
	}

	_tprintf(TEXT("Writing data to file : %s.\n"), argv[1]);

	bErrorReport = WriteFile(					//Writing to file

		hNewfile,
		Buffer,
		dwNoOfBytes,
		&dwBytesWritten,
		NULL
	);
	if (FALSE == bErrorReport)
	{
		printf("Terminal failure: Unable to write to file.\n");
	}
	else
	{
		if (dwBytesWritten != dwNoOfBytes)
		{
			// This is an error because a synchronous write that results in
			// success (WriteFile returns TRUE) should write all data as
			// requested. This would not necessarily be the case for
			// asynchronous writes.
			printf("Error: dwBytesWritten != dwNoOfBytes\n");
		}
		else
		{
			_tprintf(TEXT("Wrote data to file %s successfully\n"), argv[1]);
		}
	}
	CloseHandle(hNewfile);
	return 0;
}