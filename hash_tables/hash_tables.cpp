// Description: Simple hash table implementation using linear probing
#include <iostream>
#define SIZE 10
using namespace std;

class HashTable {
private:
    int table[SIZE];
    bool occupied[SIZE];
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            occupied[i] = false;
        }
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        while (occupied[index]) {
            index = (index + 1) % SIZE; // Linear probing
        }
        table[index] = key;
        occupied[index] = true;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            if (occupied[i]) {
                cout << "Index " << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.display();
    return 0;
}