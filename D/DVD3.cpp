#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int result = 1234;
string a, b, c, now;

int stoi(string s){
	int num=0,pow10=1;
	for(int i=0;i<s.length();i++){
		num=num*pow10+s[i]-'0';
		pow10*=10;
	}
	return num;
}
int main() {
    cin >> a >> b >> c;
    now = a; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = a + a; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = a + a + a; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = b; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = b + b; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = b + b + b; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = c; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = c + c; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = c + c + c; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = a + b; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = a + c; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = b + c; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = b + a; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = c + a; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = c + b; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = a + b + c; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = a + c + b; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = b + a + c; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = b + c + a; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = c + a + b; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    now = c + b + a; if (stoi(now) % 3 == 0) result = min(result, stoi(now));
    
    cout << result << endl;
    
    return 0;
}
