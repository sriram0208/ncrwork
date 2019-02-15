#include<iostream>
using namespace std;
class Time {
	int hr, min, sec;
public :
	Time() {
		hr = 0;
		min = 0;
		sec = 0;
	}
	Time(int h, int m, int s) {
		hr = h;
		min = m;
		sec = s;
	}
	void display_time() {
		cout << hr << ":" << min << ":" << sec << endl;
	}
	void add(Time t1, Time t2) {
		hr = t1.hr + t2.hr;
		min = t1.min + t2.min;
		sec = t1.sec + t2.sec;
	}
};
int main() {
	Time T1(12, 30, 45), T2(11, 20, 45), T3;
	T3.add(T1, T2);
	T3.display_time();
	getchar();
	return 0;
}