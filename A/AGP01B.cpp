#include<bits/stdc++.h>
using namespace std;

const int me = 2025;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t, b, c, w;
    cin >> t >> b >> c >> w;
    if(b <= t)
        cout << "Bus" << endl;
    else if(c <= t)
        cout << "CNG" << endl;
    else if(w <= t)
        cout << "Walk" << endl;
    else cout << "Too Late" << endl;

    return 0;
}
