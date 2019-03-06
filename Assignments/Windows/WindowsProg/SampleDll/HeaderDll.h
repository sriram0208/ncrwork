#pragma once

#ifdef EXPORTING_DLL
	#define DLLExport extern __declspec(dllexport)
#else
	#define DllImport extern __declspec(dllimport)
#endif

DLLExport void helloWorld();
DLLImport int add(int, int);