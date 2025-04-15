#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	} // Node():data(0),next(NULL){}
};
class Stack {
public:
	Node* top = NULL;
	// Stack() :top(NULL){}
	bool isempty() {
		return (top == NULL);
	}
	void push(int val) { // = insert_first(int val)
		Node* newnode = new Node();
		newnode->data = val;

		if (isempty()) {
			newnode->next = NULL;
			top = newnode;
		}
		else {
			newnode->next = top;
			top = newnode;
		}
	}
	void pop() {  // Delete_first()
	 
		if (isempty()) {
			cout << "Stack is already empty.\n";
		}
		else {
			Node* delptr = top;
			
			cout << "The popped element is :" << delptr->data << endl;
			top = top->next;
			delete delptr;
			
		}
	}
	void display() { // treversing.
		Node* temp = top; 
		if (isempty())
			cout << "Stack list is empty\n";
		else {
			while (temp != NULL) {
				cout << temp->data << "\n";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	int peak() {
		if (isempty()) {
			cout << "Stack underflow.\n";
			return -1;
		}
		else {
			return top->data;
		}
	}
};
int main() {
	cout << "Hello with Stack ^_^\n\n";

	Stack s;
	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
	s.display();

	s.pop();
	s.pop();
	s.display();

	s.pop();
	s.pop();
	s.display();
	s.pop();
}

