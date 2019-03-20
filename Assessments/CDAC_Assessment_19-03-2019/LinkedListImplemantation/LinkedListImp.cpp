#include<iostream>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
}NODE;
class MyLinkedList {
	NODE *start;
public:
	MyLinkedList() {
		start = NULL;
	}
	void insertFirst(int);
	void insertAtPosition(int, int);
	void reverseList();
	void printForward();
	void printBackward();
	void deleteNodeWithValue(int);
};
void MyLinkedList::insertFirst(int value) {
	NODE *temp;
	temp = new NODE;
	temp->data = value;
	if (start == NULL) {
		start = temp;
		temp->next = NULL;
	}
	else {
		temp -> next = start;
		start = temp;
	}
}
void MyLinkedList::insertAtPosition(int value, int position) {
		NODE *temp;
		temp = new node;
		temp->data = value;

		if (position==1) {
			temp->next = start;
			start = temp;
		}
		else{
			NODE *curr;
			curr = start;
			int iter = 1;
			while (iter < position) {
				curr = curr->next;
				iter++;
			}
			temp->next = curr->next;
			curr->next = temp;
		}
		
	
}
void MyLinkedList::reverseList() {

	NODE *p, *q, *r=NULL;
	p = start;
	q = p->next;
	while (r!=NULL) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	start->next = NULL;
	start = p;

}
void MyLinkedList::printForward(){
	if (start == NULL)
		cout << "List is empty\n";
	else {
		NODE *nodeIter = start;
		while (nodeIter!= NULL) {
			cout << nodeIter->data << " ";
			nodeIter = nodeIter->next;
		}
	}
}

void printNode(NODE *curr) {
	if (curr->next == NULL)
		return;
	printNode(curr->next);
	cout << curr->data << " ";
}
void MyLinkedList::printBackward() {
	printNode(start);
}

void MyLinkedList::deleteNodeWithValue(int value) {
	NODE *curr, *temp;
	if (start != NULL) {
		if (start->data == value) {
			temp = start;
			start = temp->next;
			delete temp;
		}
		else {
			curr = start;
			while (curr->next != NULL && curr->next->data != value)
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

int main() {
	MyLinkedList tempList;

	char choice, proceed;
	do {
		cout << "Enter choice from menu\n1)InsertAtNthPosition\n2)ReverseList\n3)PrintElementsInForward\n4)PrintElementsInBackward\n5)DeleteNodeWithValue\n ";
		cin >> choice;
		switch (choice) {
		case '1':
			int value;
			cout << "Enter the value to be inserted : ";
			cin >> value;
			tempList.insertFirst(value);
			/*int value, pos;
			cout << "Enter the value , position to be inserted : ";
			cin >> value>>pos;
			tempList.insertAtPosition(value, pos);*/
			break;
		case '2':
			cout << "Reverse of the list : ";
			tempList.reverseList();
			break;
		case '3':
			cout << "Elements in forward : ";
			tempList.printForward();
			break;
		case '4':
			cout << "Elements in backward : ";
			tempList.printBackward();
			break;
		}

		cout << "Do you want to continue?(Y/N) :";
		cin >> proceed;
	} while (proceed == 'Y' || proceed == 'y');
	getchar();
	return 0;
}