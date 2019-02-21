#include<bits/stdc++.h>
using namespace std;
long isPrime(long a){
  if(a==1) return 0;
  if(a==2||a==3)return 1;
  if(a%2==0)return 0;
  if(a%3==0)return 0;
  for(long i = 3;i<sqrt(a);i+=2){
    if(a%i==0) return 0;
  }
  return 1;
}
int main() {
    long a,b;
    string c;
    cin>>a>>b;
    cin>>c;
    if(b>a){cout<<404;return 0;}
    for(long i = 0;i<=c.length()-b;i++) {
      long tmp = 0;
      for(long j = 0;j<b;j++) {
         tmp =tmp*10+ (c[i+j]-'0');
//         cout<<tmp;
      }
//      if(tmp/(long)pow(10,b-1)==0)continue;
      if(isPrime(tmp)) {
        printf("%.*d", b, tmp);
        return 0;
      } 
    }
    cout<<404;
}
