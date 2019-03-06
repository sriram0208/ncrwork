#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>
DWORD WINAPI myThreadFunction(LPVOID lParam) {
	for (int num = 1;num <= 100;num++)
		printf("%d ", num);
	return 0;
}
int _tmain() {
	HANDLE hThread;
	int arg;
	DWORD dThreadId;

	hThread = CreateThread(
		NULL,
		0,
		myThreadFunction,
		&arg,
		CREATE_SUSPENDED,
		&dThreadId
	);

	Sleep(5000);
	ResumeThread(hThread);
	WaitForSingleObject(hThread,1000);
	return 0;
}