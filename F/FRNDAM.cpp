#include<bits/stdc++.h>
using namespace std;

int sod (int x) {
    int res = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res += i + x / i;
            if (i * i == x) {
                res -= i;
            }
        }
    }
    return res;
}

int main() {
    
    int T;
    cin >> T;
    while (T --) {
        int x, y;
        cin >> x >> y;
        if (sod (x) == x + y && sod (y) == x + y) {
            cout << "Friendship is ideal" << endl;
        } else {
            cout << "Friendship is not ideal" << endl;
        }
    }
    return 0;
}
