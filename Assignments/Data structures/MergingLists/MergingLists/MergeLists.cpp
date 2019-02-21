#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *next;
};
class List {
	struct node *start;
public:
	List() {
		start = NULL;
	}
	void insertElement(int);
	void deleteElement(int);
	void sort();
	void display();
};
void List::insertElement(int ele) {
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
void List::deleteElement(int ele) {
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
void List::display() {
	struct node *curr = start;
	while (curr != NULL) {
		cout << curr->data << "\t";
		curr = curr->next;
	}
	cout << "\n";
}
void List::sort() {
	struct node *c1, *c2;
	c1 = start;
	if()
	while (c1 != NULL) {
		min = c1->data;
	}
}