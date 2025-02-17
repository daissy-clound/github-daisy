#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int c = a;
    a = b; 
    b = c;
}

void sort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int a[size];

    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    sort(a, size);

    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }

    return 0;
}