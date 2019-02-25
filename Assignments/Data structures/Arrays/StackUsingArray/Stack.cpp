#include<iostream>
#define MAX 100
using namespace std;

class Stack {
	int top, a[MAX];
public :
	Stack() {
		top = -1;
	}
	bool push(int);
	int pop();
	bool isEmpty();
	void display();
};
bool Stack::push(int x) {
	if (top == MAX - 1) {
		cout << "Stack overflow\n";
		return 0;
	}
	else {
		a[++top] = x;
		return 1;
	}
}
int Stack::pop() {
	if (top == -1) {
		cout << "Stack underflow\n";
		return 0;
	}
	else {
		return a[top--];
	}
}
bool Stack::isEmpty() {
	if (top == -1)
		return 1;
	else
		return 0;
}
void Stack::display() {
	if (top == -1)
		cout << "Stack empty\n";
	else {
		cout << "Stack elements are : ";
		for (int i = 0;i <= top;i++)
			cout << a[i] << " ";
		cout << "\n";
	}
}
int main() {
	Stack S;
	char choice;
	cout << "Enter your choice :\n";
	cout << "1)push\n2)pop\n3)checkStackEmpty\n4)displayStack\n0)Exit\n";
	cin >> choice;
	while (choice != '0'){
		switch (choice) {
		case '1':
			int x;
			cout << "Enter the number to be pushed : ";
			cin >> x;
			if (S.push(x))
				cout << "Pushed element successfully\n";
			else
				cout << "Push unsuccesfull\n";
			break;
		case '2':
			x = S.pop();
			if (x == 0)
				cout << "Pop unsuccesfull\n";
			else
				cout << "Popped element : " << x << "\n";
			break;
		case '3':
			if (S.isEmpty())
				cout << "Stack is empty\n";
			else
				cout << "Stack is not empty\n";
			break;
		case '4':
			S.display();
			break;
		}
		cout << "Enter your choice :\n";
		cout << "1)push\n2)pop\n3)checkStackEmpty\n4)displayStack\n0)Exit\n";
		cin >> choice;
	}
	getchar();
}