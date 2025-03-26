#include <iostream>
#include <string>
using namespace std;

class Stack {
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
    Stack() : head(nullptr), tail(nullptr), count(0) {}

    // Thêm phần tử x vào đỉnh của stack (chính là đuôi danh sách liên kết)
    void push(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {  // Nếu stack rỗng
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    // Loại bỏ phần tử ở đỉnh của stack (đuôi danh sách liên kết)
    void pop() {
        if (tail == nullptr) return;  // Nếu stack rỗng, không có gì để pop
        Node* temp = tail;
        if (head == tail) { // Chỉ có 1 phần tử
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        count--;
    }

    // In ra stack theo thứ tự từ đáy đến đỉnh, các số cách nhau bằng khoảng trắng.
    void printStack() {
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
    Stack s;
    string a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (a == "pop") {
            s.pop();
        }
    }
    s.printStack();
    return 0;
}
