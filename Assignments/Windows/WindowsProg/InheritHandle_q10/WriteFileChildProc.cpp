#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>
#include<stdio.h>
int _tmain(int argc, TCHAR *argv[]) {

	HANDLE nFile = (HANDLE)*argv[0];
	char Buffer[] = "Hello! This is sriram!!";
	DWORD dwNoOfBytes = (DWORD)strlen(Buffer);
	DWORD dwBytesWritten;
	BOOL bErrorReport;

	_tprintf(TEXT("Writing data to file\n"));

	bErrorReport = WriteFile(					//Writing to file
		nFile,
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
			_tprintf(TEXT("Wrote data to file successfully\n"));
		}
	}
	return 0;
}