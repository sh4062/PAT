/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1017.cpp
*   Creator    ：Max
*   Date       ：2019/02/20
*   Description：
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
int main() {
  string a; int b;
  cin>>a>>b;
  string Q;
  int R;
  int temp = a[0] - '0';
  if((a[0]-'0')>=b)Q.push_back(temp/b + '0');
  for(int i = 1;i<a.length();i++) {
    R=temp%b;
    temp = R*10+a[i]-'0';
    Q.push_back(temp/b+'0');
  }
  R = temp%b;
  if(a.length() == 1&& a[0] - '0' < b) 
    cout<<"0 "<<a[0]-'0';
  else 
    cout<<Q<<" "<<R;

}
