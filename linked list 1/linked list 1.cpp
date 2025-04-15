#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};
class Linkedlist {
public:
	Node* head;

	bool isempty(){
		return (head == NULL);
	}
	void insert_first(int val) {
		Node* newnode = new Node(); // Creat new node !!
		newnode->data = val; // اساسي ايا كانت فاضيه او لا

		if (isempty()) {
			newnode->next = NULL; 
			head = newnode;
		}
		else {
			newnode->next = head; // لان النود المتصله بالهيد اسمها هيد
			head = newnode;
		}
	}
	void display() { // treversing.
		Node* temp = head; // عشان مش هعرف اتنقل بالهيد لو تنقلت بالهبد هضيع كل عناصر الليست اللي عديت عليها

		if (isempty())
			cout << "Linked list is empty\n";
		else {
			while (temp != NULL) {
				cout << temp->data << "\t";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	int count() {
		int counter = 0;
		Node* temp = head;
		while (temp != NULL) {
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	bool search(int key) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == key)
				return true;
	
			temp = temp->next;
		}
		return false;
	}
};
int main(){
	cout << "Hello with linked list ^_^\n\n";

	Linkedlist lst{};
	cout << (lst.isempty() ? "Empty\n" : "Not empty\n");
	int k , n;
	cout << "Enter number of items you want ot add: ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Enter value number " << i << " : ";
		cin >> k;
		lst.insert_first(k);
		lst.display();
	}
	cout << "Number of elemnts in the list = " << lst.count() << endl;

	cout << "What are you searching for ? ";
	int item; cin >> item;
	cout << (lst.search(item) ? "Is found\n" : "Not found\n");

	
}

