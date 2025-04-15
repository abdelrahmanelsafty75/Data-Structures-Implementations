#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left, * right;

	Node(int item) {
		data = item;
		left = right = NULL;
	}
};
class BST {
public:
	Node* root;
	BST():root(NULL){}

	Node* insert(Node* r, int val) {
		if (r == NULL) {
			Node* newnode = new Node(val);
			r = newnode;
		}
		else if (val < r->data) {
			r->left = insert(r->left, val);
		}
		else {
			r->right = insert(r->right, val);
		}
		return r;
	}
	void insert(int val) {
		root = insert(root, val);
	}

	void pre_order(Node* r) {
		if (r == NULL)return;

		cout << r->data << "\t";
		pre_order(r->left);
		pre_order(r->right);
	}
	void in_order(Node* r) {
		if (r == NULL)return;

		in_order(r->left);
		cout << r->data << "\t";
		in_order(r->right);
	}
	void post_order(Node* r) {
		if (r == NULL)return;

		pre_order(r->left);
		pre_order(r->right);
		cout << r->data << "\t";
	}

	Node* search(Node* r, int key) {
		if (r == NULL)return;
		else if (key == r->data)
			return r;
		else if (key < r->data)
			return search(r->left, key);
		else
			return search(r->right, key);
	}
	bool search(int key) {
		Node* ans = search(root, key);
		return(ans != NULL);
	}
};

int main(){
   cout << "Hello Nigga let's practice: ^_^ \n\n";

  

  
   return 0;
}

