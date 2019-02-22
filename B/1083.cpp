/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1083.cpp
*   Creator    ：Max
*   Date       ：2019/02/20
*   Description：
*
================================================================*/
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> vec(n,0);
  vector<int> vec2;
  int a[n]={0};
  int b[n]={0};
  for(int i = 0;i < n;i++) {
    vec2.push_back(i+1);
    cin>>vec[i];
    a[i]=abs(vec[i]-vec2[i]);
  }
  for(int i = 0;i < n;i++) {
    b[a[i]]++;
  }
  for(int i = n-1;i>=0;i--) {
    if(b[i]>1)cout<<i<<' '<<b[i]<<'\n';
  }
}

