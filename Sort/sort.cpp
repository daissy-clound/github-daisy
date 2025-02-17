#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) swap(a[i],a[j]);
        }
    }
}

void selectionSort(int a[], int size) {
    int min;
    int vt;
    for (int i = 0; i < size - 1; i++) {
        min = a[i];
        vt = i;
        for (int j = i + 1 ; j < size; j++) {
            if (min > a[j]) {
                min = a[j];
                vt = j;
            }
        }
        swap(a[i], a[vt]);
    }
}

void insertionsort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (a[i] > a[i + 1]) {
            int min = a[i + 1];
            for (int j = i; j >= 0; j--) {
                if (min < a[j]) {
                    a[j + 1] = a[j];
                } else {
                    a[j + 1] = min;
                }
            }

        }
    }
}

void merge(int a[], int l, int m, int r) {
    vector <int> x(a + l, a + m + 1); // Tạo vector chứa phần tử a[l] đến a[m]
    vector <int> y(a + m + 1, a + r + 1); // Tạp vector chứa phần tử a[m+1] đến a[r]
    int i = 0;
    int j = 0;
    int s1 = x.size();
    int s2 = y.size();

    while (i < s1 && j < s2) {
        if (x[i] <= y[j]) {
            a[l++] = x[i++];
        } else {
            a[l++] = y[j++];
        }
    }
    while (i < s1) {
        a[l++] = x[i++];
    } 
    while (j < s2) {
        a[l++] = y[j++];
    }
}

void mergesort(int a[], int l, int r) {
    if (l >= r) return;

    int m = (l+r)/2;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, m, r);
}


int main() {
    int in;
    cin >> in;
    int a[in];
    for (int i = 0; i < in; i++) {
        cin >> a[i];
    }
    mergesort(a, 0, in - 1);
    for (int i = 0; i < in; i++) {
        cout << a[i] << " ";
    }
}
