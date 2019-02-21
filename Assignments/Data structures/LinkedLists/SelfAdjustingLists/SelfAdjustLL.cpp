#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *next;
};
class SelfAdjustLL {
	struct node *start;
public:
	SelfAdjustLL() {
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
	bool searchElement(int);
	void selfAdjust(int);
	~SelfAdjustLL() {
		struct node *temp;
		while (start != NULL) {
			temp = start;
			start = temp->next;
			delete temp;
		}
	}
	friend void print(struct node *);
};

void SelfAdjustLL::insertFirst(int ele) {
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void SelfAdjustLL::insertLast(int ele) {
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

void SelfAdjustLL::insertAfter(int sele, int ele) {
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
void SelfAdjustLL::insertBefore(int sele, int ele) {
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
int SelfAdjustLL::deleteFirst() {
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
int SelfAdjustLL::deleteLast() {
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
void SelfAdjustLL::deleteSpec(int ele) {
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
void SelfAdjustLL::travelForward() {
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
void SelfAdjustLL::travelBackward() {
	if (start != NULL) {
		print(start);
		cout << "\n";
	}
}
void SelfAdjustLL::reverse() {
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
bool SelfAdjustLL::searchElement(int ele) {
	struct node *p;
	p = start;
	while (p != NULL) {
		if (p->data == ele) {
			this->selfAdjust(ele);
			return true;
		}
		p = p->next;
	}
	return false;
}

void SelfAdjustLL::selfAdjust(int ele) {
	this->deleteSpec(ele);
	this->insertFirst(ele);
}
int main() {
	SelfAdjustLL l1;
	int arr[] = { 1,3,2,5,8,4,6,4,9,7 };
	for (int i = 0;i < 10;i++)
		l1.insertLast(arr[i]);
	l1.travelForward();
	l1.searchElement(4);
	l1.travelForward();
	getchar();
	return 0;
}

