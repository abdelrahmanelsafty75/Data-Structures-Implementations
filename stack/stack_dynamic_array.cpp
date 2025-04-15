#include <iostream>
using namespace std;

class Stack {
private:
	int top, length;
	int* stack;
public:
	Stack(int size) {
		stack = new int[size];
		length = size;
		top = -1;
	}
	bool isempty() {
		return(top == - 1);
	}
	bool isfull() {
		return(top == length - 1);
	}
	void push(int val) {
		if (isfull())
			cout << "Stack overflow ! \n";
		else {
			stack[++top] = val;
		}
	}
	void pop() {
		if (isempty())
			cout << "Stack is empty! \n";
		else
			top--;
	}
	void display() {
		if (isempty())
			cout << "Stack is already empty! \n";
		else {
			for (int i = top; i >= 0; i--)
				cout << stack[i] << "\t";
		}
	}
};

int main() {
	cout << "Hello Nigga let's practice: ^_^ \n\n";


	int n;
	cout << "Enter Stack Size: ";
    cin >> n;

	Stack s(n);

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	s.push(60);

	cout << "\n Content: \n";
	s.display();

	s.pop();
	s.pop();

	cout << "\n Content: \n";
	s.display();

	return 0;
}

