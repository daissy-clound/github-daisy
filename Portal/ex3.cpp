#include <iostream>
using namespace std;
class DoubleLinkList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node() : data(0), next(nullptr), prev(nullptr) {}
        Node(int data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    DoubleLinkList() : head(nullptr), tail(nullptr), count(0) {}

    void read(int n) {
        if(n <= 0) return;
        int x;
        cin >> x;
    
        head = new Node(x);
        tail = head;
        count = 1;
        Node* current = head;

        for (int i = 1; i < n; i++) {
            cin >> x;
            Node* newNode = new Node(x);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
            tail = current;
            count++;
        }       
    } 

    int count_triplets() {
        Node* current = head;
        int cnt = 0;

        if (count < 3)
        return 0;

        while (current->next != nullptr && current->next->next != nullptr) {
           if (0 == current->data + current->next->data + current->next->next->data) {
                cnt++;
           }

           current = current->next;
        }
        return cnt;
    }
};

int main() {
    DoubleLinkList list;
    int n;
    cin >> n;
    list.read(n);
    cout << list.count_triplets();
    return 0;
}