#include<bits/stdc++.h>
using namespace std;

const int MAX = 10005;

int a, b, c;

int power(int a, int b, int modulo) {
    if (b == 0) {
        return 1 % modulo;
    }
    if (b & 1) {
        return 1LL * power(a, b - 1, modulo) * a % modulo;
    }
    int half = power(a, b >> 1, modulo);
    return 1LL * half * half % modulo;
}

int main() {
    cin >> a >> b >> c;
    cout << power(a, b, c) << endl;
    
    return 0;
}
