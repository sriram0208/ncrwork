#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *next;
};
class Stack {
	struct node *top;
public:
	Stack() {
		top = NULL;
	}
	void push(int);
	void pop();
	void printStack();
	~Stack() {
		while (top != NULL) {
			struct node *temp;
			temp = top;
			top = top->next;
			delete temp;
		}
	}
};
void Stack::push(int ele) {
	struct node *temp;
	temp = new node;
	temp->data = ele;
	if (top == NULL) {
		top = temp;
		temp->next = NULL;
	}
	else {
		temp->next = top;
		top = temp;
	}
}
void Stack::pop() {
	if (top == NULL)
		cout << "Stack underflow" << endl;
	else {
		struct node *temp;
		temp = top;
		top = top->next;
		int x = temp->data;
		delete temp;
		cout << "Popped element is :" << x << endl;
	}
}
void Stack::printStack() {
	if (top == NULL)
		cout << "Stack is empty" << endl;
	else {
		struct node *curr = top;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
}
int main() {
	Stack S;
	S.push(2);
	S.push(4);
	S.push(6);
	S.printStack();

	S.pop();
	S.pop();
	S.printStack();

	S.~Stack();
	S.printStack();
	getchar();
	getchar();

	return 0;
}