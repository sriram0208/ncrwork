#include<iostream>
using namespace std;
struct node {
	int coeff;
	int power;
	struct node *next;
};
class Poly{
	struct node *list;
public:
	Poly() {
		list = NULL;
	}
	void insert() {

	}
};