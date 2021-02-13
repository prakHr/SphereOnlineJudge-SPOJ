#include<bits/stdc++.h>
using namespace std;

const int me = 1025;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    long long n;
    
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n;
        while(n % 2 == 0)
            n /= 2;
        cout << "Case " << c + 1 << ": " << n << endl;
    }
    
    return 0;
}
