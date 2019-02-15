#include<iostream>
#define FeetToMetre 0.3048
#define InchToCenti 2.54
#define MetreToFeet 3.28084
#define CentiToInch 0.3937008

using namespace std;

class Distance2;
class Distance1 {
	int metres, centi;
public:
	Distance1() {
		metres = 0;
		centi = 0;
	}
	Distance1(int m, int c) {
		metres = m;
		centi = c;
	}
	friend void addDistancesInMetres(Distance1, Distance2);
	friend void addDistancesInFeet(Distance1, Distance2);
};
class Distance2 {
	int feet, inch;
public:
	Distance2() {
		feet = 0;
		inch = 0;
	}
	Distance2(int f, int i) {
		feet = f;
		inch = i;
	}
	friend void addDistancesInMetres(Distance1, Distance2);
	friend void addDistancesInFeet(Distance1, Distance2);
};
void addDistancesInMetres(Distance1 D1,Distance2 D2) {
	Distance1 temp;
	temp.metres = D1.metres + D2.feet * FeetToMetre;
	temp.centi = D1.centi + D2.inch*InchToCenti;

	cout << "Total distance\t:" << temp.metres << "metres " << temp.centi << "centimetres"<<endl;
}

void addDistancesInFeet(Distance1 D1, Distance2 D2) {
	Distance2 temp;
	temp.feet = D2.feet + D1.metres * MetreToFeet;
	temp.inch = D2.inch + D1.centi*CentiToInch;

	cout << "Total distance\t:" << temp.feet << "feet " << temp.inch << "inches" << endl;
}

int main() {
	Distance1 D1(2, 5);
	Distance2 D2(3, 5);
	addDistancesInMetres(D1, D2);
	addDistancesInFeet(D1, D2);
	getchar();
}