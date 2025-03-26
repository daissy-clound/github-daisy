#include <iostream>
#include <stdexcept>
using namespace std;

class SingleLinkList {
private:
    struct Node {
        int data;
        Node* next;
        Node() : data(0), next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int count;

public: 
    SingleLinkList() : head(nullptr), tail(nullptr), count(0) {}

    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;

            if (tail == nullptr) {
                tail = head;
            }

        } else {
            Node* temp = head;

            for (int i = 0; i < p - 1; i++) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;

            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
        count++;
    }

    void deleteNode(int p) {
        if (p < 0 || p >= count) {
            return;
        }

        if (p == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;

            for (int i = 0; i < p - 1; i++) {
                temp = temp->next;
            }

            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;

            if (temp->next == nullptr) {
                tail = temp;
            }
        }
        count--;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    
    SingleLinkList list;
    list.insert(0, 1);
    list.insert(1, 3);       
    list.insert(1, 4);
    list.insert(2, 2);
    list.deleteNode(1);
    list.display();

    return 0;
}