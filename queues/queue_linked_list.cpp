#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
};
class Queue {
public:
    Node* front = NULL, * rear = NULL;
    bool isEmpty() {
        return(front == NULL); // empty
  }
   void enqueue(int val) {   // adding an item
       Node* newnode = new Node();
       newnode->data = val;
       newnode->next = NULL; 
       if (isEmpty()) {
           front = rear = newnode;  // first node
       }
       else {
           rear->next = newnode;  
           rear = newnode;      
       }
   }
   void dequeue() {  // deleting an item
      if (isEmpty())
          cout << " queue is already empty.\n";
      else if (front == rear) { // queue has only one node.
          Node* delptr = front;
          front = rear = NULL;   
          delete delptr;
      }
      else {
          Node* delptr = front;
          front = front->next;
          delete delptr;
      }
   }
   int peak() {  // return the first item
       if (isEmpty()) {
           cout << "queue is already emptpy.\n";
           return -1;
       }
       else {
           return front->data;
       }
   }
   void clear() {  // delete all items
       while (!isEmpty())
           dequeue();
    }
   void display() {   // display itmes
       if (isEmpty())
           cout << "queue is already empty.\n";
       else {
           Node* temp = front;
           while (temp != NULL) {
               cout << temp->data << "\t";
               temp = temp->next;
           }
           cout << endl;
       }
   }
};
int main() {
    cout << "Hello with queue ^_^ : \n\n";
    Queue q;
    q.enqueue(10);
    q.enqueue(100);
    q.enqueue(1000);
    q.display();
    q.dequeue();
    cout << "the peak = " << q.peak() << "\n\n";
    q.display();
    q.clear();
    q.display();
   
    return 0;
}

