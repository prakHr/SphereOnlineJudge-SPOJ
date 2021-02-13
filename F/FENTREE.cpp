#include<bits/stdc++.h>
using namespace std;

const int me = 1000025;

int n, q, x, y;
char type;
int a[me];
long long ft[me];

void add(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] += value;
}
long long get(int pos){
    long long s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s += ft[pos];
    return s;
}
long long get(int l, int r){
    return get(r) - get(l - 1);
}

int main(int argc, const char * argv[]) {
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
        add(i, a[i]);
    }
    scanf("%d", &q);
    while(q --){
        scanf(" %c%d%d", &type, &x, &y);
        if(type == 'u'){
            add(x, y);
            a[x] += y;
        }
        else{
            printf("%lld\n", get(x, y));
        }
    }
    
    return 0;
}
