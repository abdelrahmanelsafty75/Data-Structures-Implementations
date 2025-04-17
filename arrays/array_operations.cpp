#include <iostream>
using namespace std;
class Array {
private:
	int size, length;
	int* items; // array name
public:
	Array(int arrsize) {
		size = arrsize;
		length = 0;
		items = new int[arrsize]; // We booked a spot at Heap, the size I want
	}
	void fill() {
		int nofitems;
		cout << "how many items you want to enter? \n";
		cin >> nofitems;
		if (nofitems > size) {
			cout << "Invalid\n";
			return;
		}
		else {
			for (int i = 0; i < nofitems; i++) {
				cout << "enter item number " << i + 1 << ": \n";
				cin >> items[i];
				length++;  // "noitems" variable is Not global
			}
		}
	}
	void display() {
		cout << "Display : \n";
		for (int i = 0; i < length; i++) 
			cout << items[i] << "\t";
		cout << endl;
	}
	int getsize() {
		return size;
	}
	int getlength() {
		return length;
	}
	int search(int key) {
		for (int i = 0; i < length; i++) {
			if (items[i] == key)
				return i+1; // if it's foud, return it's positon.
		}
		return 0;
	}
	void append(int k) { // insert at end.
		if (length < size) {
			items[length] = k;
			length++;
		}
		else
			cout << "Array is Full.\n";
	}
	void insert(int index, int valu) { // Not replacing , we must shift element ->.
		if (index >= 0 && index < size) {
			for (int i = length; i > index; i--) {
				items[i] = items[i - 1];
			}
			items[index] = valu;
			length++;
		}
		else {
			cout << "Eror , index out of rang. \n";
		}
	}
	void Delete(int index) {
		if (index >= 0 && index < size) {
			for (int i = index; i < length - 1; i++) {
				items[i] = items[i + 1];
			}
			length--;
		}
		else {
			cout << "out of range!\n";
		}
	}
};
int main(){
	int n;
	cout << "enter array size: ";
	cin >> n;
	Array ob(n);
	ob.fill();
	 cout << "array size = " << ob.getsize() << " while array length = " <<  ob.getlength() << endl;
	// ob.display();
	int val;
	cout << "what are you searching for ? ";
	cin >> val;
	if (ob.search(val))
		cout << "is found, it's position -> " << ob.search(val) << endl;
	else
		cout << "Not found\n";
	int k;
	cout << "enter val to add to the end of array: ";
	cin >> k;
	ob.append(k);
	ob.display();
	cout << "enter index and item to insert: ";
	int item, indexx; cin >> indexx >> item;
	ob.insert(indexx, item);
	cout << "array size = " << ob.getsize() << " while array length = " << ob.getlength() << endl;
	ob.display();

	cout << "enter index to delete: ";
	int indexx2; cin >> indexx2;
	ob.Delete(indexx2);
	cout << "array size = " << ob.getsize() << " while array length = " << ob.getlength() << endl;
	ob.display();
}

