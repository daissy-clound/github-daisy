#include <bits/stdc++.h>
using namespace std;

int divisor(int a, int b) {
    for (int i = min(a,b); i > 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 0;
}

int main() {
    int a, b;
    cin >> a >> b;
    int c = divisor(a, b);
    cout << c;
    return 0;
}