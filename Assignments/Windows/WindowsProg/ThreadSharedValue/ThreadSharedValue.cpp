#include "pch.h"
#include <iostream>
#include<windows.h>
#include<tchar.h>
#define SIZE 100
using namespace std;

DWORD WINAPI thread_1(LPVOID lpParam) {
//	_tprintf(TEXT("Running thread_1...\n"));
	(*(int *)lpParam)= (*(int *)lpParam)  +1;
	return 0;
}

int _tmain() {
	HANDLE hThread[SIZE];
	int shared_value = 0;
	DWORD dThreadId[SIZE];

	//Thread creation
	for (int i = 0;i < SIZE;i++) {
		hThread[i] = CreateThread(
			NULL,
			0,
			thread_1,
			&shared_value,
			0,
			&dThreadId[i]
		);
	}

	//wait until thread execution completes

 	WaitForMultipleObjects(SIZE, hThread, TRUE, INFINITE);

	wcout << shared_value << endl;

	for (int i = 0;i < SIZE;i++)
		CloseHandle(hThread[i]);
	return 0;
}
