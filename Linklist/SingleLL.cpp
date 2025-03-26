#include <iostream>
using namespace std;

struct: Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public: 
    LinkedList() :head(nullptr) {}

    void inserAtBegining(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void printList() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int main() {
        LinkList myList;

        myList.insertAtBegining(10);
        myList.insertAtBegining(20);    
        myList.insertAtBegining(30);
        myList.insertAtBegining(40);

        myList.printList();
        return 0;
    }

    }