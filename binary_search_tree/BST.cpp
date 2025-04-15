#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left, * right;

	Node(int item) { // constructor 
		data = item;
		left = right = NULL;
	}
};
class BST {
public:
	Node *root;
	BST():root(NULL){}

	Node *insert(Node* r, int item) { // 3 cases:
		if (r == NULL) { // if tree was empty
			Node* newnode = new Node(item);
			r = newnode;
			// newnode->data = item; 
			// newnode->left = NULL;
			// newnode->right = NULL , already done in the constructor.
		}
		else if (item < r->data)  // small go to left!
			r->left = insert(r->left, item);
		else                      // large go right!
			r->right = insert(r->right, item);

		return r;
	}
	void insert(int item) {  // انسرت مختصره اتعامل معاها بدل الكبيرة ,, يعني اللي جوا هي الكبيرة
		root = insert(root, item);
	}

/*  ==========================       TRAVERSING         ========================             */

	void pre_order(Node* r) {  //  root , left , right
		if (r == NULL)
			return; //empty.
		cout << r->data << "\t";
		pre_order(r->left);
		pre_order(r->right); 
		 // both recurion.
	}
	void in_order(Node* r) {  //  left , root , right
		if (r == NULL)
			return;
		in_order(r->left);
		cout << r->data << "\t";
		in_order(r->right);
	}
	void post_order(Node* r) {  //  left , right , root
		if (r == NULL)
			return;
		post_order(r->left);
		post_order(r->right);
		cout << r->data << "\t";
	}
/*========================================================================================*/
	Node* search(Node* r, int key) { // 4 cases:
		if (r == NULL)
			return NULL; // empty ? end the program.
		else if (r->data == key)
			return r; // first element (root) = key
		else if (key < r->data)
			return search(r->left, key); // key small , go left.
		else
			return search(r->right, key); // key larg , go right.
	}
	bool search(int key) {
		Node* answer = search(root, key);
		return(answer != NULL);

		// found ? answer = Node that value exist ,
	    // Not found ? answer = NULL .
	}
/*=============================================================================*/
	 // NULL = 0
	Node* findmin(Node* r) { // 3 cases:
		if (r == NULL)
			return NULL; // empty.
		else if (r->left == NULL)
			return r; // مافيش اصلا صب تري شمال يبقى الروت هو اصغر حاجة 
		else
			return findmin(r->left); // كمل نفس الخطوات ف الشمال بالريكرجن
	}
	Node* findmax(Node* r) {
		if (r == NULL)
			return NULL;
		else if (r->right == NULL)
			return r;
		else
			return findmax(r->right);
	}
/*==========================================================================*/
	Node* Delete(Node* r, int key) { // 4 cases: 
		if (r == NULL)
			return NULL; // case 1:  empty

		//  مرحلة التوجيه , لو اللي عاوز امسحه اصغر من الروت اروح شمال لو اكبر اروح يمين و بعد ما خلاص اتده ايدا شغل الالس
		else if (key < r->data)
			r->left = Delete(r->left, key);
		else if (key > r->data)
			r->right = Delete(r->right, key);

		else { // خلاص وصلتله اللي عاوز امسحه
			if (r->left == NULL and r->right == NULL) // case 2: leaf node
				r = NULL;

			// case 3: that node has one child (left or right)
			else if (r->left != NULL and r->right == NULL) { // one child on left
				r->data = r->left->data; // transfer data from child to pairent that will be removed.
				delete r->left;
				r->left = NULL;
			}
			else if (r->left == NULL and r->right != NULL) { // one child on right
				r->data = r->right->data;
				delete r->right;
				r->right = NULL;
			}
			else { // case 4: that node has two children: replace it with the largest on left OR smallest on right.
				Node* pre = findmax(r->left);
				r->data = pre->data;   // خلاص لقيناه بالفايند و نقلنا قيمته
				r->left = Delete(r->left, pre->data); // نحذفه بقا بعد ما نقلنا قيمته من الليفت و نسيف شكل الليفت تري بعد الحذف
			}
		}
		return r;
	}
};

int main(){
	cout << "Hello With Binary Search Tree  ^_^ \n\n";

	BST ob; // 45 15 79 90 10 55 12 20 50 
	ob.insert(45);
	ob.insert(15);
	ob.insert(79);
	ob.insert(90);
	ob.insert(10);
	ob.insert(55);
	ob.insert(12);
	ob.insert(20);
	ob.insert(50);

	cout << "Display the tree content: \n";
	cout << "Pre_ordr: \n";
	   ob.pre_order(ob.root);    // لازم اباصي الروت قبل اي شغل عشان اعرفه يبدا من عنده
	cout << "\nIn-order: \n";
	   ob.in_order(ob.root);
	cout << "\nPost_order: \n";
	   ob.post_order(ob.root);


	   cout << "\nEnter value to search: ";
	   int n; cin >> n;
	   cout << (ob.search(n) ? "Found" : "NOT found") << endl;


	   cout << "Find minimum: \n";
	   Node* mn = ob.findmin(ob.root);
	   if (mn != NULL)
		   cout << "Here it's : " << mn->data << endl;
	   else
		   cout << "Not exist!" << endl;

	   cout << "Find maximum: \n";
	   Node* mx = ob.findmax(ob.root);
	   if (mx != 0)
		   cout << "Here it's : " << mx->data << endl;
	   else
		   cout << "Not exist!" << endl;


	   cout << "which item you want to delete: ";
	   int k; cin >> k;
	   Node* result = ob.Delete(ob.root, k);
	   cout << "After Deletion: \n";
	   ob.pre_order(result);

	return 0;
}
