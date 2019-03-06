
#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>
using namespace std;
DWORD WINAPI MythreadFunction(LPVOID lpParam) {
	_tprintf(TEXT("Running thread...\n"));
	Sleep(10000);
	return 0;
}
int _tmain() {
	HANDLE hThread;
	int arg;
	DWORD dThreadId;
	DWORD dExitCode;
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

	WaitForSingleObject(hThread, 5000);
	TerminateThread(hThread, 1);
	Sleep(10);
	GetExitCodeThread(hThread, &dExitCode);

	if (dExitCode == STILL_ACTIVE)
		cout << "Thread still active" <<dExitCode<< endl;
	else
		cout << "Thread exited with exit code" << dExitCode << endl;

	return 0;
}
