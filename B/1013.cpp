/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1013.cpp
*   Creator    ：Max
*   Date       ：2019/02/20
*   Description：
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;

int isPrime(int a) {
  if(a==2||a==3) return 1;
  if(a%6==0) return 0;
  for(int i = 2;i<=sqrt(a);i++) {
     if(a%i==0) return 0; 
  }
  return 1;
}

int main() {
    int a,b;
    cin>>a>>b;
    vector<int> res(10001,0);
    int count = 0;
    for(int t = 2; ; t++) {
      if(isPrime(t)){ count++;
        if(count>=a&&count<=b){
          if(((count-a+1)%10)==0)
          cout<<t<<'\n';
          else if(count != b)
          cout<<t<<' ';
          else
          cout<<t;
        }
      }
      if(count>b)break;
    }
    
    return 0;

}
