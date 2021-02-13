#include<bits/stdc++.h>
using namespace std;

const long long me = 10000025;

int n;
int sp[me];

int main()
{
    
    for(int i = 2; i < me; i ++)
        if(!sp[i]){
            for(int j = i; j < me; j += i)
                if(!sp[j])
                    sp[j] = i;
        }
    
    while(scanf("%d", &n) != EOF){
        printf("1");
        while(n > 1){
            printf(" x %d", sp[n]);
            n /= sp[n];
        }
        puts("");
    }
    
    return 0;
}
