#include <iostream>
#include <string>
using namespace std;

class Queue {
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
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    // Thêm phần tử x vào đuôi của hàng đợi.
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {  // Hàng đợi rỗng
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    // Loại bỏ phần tử ở đầu của hàng đợi.
    void dequeue() {
        if (head == nullptr) return;  // Hàng đợi rỗng, không có gì để loại bỏ
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr; // Nếu hàng đợi trở nên rỗng sau khi loại bỏ
        delete temp;
        count--;
    }

    // Xuất ra các phần tử của hàng đợi, cách nhau bởi khoảng trắng.
    void printQueue() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr)
                cout << " ";
            current = current->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Queue q;
    string op;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (op == "dequeue") {
            q.dequeue();
        }
    }
    q.printQueue();
    return 0;
}
