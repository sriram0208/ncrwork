#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *next;
};
class Queue {
	struct node *front, *rear;
public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	void insert(int);
	void remove();
	void printQueue();
	~Queue() {
		while (front != NULL) {
			struct node *temp = front;
			front = front->next;
			delete temp;
		}
		rear = NULL;
	}

};
void Queue::insert(int ele) {
	struct node *temp;
	temp = new node;
	temp->data = ele;
	if (front == NULL) {
		front = temp;
		rear = temp;
		temp->next = NULL;
	}
	else {
		rear->next = temp;
		temp->next = NULL;
		rear = temp;
	}
}
void Queue::remove(){
	if (front == NULL)
		cout << "Queue underflow" << endl;
	else {
		int x;
		if (front == rear) {
			x = front->data;
			delete front;
			front = NULL;
			rear = NULL;
		}
		else {
			struct node *temp;
			temp = new node;
			temp = front;
			cout << "Removed element is :" << temp->data << endl;
			front = front->next;
			delete temp;
		}
	}
}
void Queue::printQueue() {
	if (front == NULL)
		cout <<"Queue is empty";
	else {
		struct node *curr = front;
		while (curr != NULL) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	cout << endl;
}

int main() {
	Queue Q;
	Q.insert(3);
	Q.insert(5);
	Q.insert(6);
	Q.printQueue();
	Q.remove();
	Q.remove();
	Q.printQueue();
	Q.~Queue();
	Q.printQueue();
	getchar();
	return 0;
}