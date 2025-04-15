#include <iostream>
using namespace std;

class Branch {
public:
    int id;
    string name;
    string manager;
    Branch* next;

    Branch(): id(0), name(""), manager(""), next(NULL) {}
};

class AccountHolder {
public:
    int id;
    string name;
    string address;
    double balance;
    AccountHolder* next;

    AccountHolder(): id(0), name(""), address(""), balance(0.0), next(NULL) {}
        
};

class Branches_Linkedlist {
public:
    Branch* head;

    Branches_Linkedlist() :head(NULL) {};

    void Add_Branch(int id, string name, string manager) {
        Branch* newbranch = new Branch();
        newbranch->id = id;
        newbranch->name = name;
        newbranch->manager = manager;

        newbranch->next = head;
        head = newbranch;
    }
    void Display_Branches() {
        Branch* temp = head;

        while (temp != NULL) {
            cout << "Branch ID: " << temp->id << ", Name: " << temp->name
            << ", Manager: " << temp->manager << endl;

            temp = temp->next;
        }
        cout << endl;
    }
    bool Search_byId(int id) {
        Branch* temp = head;

        while (temp != NULL) {
            if (temp->id == id)
                return true;
            temp = temp->next;
        }
        return false;
    }
};

class AccountHolders_LinkedList {
public:
    AccountHolder* head;
    AccountHolders_LinkedList() :head(NULL) {};

    void Add_holder(int id, string name, string address, double balance) {

        AccountHolder* newaccountholder = new AccountHolder();

        newaccountholder->id = id;
        newaccountholder->name = name;
        newaccountholder->address = address;
        newaccountholder->balance = balance;

        newaccountholder->next = head;
        head = newaccountholder;
    }
    void Remove_holder_byId(int id) {
        AccountHolder* delptr = head;

        if (delptr->id == id) {
            head = head->next;
            delete delptr;
        }
        else {
            AccountHolder* prev = NULL;
            while (delptr->id != id) {
                prev = delptr;
                delptr = delptr->next;
            }
            prev->next = delptr->next;
            delete delptr;
        }
    }
    void Display_AccountHolders() {
        AccountHolder* temp = head;
        while (temp != NULL) {
            cout << "Holder ID: " << temp->id << ", Name: " << temp->name
                << ", Address: " << temp->address << ", Balance: " << temp->balance << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    bool Search_byName(string name) {
        AccountHolder* temp = head;

        while (temp != NULL) {
            if (temp->name == name)
                return true;
            temp = temp->next;
        }
        return false;
    }
   AccountHolder *Search_byNameptr(string name) {  // for a reason
        AccountHolder* temp = head;

        while (temp != NULL) {
            if (temp->name == name)
                return temp;
            temp = temp->next;
        }
        return NULL;
    } 
    void UpdateInformation_byName(int newId, string name, string newAddress, double newBalance) {
        AccountHolder* holder = Search_byNameptr(name);
        if (Search_byNameptr(name)) {
            holder->id = newId;
            holder->address = newAddress;
            holder->balance = newBalance;
        }
        else {
            cout << "NOT exist!\n";
        }
    }
};
int main(){

    Branches_Linkedlist b;
    b.Add_Branch(230, "America", "Elsafty");
    b.Add_Branch(360, "France", "Samy");
    b.Add_Branch(500, "Eygpt", "Reda");

    b.Display_Branches();

    cout << (b.Search_byId(420) ? "Found!\n\n" : "NOT Found!\n\n");
        
    cout << "=======================================================\n\n";

    AccountHolders_LinkedList h;
    h.Add_holder(1000, "Elsafty", "Giza", 1250.00);
    h.Add_holder(2000, "Reda", "Tanta", 5650.00);
    h.Add_holder(3000, "Hmad", "Fesal", 9400.00);

    h.Display_AccountHolders();

    h.Remove_holder_byId(2000);

    h.Display_AccountHolders();

    cout << (h.Search_byName("Hmad") ? "Found!\n\n" : "NOT Found!\n\n");

    h.UpdateInformation_byName(5000, "Hmad", "Haram", 120.00);

    cout << "After Updates: \n";

    h.Display_AccountHolders();

	return 0;
}

