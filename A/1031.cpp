//题意说了左边长度n1=右边长度n3，而且n1<=n2，n2为一行字符的长度。而且n1+n2+n3-2=n。
//所以可以得到n1=(n+2)/3，n2=n+2-n1*2。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5+5;
const ll INF = 0x3f3f3f3f;
const double eps=1e-4;
const int T=3;
 
int main() {
    char  str[N];
    cin>>str;
    int sz=strlen(str);
    int n1=(sz+2)/3,n2=sz-2*n1+2;
    for(int i=0; i<n1-1; i++) {
        cout<<str[i];
        for(int j=0; j<n2-2; j++) {
            cout<<" ";
        }
        cout<<str[sz-i-1]<<endl;
    }
    for(int i=n1-1; i<n1+n2-1; i++) {
        cout<<str[i];
    }
    return 0;
}
