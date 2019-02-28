#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *next;
};
class SingleLL {
	struct node *start;
public:
	SingleLL() {
		start = NULL;
	}
	void insertFirst(int);
	void insertLast(int);
	void insertAfter(int, int);
	void insertBefore(int, int);
	int deleteFirst();
	int deleteLast();
	void deleteSpec(int);
	void travelForward();
	void travelBackward();
	void reverse();
	~SingleLL() {
		struct node *temp;
		while (start != NULL) {
			temp = start;
			start = temp->next;
			delete temp;
		}
	}
	friend void print(struct node *);
};

void SingleLL::insertFirst(int ele) {
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void SingleLL::insertLast(int ele) {
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	struct node *curr = start;
	if (curr == NULL)
		start = temp;
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}

void SingleLL::insertAfter(int sele, int ele) {
	if (start != NULL) {
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "element not found\n";
	}
	else
		cout << "list empty\n";
}
void SingleLL::insertBefore(int sele, int ele) {
	if (start != NULL) {
		struct node *temp;
		temp = new node;
		temp->data = ele;

		if (start->data == sele) {
			temp->next = start;
			start = temp;
		}
		struct node *curr;
		curr = start;
		while (curr->next != NULL && curr->next->data != sele)
			curr = curr->next;
		if (curr->next != NULL) {
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "element not found\n";
	}
	else
		cout << "list empty\n";
}
int SingleLL::deleteFirst() {
	int x = -999;
	if (start != NULL) {
		struct node *temp;
		temp = start;
		start = temp->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "list empty\n";
	return x;
}
int SingleLL::deleteLast() {
	int x = -999;
	if (start != NULL) {
		if (start->next == NULL) {
			x = start->data;
			delete start;
			start = NULL;
		}
		else {
			struct node *curr;
			curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}
	}
	else
		cout << "list empty\n";
	return x;
}
void SingleLL::deleteSpec(int ele) {
	struct node *curr, *temp;
	if (start != NULL) {
		if (start->data == ele) {
			temp = start;
			start = temp->next;
			delete temp;
		}
		else {
			curr = start;
			while (curr->next != NULL && curr->next->data != ele)
				curr = curr->next;
			if (curr->next != NULL) {
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "element not found\n";
		}
	}
	else
		cout << "list empty\n";
}
void SingleLL::travelForward() {
	struct node *curr = start;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << "\n";
}
void print(struct node *curr) {
	if (curr != NULL)
	{
		print(curr->next);
		cout << curr->data << " ";
	}
}
void SingleLL::travelBackward() {
	if (start != NULL) {
		print(start);
		cout << "\n";
	}
}
void SingleLL::reverse() {
	if (start != NULL) {
		if (start->next != NULL) {
			struct node *p, *q, *r;
			p = start;
			q = p->next;
			while (q != NULL) {
				r = q->next;
				q->next = p;
				q = r;
				p = q;
			}
			start->next = NULL;
			start = p;
		}
	}
}

int main() {
	SingleLL Sll;
	char choice;
	int val,pos;
	cout << "Enter choice  :\n\n";
	cout <<"1)insertFirst\t\t2)insertLast\n3)insertAfter\t\t4)insertBefore\n5)deleteFirst\t\t6)deleteLast\n7)deleteSpec\t\t8)travelForward\n9)travelBackward\t10)reverse : ";
	cin >> choice;
	while (choice >= '1' && choice <= '10') {
		switch (choice) {
		case '1':cout << "Enter value to be inserted :";
			cin >> val;
			Sll.insertFirst(val);
			break;
		case '2':cout << "Enter value to be inserted :";
			cin >> val;
			Sll.insertLast(val);
			break;
		case '3':cout << "Enter position , value to be inserted :";
			cin >> pos >> val;
			Sll.insertAfter(pos, val);
			break;
		case '4':cout << "Enter position , value to be inserted :";
			cin >> pos >> val;
			Sll.insertBefore(pos, val);
			break;
		case '5':cout << "Enter value to be deleted :";
			cin >> val;
			Sll.deleteFirst();
			break;
		case '6':cout << "Enter value to be deleted :";
			cin >> val;
			Sll.deleteLast();
			break;
		case '7':cout << "Enter value to be deleted :";
			cin >> val;
			Sll.deleteSpec(val);
			break;
		case '8':
			cout << "Forward list : ";
			Sll.travelForward();
			break;
		case '9':
			cout << "Backward list : ";
			Sll.travelBackward();
		case '10':
			cout << "Reverse list : ";
			Sll.reverse();
			break;
		}
		cout << "Enter choice  :\n\n";
		cout << "1)insertFirst\t\t2)insertLast\n3)insertAfter\t\t4)insertBefore\n5)deleteFirst\t\t6)deleteLast\n7)deleteSpec\t\t8)travelForward\n9)travelBackward\t10)reverse : ";
		cin >> choice;
	}
	getchar();
	return 0;
}

