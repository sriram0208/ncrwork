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
	friend List mergeLL(List, List);
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
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << "\n";
}
void List::sort() {
	struct node *c1, *c2, *min;
	int temp;
	if (start != NULL && start->next != NULL) {
		c1 = start;
		while (c1->next != NULL) {
			min = c1;
			c2 = c1->next;
			while (c2 != NULL) {
				if (c2->data < min->data)
					min = c2;
				c2 = c2->next;
			}
			if (min != c1) {
				temp = c1->data;
				c1->data = min->data;
				min->data = temp;
			}
			c1 = c1->next;
		}
	}
}
List mergeLL(List l1, List l2) {
	struct node *c1, *c2;
	List l3;
	c1 = l1.start;
	c2 = l2.start;
	while (c1 != NULL && c2 != NULL) {
		if (c1->data < c2->data) {
			l3.insertElement(c1->data);
			c1 = c1->next;
		}
		else if (c1->data > c2->data) {
			l3.insertElement(c2->data);
			c2 = c2->next;
		}
		else {
			l3.insertElement(c1->data);
			l3.insertElement(c2->data);
			c1 = c1->next;
			c2 = c2->next;
		}
	}
	while (c1 != NULL) {
		l3.insertElement(c1->data);
		c1 = c1->next;
	}
	while (c2 != NULL) {
		l3.insertElement(c2->data);
		c2 = c2->next;
	}
	return l3;
}
int main() {
	List l1, l2, l3;
	int arr1[] = { 6,2,7,4,6,15,9,23,33,21 };
	int arr2[] = { 3,45,67,11,7,9,1,23,43,56 };
	for (int i = 0;i < 10;i++) {
		l1.insertElement(arr1[i]);
		l2.insertElement(arr2[i]);
	}
	l1.display();
	l2.display();
	l1.sort();
	l2.sort();
	cout << "sorted lists\n";
	l1.display();
	l2.display();
	l3 = mergeLL(l1, l2);
	cout << "merged list\n";
	l3.display();
	getchar();
	return 0;
}