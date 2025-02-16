#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    for (int i = 0; i < (int) a.size(); i++) {
        cout << a[a.size() - i - 1];
    }
    return 0;
}