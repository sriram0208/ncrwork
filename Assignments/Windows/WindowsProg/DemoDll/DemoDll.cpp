#include "pch.h"
#include <iostream>
#include "HeaderDll.h"

int main() {
	printf("Demo for DLL\n");
	helloWorld();
	printf("%d\n", add(2,3));
	return 0;
}