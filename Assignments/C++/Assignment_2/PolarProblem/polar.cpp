#include<iostream>
using namespace std;

class Polar {
	float angle, radius;
	static int count;
public:
	Polar() {
		angle = 0;
		radius = 0;
		count++;
	}
	Polar(float a, float r) {
		angle = a;
		radius = r;
		count++;
	}
	void show_count() {
		cout << "count :" << count << endl;
	}
	void display() {
		cout << "angle :" << angle << "\tradius :" << radius << endl;
	}
};
int Polar::count = 0;
void main() {
	Polar P1(60, 5);
	P1.show_count();
	P1.display();

	Polar P2(30, 2);
	P2.show_count();
	P2.display();

	getchar();
}