#include<iostream>
using namespace std;
struct node {
	int coeff;
	int power;
	struct node *next;
};
class Poly {
	struct node *list;
public:
	Poly() {
		list = NULL;
	}
	void insert(int, int);
	void display();
	friend Poly addPoly(Poly, Poly);
};
void Poly::insert(int coeff, int power) {
	struct node *temp;
	temp = new node;
	temp->coeff = coeff;
	temp->power = power;
	temp->next = NULL;
	if (list == NULL)
		list = temp;
	else {
		struct node *curr;
		curr = list;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}

}
void Poly::display() {
	if (list == NULL)
		cout << "List empty\n";
	else {
		struct node *curr = list;
		while (curr != NULL) {
			cout << curr->coeff << "X" << curr->power << " ";
			curr = curr->next;
		}
		cout << "\n";
	}
}
Poly addPoly(Poly P1, Poly P2) {
	Poly P;
	struct node *C1 = P1.list;
	struct node *C2 = P2.list;

	struct node *C3 = P.list;
	while (C1 != NULL && C2 != NULL) {
		if (C1->power > C2->power) {
			P.insert(C1->coeff, C1->power);
			C1 = C1->next;
		}
		else if (C1->power < C2->power) {
			P.insert(C2->coeff, C2->power);
			C2 = C2->next;
		}
		else {
			P.insert(C1->coeff + C2->coeff, C1->power);
			C1 = C1->next;
			C2 = C2->next;
		}
	}
	while (C1 != NULL) {
		P.insert(C1->coeff, C1->power);
		C1 = C1->next;
	}
	while (C2 != NULL) {
		P.insert(C2->coeff, C2->power);
		C2 = C2->next;
	}
	return P;
}
int main() {
	Poly P1;
	P1.insert(5, 2);
	P1.insert(4, 1);
	P1.insert(-1, 0);
	P1.display();

	Poly P2;
	P2.insert(4, 2);
	P2.insert(3, 1);
	P2.insert(-1, 3);
	P2.display();

	Poly P;
	P = addPoly(P1, P2);
	P.display();
	getchar();
}