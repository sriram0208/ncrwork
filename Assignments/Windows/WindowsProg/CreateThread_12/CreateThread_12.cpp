#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>
DWORD WINAPI MythreadFunction(LPVOID lpParam) {
	_tprintf(TEXT("Running thread"));
	return 0;
}
int _tmain() {
	HANDLE hThread;
	int arg;
	DWORD dThreadId;

	//Thread creation

	hThread = CreateThread(
		NULL,
		0,
		MythreadFunction,
		&arg,
		0,
		&dThreadId
	);

	//wait until thread execution completes

	WaitForSingleObject(hThread, 1000);
	return 0;
}
