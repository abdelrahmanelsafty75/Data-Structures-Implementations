//#include <iostream>
//using namespace std;
//#define size 5
//
//int queue[size];
//int front = -1, rear = -1;
//
//bool isEmpty() {
//    return((front == -1 and rear == -1) || front > rear);
//}
//bool isFull() {
//    return(rear == size - 1);
//}
//void enqueue(int val) {
//    if (isFull())
//        cout << "Queue is already full.\n";
//    else {
//        if (isEmpty()) {
//            front++;
//            queue[++rear] = val;
//        }
//        else {
//            queue[++rear] = val;
//        }
//    }
//}
//void dequeue() {
//    if (isEmpty())
//        cout << "Queue is already empty.\n";
//    else {
//        front++;
//    }
//}
//int peak() {
//    if (isEmpty()) {
//        cout << "Queue is already empty.\n";
//        return -1;
//    }
//    else {
//        return queue[front];
//    }
//}
//void display() {
//    if (isEmpty()) 
//        cout << "Queue is already empty.\n";
//    else {
//        for (int i = front; i <= rear; i++) {
//            cout << queue[i] << " ";
//        }
//        cout << endl;
//    }
//}
//int main(){
//    cout << "Hello with queue ^_^ : \n\n";
//
//    enqueue(5);
//    enqueue(10);
//    enqueue(25);
//    display();
//    dequeue();
//    cout << "peak: " << peak();
//    return 0;
//}
/*================================ Dynamic Array =======================================================*/
#include <iostream>
using namespace std;

class Queue {
public:
	int front, rear, len;
	int* queue;

    Queue(int size) {
		queue = new int[size];
		front = -1;
		rear = -1;
		len = size;
	}
	bool isempty() {
		return (front == -1 or front > rear);
	}
	bool isfull() {
		return (rear == len - 1);
	}

	void enqueue(int val) {
		if (isfull())
			cout << "Queue is full\n";
		else if (isempty()) {
			front++;
			queue[++rear] = val;
		}
		else
			queue[++rear] = val;
	}
	void dequeue() {
		if (isempty())
			cout << "Queue is already empty\n";
		else
			front++;
	}
	void peak() {
		cout << "peak: " << queue[front] << endl;
	}
	void display() {
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
	cout << "Hello Nigga let's practice: ^_^ \n\n";


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


