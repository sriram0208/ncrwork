#include<iostream>
using namespace std;

inline int add(int a, int b) {
	return a + b;
}
inline int sub(int a, int b) {
	return a - b;
}
inline int mul(int a, int b) {
	return a * b;
}
inline int divi(int a, int b) {
	return a / b;
}
inline int mod(int a, int b) {
	return a % b;
}
int main() {
	int a = 3, b = 5, res;
	res = add(a, b);
	cout << "sum : " << res << "\t";
	res = sub(a, b);
	cout << "difference : " << res << "\t";
	res = mul(a, b);
	cout << "mul : " << res << "\t";
	res = divi(a, b);
	cout << "div : " << res << "\t";
	res = mod(a, b);
	cout << "mod : " << res << "\t";
	getchar();
}