#include<bits/stdc++.h>
using namespace std;
const int me = 2025;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int a[8];
    for(int i = 0; i < 8; i ++)
        cin >> a[i];
    cout << a[0] - a[1] - a[2] - a[3] + a[4] + a[5] + a[6] - a[7] << endl;
    
    return 0;
}
