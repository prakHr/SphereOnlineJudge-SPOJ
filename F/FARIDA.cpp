#include<bits/stdc++.h>
using namespace std;

const int me = 10025;

int t, n;
int a[me];
long long dp[me][2];

int main() {
    
    
    cin >> t;
    for(int c = 0; c < t; c ++){
        cin >> n;
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        dp[0][0] = 0;
        dp[0][1] = a[0];
        for(int i = 1; i < n; i ++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][0] + a[i], dp[i - 1][1]);
        }
        cout << "Case " << c + 1 << ": ";
        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    
    return 0;
}
