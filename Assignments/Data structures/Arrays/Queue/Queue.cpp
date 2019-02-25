#include<iostream>
#define MAX 100
using namespace std;

class Queue {
	int a[MAX], front, rear;
public:
	Queue() {
		front = -1;
		rear = -1;
	}
	bool insert(int);
	void remove();
	void display();
	bool isEmpty();
};
bool Queue::insert(int x) {
	if (rear == MAX - 1)
	{
		cout << "Queue is full , unable to insert\n";
		return 0;
	}
	else {
		if (front == -1) {
			front = 0;
			rear = 0;
			a[front] = x;
		}
		else {
			a[++rear] = x;
		}
		return 1;
	}
}
void Queue::remove() {
	if (front == -1)
		cout << "Queue is empty\n";
	else {
		if (front == rear) {
			cout << "removed element is : " << a[front] << "\n";
			front = -1;
			rear = -1;
		}
		else {
			cout << "removed element is : " << a[front] << "\n";
			front++;
		}
	}
}
void Queue::display() {
	if (front == -1)
		cout << "Queue is empty\n";
	else {
		cout << "Queue elements are : ";
		for (int i = front;i <= rear;i++)
			cout << a[i] << " ";
		cout << "\n";
	}
}
bool Queue::isEmpty() {
	if (front == -1)
		return 1;
	else
		return 0;
}

int main() {
	Queue Q;
	char choice;
	cout << "Enter your choice :\n";
	cout << "1)insert\n2)remove\n3)checkQueueEmpty\n4)displayQueue\n0)Exit\n";
	cin >> choice;
	while (choice != '0') {
		switch (choice) {
		case '1':
			int x;
			cout << "Enter the number to be inserted : ";
			cin >> x;
			if (Q.insert(x))
				cout << "inserted element successfully\n";
			else
				cout << "insert unsuccesfull\n";
			break;
		case '2':
			Q.remove();
			break;
		case '3':
			if (Q.isEmpty())
				cout << "Queue is empty\n";
			else
				cout << "Queue is not empty\n";
			break;
		case '4':
			Q.display();
			break;
		}
		cout << "Enter your choice :\n";
		cout << "1)insert\n2)remove\n3)checkQueueEmpty\n4)displayQueue\n0)Exit\n";
		cin >> choice;
	}
	getchar();
}