#include<iostream>
using namespace std;
class Point {
	int x, y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	friend int distance(Point, Point);
};
int distance(Point P1, Point P2) {
	float dis;
	dis = sqrt(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y), 2));
	return dis;
}
int main() {
	Point P1(2, 8), P2(1, 5);
	int dis = distance(P1, P2);
	cout << "Distance between points : " << dis << endl;
	getchar();
}
