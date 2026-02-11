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

    linked_list(linked_list * rhs) {
        copy_from(rhs->front);
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

    private: 
        list_node * front;
        list_node * back;
        int count;

        void delete_nodes(list_node * curr) {
            while (curr != nullptr) {
                list_node* temp = curr->next; 
                delete curr; // becomes dangling pointer
                curr = temp;
            }
        }

        void copy_from(list_node * other) {
            if (other == nullptr) {
                front = nullptr; 
            } else {
                
            }
        }
};

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

    linked_list list2 = list; // linked_list list2(list1) -> copy constructor
    return 0;
}