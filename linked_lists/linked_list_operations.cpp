#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};
class Linkedlist {
public:
	Node* head = NULL;

	bool isempty() {
		return (head == NULL);
	}
	void insert_first(int val) {  // insert first
		Node* newnode = new Node(); // Creat new node 
		newnode->data = val; 

		if (isempty()) {
			newnode->next = NULL;
			head = newnode;
		}   
		else {
			newnode->next = head; 
			head = newnode; 
		}
	}
	void insertEnd(int val) { // insert at the end = append 
		Node* newnode = new Node();
		newnode->data = val;
		if (isempty()) {
			head = newnode;
			newnode->next = NULL;
		}
		else {
			Node* temp = head;
			while (temp->next != NULL) { // stop at the last node
				temp = temp->next;
			}
		     temp->next = newnode;     
		     newnode->next = NULL;  
		}
	}
	void insertBefore(int item, int val) { // insert befor an item
		if (isempty())
			insert_first(val);
		if (search(item)) {  // make sure about that item is exists
			Node* temp = head;

			Node* newnode = new Node();
			newnode->data = val;
			
			while (temp != NULL && temp->next->data != item) {
				temp = temp->next;
			}
			newnode->next = temp->next;  
			temp->next = newnode;
		}
		else {
			cout << "Sorry ,item is not found! \n";
		}
	}
	void InsertAt(int item, int pos) {// Insert in particular position
		int curr = 1;
		Node* newnode = new Node;
		newnode->data = item;

		if (isempty()) { // list is empty
			newnode->next = NULL;
			head = newnode;
		}
		else if (pos == 1) { // first position to be head node
			newnode->next = head;
			head = newnode; // insert_first
		}
		else
		{
			Node* temp = head;
			while (curr < pos - 1) {
				curr++;
				temp = temp->next;
			}
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
	void append(int item) {  // insert end
		if (isempty())
			insert_first(item);
		else {
			Node* temp = head;

			Node* newnode = new Node();
			newnode->data = item;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			newnode->next = NULL;
			temp->next = newnode;
		}
	}
	void display() { // treversing.
		Node* temp = head; // creating another pointer, because if i treversing with the 
						  // head pointer i lose the previous nodes
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
	int count() {      // count nodes
		int counter = 0;
		Node* temp = head;
		while (temp != NULL) {
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	bool search(int key) {  // search for node
		Node* temp = head;
		while (temp != NULL) {
			if (temp->data == key)
				return true;

			temp = temp->next;
		}
		return false;
	}
	int search_ret_pos(int key) { // search and return value's positon if exist.
		Node* temp = head;
		int pos = 1;
		while (temp != NULL) {
			if (temp->data == key)
				return pos;

			pos++;
			temp = temp->next;
		}
		return -1;
	}
	void Delete_item(int item) { // Delete 
		Node* delptr = head;
		if (isempty())
			cout << "List is already empty.\n";
		if (head->data == item) {  // state 1
			head = head->next;
			delete delptr; 
		}
		else {  // state 2
			Node* prev = NULL; 
			while (delptr->data != item) {
				prev = delptr;
				delptr = delptr->next;
			} // كده خلاص وصلنا
			prev->next = delptr->next;
			delete delptr;
		}
	}
	void Delete_first() { // Delete first item
		if (isempty())
			cout << "Already empty!\n";
		else {
			Node* delptr = head;
			head = head->next;
			delete delptr;
		}
	}
	void Delete_end() {
		if (isempty())  // no lists
			cout << "already empty. \n";
		else if (head->next == NULL) { // contan's only one node.
			delete head;
			head = NULL;  // empty.
		}
		else {
			Node* temp = head;
			while (temp->next->next != NULL) { 
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
		}
	}
};
int main() {
	cout << "Hello with linked list ^_^\n\n";

	Linkedlist lst{};
	cout << (lst.isempty() ? "Empty\n" : "Not empty\n");
	int k, n;
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

	//cout << (lst.isempty() ? "Empty\n" : "Not empty\n");
	int x, y;
	cout << "Enter item and value to insert befot it: \n";
	cin >> x >> y;
	lst.insertBefore(x, y);
	lst.display();

	int v;
	cout << "Enter value to add at the end: ";
	cin >> v;
	lst.append(v);
	lst.display();

	cout << "What are you searching for ? ";
	int ite; cin >> ite;
	cout << (lst.search(ite) ? "Is found\n" : "Not found\n");

	int d;
	cout << "Enter item to delete: ";
	cin >> d;
	lst.Delete_item(d);
	lst.display();

	cout << "deleting the last elemnt : \n";
	lst.Delete_end();
	lst.display();
}

