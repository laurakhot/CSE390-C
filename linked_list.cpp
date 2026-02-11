#include <iostream> 
#include <string> 
#include <sstream> 

using namespace std; 

// back              // list_node*
// *back             // list_node
// back->next        // list_node*

// simple objects better as struct
// everything by default public
struct list_node {
    list_node(int init_data = 0, list_node * link = nullptr) {
        data = init_data;
        next = link;
    }
    int data; 
    list_node * next;
};

class linked_list {
    public: 
    linked_list() { // 0 arg constructor
        front = back = nullptr;
        count = 0;
    }

    // copy constructor
    linked_list(const linked_list & rhs) {
        copy_from(rhs.front);
        count = rhs.count;
    }

    ~linked_list() {
        delete_nodes(front); // pass pointer to first node that want to get rid of (starting from front get rid of nodes)
    }

    void add(int num) {
        // list_node * new_node = new list_node(num); // in heap
        // back->next = new_node;
        // back = back->next;
        // empty list: 
        if (count == 0) {
            front = back = new list_node(num);
        } else {
            back = back->next = new list_node(num);
        } 
        count ++;
    }

    int size() const {
        return count;
    }

    string to_string() const {
        ostringstream out; 
        out << "["; 
        if (count > 0) {
            out << front->data; 
            list_node * curr = front->next; 
            while (curr != nullptr) {
                out << ", " << curr->data;
                curr = curr->next;
            }
        }
        out << "]";
        return out.str();
    }

    // return reference to the linked list to support chaining
    linked_list & operator=(const linked_list & rhs) { // mutating state so needs to be member function
        if (this != &rhs) {
            delete_nodes(front);
            copy_from(rhs.front); 
            count = rhs.count;
        }
        return *this;
    }

    const int & operator[](int index) const { // want to return reference to int inside node to make it modifiable
        return node_at(index)->data;
    }

    int & operator[](int index) { // want to return reference to int inside node to make it modifiable
        return node_at(index)->data;
    }

    private: 
        list_node * front;
        list_node * back;
        int count;

        // returns the node at a particular index 
        list_node * node_at(int index) const {
            list_node * curr = front; 
            while(index > 0) {
                curr = curr->next;
                index--;
            }
            return curr;
        }

        void delete_nodes(list_node * curr) {
            while (curr != nullptr) {
                list_node* temp = curr->next; 
                delete curr; // becomes dangling pointer
                curr = temp;
            }
        }

        void copy_from(list_node * other) {
            if (other == nullptr) {
                front = back = nullptr; 
            } else {
                front = new list_node(other->data); // know at least one node exists (not empty)
                list_node * curr1 = other->next; 
                list_node * curr2 = front; 
                while (curr1 != nullptr) {
                    curr2->next = new list_node(curr1->data); 
                    curr1 = curr1->next;
                    curr2 = curr2-> next;
                }
                back = curr2;
            }
        }
};

void print(const linked_list & list) {
    cout << "["; 
    if (list.size() > 0) {
        cout << list[0]; 
        for (int i = 0; i < list.size(); i ++) {
            cout << ", " << list[i]; 
        }
    }
    cout << "]";
}

int main() {
    linked_list list; 
    // cout << list.to_string() << endl;
    // list.add(2);
    // list.add(4);
    // list.add(7);
    // cout << "size = " << list.size() << endl;
    // cout << list.to_string() << endl;
    for (int n : {3, 18, 12, 7, 16, 15, 0, 7}) {
        cout << "list 1 = " << list.to_string() << ", adding " << n << endl;
        list.add(n);
    }

    linked_list list2 = list; // linked_list list2(list1) -> copy constructor (manipulating list 2 should not change list 1)
    list2.add(6); 
    cout << "list 1 = " << list.to_string() << endl; 
    cout << "list 2 = " << list2.to_string() << endl;

    linked_list list3; 
    list3.add(10); 
    list3.add(20); 
    cout << "list 3 = " << list3.to_string() << endl; 
    list3 = list; // assignment operator (list 3 should be assigned everything in list 1; without overloading this is shallow copy)
    cout << "list 3 = " << list3.to_string() << endl; 

    list = list2 = list2; 

    for (int i = 0; i < list.size(); i++) {
        // cout << list[i] << endl;
        list[i] *= 2;
        // cout << list[i] << endl;
    }
    return 0;
}