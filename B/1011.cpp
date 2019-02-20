/*================================================================
 *   Copyright (C) 2019 Max. All rights reserved.
 *   
 *   Filename   ：1011.cpp
 *   Creator    ：Max
 *   Date       ：2019/02/20
 *   Description：
 *
 ================================================================*/
#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int t =1;
  while(n--){
    long long a,b,c;
    cin>>a>>b>>c;
    if(a+b>c) {cout<<"Case #"<<t<<": true"<<endl;t++;}
    else{cout<<"Case #"<<t<<": false"<<endl;t++;}
  }
}
