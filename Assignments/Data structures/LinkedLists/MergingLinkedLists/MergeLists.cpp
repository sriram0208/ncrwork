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
	char choice;
	int val;

	cout << "Enter choice :\n\n";
	cout << "1)InsertToList1\t\t2)InsertToList2\n3)DeleteFromList1\t4)DeleteFromList2\n5)SortList1\t\t6)SortList2\n7)DisplayList1\t\t8)DisplayList2\n9)mergeLists : ";
	cin >> choice;
	while (choice >= '1'&&choice <= '9') {
		switch (choice) {
		case '1':cout << "Enter value to be inserted to list1 :";
			cin >> val;
			l1.insertElement(val);
			break;
		case '2':cout << "Enter value to be inserted to list2:";
			cin >> val;
			l2.insertElement(val);
			break;
		case '3':cout << "Enter value to be deleted from list1:";
			cin >> val;
			l1.deleteElement(val);
			break;
		case '4':cout << "Enter value to be deleted from list2:";
			cin >> val;
			l2.deleteElement(val);
			break;
		case '5':l1.sort();
			break;
		case '6':l2.sort();
			break;
		case '7':l1.display();
			break;
		case '8':l2.display();
			break;
		case '9':l3 = mergeLL(l1, l2);
			cout << "Merged Lists : ";
			l3.display();
			break;
		}
		cout << "Enter choice :\n\n";
		cout << "1)InsertToList1\t\t2)InsertToList2\n3)DeleteFromList1\t\t4)DeleteFromList2\n5)SortList1\t\t6)SortList2\n7)DisplayList1\t\t8)DisplayList2\n9)mergeLists : ";
		cin >> choice;
	}
	getchar();
	return 0;
}