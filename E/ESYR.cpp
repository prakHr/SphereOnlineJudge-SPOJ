#include<bits/stdc++.h>
using namespace std;

long long int p[] = {987654312678, 987898765678, 987896545674, 456789234576, 987896512307, 987654888999, 999999993425};

int main() {
    
    int T;
    cin >> T;
    while (T --) {
        long long int n, ok = 0;
        cin >> n;
        for (int i = 0; i < 7; i++) {
            if (p[i] == n) {
                ok = 1;
            }
        }
        if (ok == 1) {
            cout << "Special Number" << endl;
        } else {
            cout << "Just a number" << endl;
        }
    }
    return 0;
}
