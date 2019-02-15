#include<iostream>
using namespace std;
class Complex {
	int real, imag;
public:
	Complex() {
		real = 0;
		imag = 0;
	}
	Complex(int val) {
		real = val;
		imag = val;
	}
	Complex(int r, int i) {
		real = r;
		imag = i;
	}
	void display_complex() {
		cout << "real :" << real << "\timag :" << imag << endl;
	}
	friend Complex addComplex(Complex, Complex);
	friend Complex mulComplex(Complex, Complex);

};
Complex addComplex(Complex C1, Complex C2) {
	Complex tmp;
	tmp.real = C1.real + C2.real;
	tmp.imag = C1.imag + C2.imag;
	return(tmp);

}
Complex mulComplex(Complex C1, Complex C2) {
	Complex tmp;
	tmp.real = C1.real*C2.real + C1.imag * C2.imag;
	tmp.imag = C1.real*C2.imag + C1.imag * C2.real;
	return(tmp);

}
int main() {
	Complex C1(1, 2), C2(2, 3), C3,C4;
	C3 = addComplex(C1, C2);
	C3.display_complex();
	C4 = mulComplex(C1, C2);
	C4.display_complex();
	getchar();
}