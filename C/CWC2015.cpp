//https://github.com/tr0j4n034/SPOJ/blob/master/DALTSUM.cpp(modular arithmetic)
//https://github.com/tr0j4n034/SPOJ/blob/master/DCEPC12G.cpp(prime number and prefix su,)
//https://github.com/tr0j4n034/SPOJ/blob/master/DCEPC14A.cpp(fenwick tree in a grid)
//https://github.com/tr0j4n034/SPOJ/blob/master/DCEPC206.cpp(simple fenwick tree)
//https://github.com/tr0j4n034/SPOJ/blob/master/DCEPC505.cpp(about divisibility of prime numbers)
//https://github.com/tr0j4n034/SPOJ/blob/master/DCEPCA03.cpp(prefix sum of totient function)
//https://github.com/tr0j4n034/SPOJ/blob/master/DIFERENC.cpp(stack operations)
//https://github.com/tr0j4n034/SPOJ/blob/master/DIG.py(formula based)
//https://github.com/tr0j4n034/SPOJ/blob/master/DIV.cpp(prime number)
//https://github.com/tr0j4n034/SPOJ/blob/master/DIVFACT.cpp(about divisibility of prime numbers)
//https://github.com/tr0j4n034/SPOJ/blob/master/DIVFIBS.cpp(fibonacci series)
//https://github.com/tr0j4n034/SPOJ/blob/master/DIVSTR.cpp(count of strings)
//https://github.com/tr0j4n034/SPOJ/blob/master/DOL.cpp(even prime divisor)
//https://github.com/tr0j4n034/SPOJ/blob/master/DRAGKING.cpp(dp sum)
//https://github.com/tr0j4n034/SPOJ/blob/master/DRAWIT.cpp(computation based on degree in a graph)
//https://github.com/tr0j4n034/SPOJ/blob/master/DRTREE.cpp(LCA of a tree)
//https://github.com/tr0j4n034/SPOJ/blob/master/DVD3.cpp(permutations of three numbers)

//https://github.com/tr0j4n034/SPOJ/blob/master/EC_DIVS.cpp(prime number and freqdict)
//https://github.com/tr0j4n034/SPOJ/blob/master/EDIT.cpp(dp)
//https://github.com/tr0j4n034/SPOJ/blob/master/EIUASSEMBLY.cpp(binary search)
//https://github.com/tr0j4n034/SPOJ/blob/master/EKO.cpp(binary search and prefix sum)
//https://github.com/tr0j4n034/SPOJ/blob/master/EMTY2.cpp(stack)
//https://github.com/tr0j4n034/SPOJ/blob/master/ESYR.cpp(JUST FOR SYNTAX)
//https://github.com/tr0j4n034/SPOJ/blob/master/ETF.cs(euler totient function)
//https://github.com/tr0j4n034/SPOJ/blob/master/ETFD.cpp(for ETF)(not done)

//https://github.com/tr0j4n034/SPOJ/blob/master/FACTCG2.cpp(smallest prime)
//https://github.com/tr0j4n034/SPOJ/blob/master/FACTMUL.py(factorial and modulo)
//https://github.com/tr0j4n034/SPOJ/blob/master/FARIDA.cpp(dp)
//https://github.com/tr0j4n034/SPOJ/blob/master/FASHION.cpp(sorting)
//https://github.com/tr0j4n034/SPOJ/blob/master/FAST2.py(long long int)
//https://github.com/tr0j4n034/SPOJ/blob/master/FASTPOW.cpp(modular exponentiation)
//https://github.com/tr0j4n034/SPOJ/blob/master/FENCE1.py(math)
//https://github.com/tr0j4n034/SPOJ/blob/master/FENTREE.cpp(fenwick tree)
//https://github.com/tr0j4n034/SPOJ/blob/master/FINGP.py(string)
//https://github.com/tr0j4n034/SPOJ/blob/master/FRNDAM.cpp(divisors sum)

//https://github.com/tr0j4n034/SPOJ/blob/master/FUNPROB.py(probability)

//https://github.com/tr0j4n034/SPOJ/blob/master/GAME3.cpp(bit manipulation)(DONE)
//https://github.com/tr0j4n034/SPOJ/blob/master/GASOLINE.cpp(dijkstra)(DONE)
//https://github.com/tr0j4n034/SPOJ/blob/master/GCDS.cpp(prime number)
//https://github.com/tr0j4n034/SPOJ/blob/master/GCPC11A.cpp(math)
//https://github.com/tr0j4n034/SPOJ/blob/master/GDCOFTI.py(gcd)(DONE)
//https://github.com/tr0j4n034/SPOJ/blob/master/GGD.cpp(gcd)(DONE)
//https://github.com/tr0j4n034/SPOJ/blob/master/GNYR04C.cpp(dp and bit manipulation)
//https://github.com/tr0j4n034/SPOJ/blob/master/GOIT.cpp(probability)(DONE)
//https://github.com/tr0j4n034/SPOJ/blob/master/GOODA.cpp(graph theory)
//https://github.com/tr0j4n034/SPOJ/blob/master/GOODB.cpp(combinatorics)(DONE)
//https://github.com/tr0j4n034/SPOJ/blob/master/GSS1.cpp(segment tree)(DONE)
//https://github.com/tr0j4n034/SPOJ/blob/master/GSS3.cpp(segment tree)



//https://www.spoj.com/problems/CAPRICA


#include<bits/stdc++.h>
using namespace std;

const int me=1000025;

int T,N;
int a[45];
bitset<25> bs[me];
int main(){
	cin >> T;
    for(int c = 0; c < T; c ++){
        cout << "Case " << c + 1 << ": ";
        cin >> N;
        int total_sum = 0;
        for(int i = 0; i < N; i ++){
            cin >> a[i];
            total_sum += a[i];
        }
//        cout<<"N & 1"<<(N & 1)<<endl;
		//checking the last set bit of total_sum
        if(total_sum & 1){
            cout << "No" << endl;
            continue;
        }
        //checking the last set bit of N
        if(N & 1){
            cout << "No" << endl;
            continue;
        }
        int half = total_sum >> 1;
        //re initializing the bitset array
        for(int i = 0; i <= half; i ++){
            bs[i].reset();
        }
        for(int i = 0; i < N; i ++){
            for(int j = half; j > a[i]; j --){
                bs[j] |= bs[j - a[i]] << 1;
            }
            bs[a[i]][1] = 1;
        }
        cout << (bs[half][N >> 1] ? "Yes" : "No") << endl;
    }
	return 0;
}
