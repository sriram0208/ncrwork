#include<iostream>
using namespace std;
class Complex {
	int real;
	int imag;
public:
	Complex() {
		real = 0;
		imag = 0;
	}
	Complex(int r) {
		real = r;
		imag = 0;
	}
	Complex(int r, int i) {
		real = r;
		imag = i;
	}
	Complex(Complex &C) {
		real = C.real;
		imag = C.imag;
	}
	~Complex() {
	}

	void display_complex() {
		cout << "real :" << real << " imag :" << imag << "\n";
	}
	Complex operator+(Complex C) {
		real = real + C.real;
		imag = imag + C.imag;
		return (*this);
	}
	Complex operator-(Complex C) {
		real = real - C.real;
		imag = imag - C.imag;
		return (*this);
	}
	Complex operator*(Complex C) {
		real = real * C.real + imag * C.imag;
		imag = real * C.imag + imag * C.real;
		return (*this);
	}
	Complex operator-() {
		real = -real;
		imag = -imag;
		return(*this);
	}

	Complex operator++() {
		++real;
		++imag;
		return (*this);
	}

	Complex operator++(int x) {
		Complex temp;
		temp.real = real++;
		temp.imag = imag++;
		return temp;
	}
	Complex operator+=(Complex C) {
		real = real + C.real;
		imag = imag + C.imag;
		return (*this);
	}
	Complex operator,(Complex C) {
		return C;
	}
	Complex* operator->() {
		return this;
	}

	friend ostream& operator<<(ostream&, Complex);
};

ostream& operator<<(ostream &cout, Complex C) {
	if (C.imag > 0)
		cout << C.real << "+" << C.imag << "i\n";
	else
		cout << C.real << C.imag << "i\n";
	return cout;
}



void main() {
	Complex C1(8, 3), C2(5), C3(C1), C4, C5;
	C4 = C1 + C2;
	cout << "Sum :" << C4;

	C4 = C1 - C2;
	cout << "Diff :" << C4;

	C4 = C1 * C2;
	cout << "Mul :" << C4;

	C4 = -C1;
	cout << "unary minus :" << C4;

	C4 = ++C1;
	cout << "pre-increment :" << C4;

	C4 = C1++;
	cout << "post-increment :" << C4;

	C3 += C2;

	C4 = (C1, C2, C3);
	cout << "comma :" << C4;

	C5 = C1, C2, C3;
	cout << C5;

	C5->display_complex();

	getchar();
}