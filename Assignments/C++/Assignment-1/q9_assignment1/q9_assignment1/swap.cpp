#include<iostream>
using namespace std;
void swap_value(int x, int y) {
	int temp;
	temp = x, x = y;
	y = temp;
}
void swap_reference(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}
int main() {
	int a=2, b=5;
	char choice;
	cout << "Before swap :" << a << "\t" << b<<endl;
	cout << "1)Call by value\n2)Call by reference\nEnter your choice :" << endl;
	cin >> choice;
	getchar();
	switch (choice) {
	case '1':swap_value(a, b);
		break;
	case '2':swap_reference(a, b);
		break;
	}
	cout << "After swap :" << a << "\t" << b;
	getchar();
}