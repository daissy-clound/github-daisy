#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    for (int i = (int) a.size() - 1; i >= 0; i--) {
        cout << a[i];
    }
    return 0;
}