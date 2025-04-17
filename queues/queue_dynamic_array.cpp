#include <iostream>
using namespace std;

class Queue {
public:
	int front, rear, len;
	int* queue;

    Queue(int size) { // Constructor to set initial values
		queue = new int[size];
		front = -1;
		rear = -1;
		len = size;
	}
	bool isempty() {  // check if queue is empty
		return (front == -1 or front > rear);
	}
	bool isfull() {  // check if queue is full
		return (rear == len - 1);
	}

	void enqueue(int val) { // adding item
		if (isfull())
			cout << "Queue is full\n";
		else if (isempty()) {
			front++;
			queue[++rear] = val;
		}
		else
			queue[++rear] = val;
	}
	void dequeue() {  // deleting item
		if (isempty())
			cout << "Queue is already empty\n";
		else
			front++;
	}
	void peak() {  // return the first item
		cout << "peak: " << queue[front] << endl;
	}
	void display() {  // display all items
		if (isempty())
			cout << "Queue is already empty\n";
		else {
			for (int i = front; i <= rear; i++) {
				cout << queue[i] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	cout << "Hello, let's practice: ^_^ \n\n";


	Queue q(3);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);

	q.display();

	q.dequeue();

	q.display();

	q.dequeue();
	q.dequeue();

	q.display();

	return 0;
}


