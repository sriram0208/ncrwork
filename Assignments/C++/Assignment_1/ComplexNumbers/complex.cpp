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

	int real1, imag1, real2, imag2;
	char choice, proceed;
	do {
		cout << "Enter the first complex number" << endl;
		cout << "\nReal part : ";
		cin >> real1;
		cout << "\nImag part : ";
		cin >> imag1;
		cout << "Enter the second complex number" << endl;
		cout << "\nReal part : ";
		cin >> real2;
		cout << "\nImag part : ";
		cin >> imag2;

		Complex firstComplexNum(real1, imag1), secondComplexNum(real2, imag2), res;
		firstComplexNum.display_complex();
		secondComplexNum.display_complex();
		cout << "Choose the operation to be performed\n1)addition\t2)multiplication\n";
		cin >> choice;
		switch (choice) {
		case '1':res = addComplex(firstComplexNum, secondComplexNum);
			break;
		case '2':res = mulComplex(firstComplexNum, secondComplexNum);
			break;
		}
		res.display_complex();

		cout << "Do you want to proceed?(Y/N) : ";
		cin >> proceed;
	} while (proceed == 'Y' || proceed == 'y');
	getchar();
}