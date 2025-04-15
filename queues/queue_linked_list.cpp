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
        return(front == NULL); // معنى ان الفرونت بنل انه اكيد الرير بنل فواحد كفايه
  }
   void enqueue(int val) {
       Node* newnode = new Node();
       newnode->data = val;
       newnode->next = NULL; //لان اي نود هضيفها هتبقى ف الاخر عند الرير فا النيكست بتاعها بنل
       if (isEmpty()) {
           front = rear = newnode;  // first node
       }
       else {
           rear->next = newnode;  // النود اللي كانت الاخيرة "رير" تشاور على اللي لسه ضايفها
           rear = newnode;        // رير بوينتر بقا
       }
   }
   void dequeue() {
      if (isEmpty())
          cout << " queue is already empty.\n";
      else if (front == rear) { // only one node.
          Node* delptr = front;
          front = rear = NULL;   //هرجعهم زي ما كانوا ف الاول لان النود الوحيده اتمسحت 
          delete delptr;
      }
      else {
          Node* delptr = front;
          front = front->next;
          delete delptr;
      }
   }
   int peak() {
       if (isEmpty()) {
           cout << "queue is already emptpy.\n";
           return -1;
       }
       else {
           return front->data;
       }
   }
   void clear() {
       while (!isEmpty())
           dequeue();
    }
   void display() {
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

