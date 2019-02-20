/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1002.cpp
*   Creator    ：Max
*   Date       ：2019/02/19
*   Description：
*
================================================================*/

#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin>>a;
  long b = 0;
  for(char i : a) {
  b+=i-'0';}
  stringstream ss;
  ss<<b;
  ss>>a;
  int l = a.size();
  map<char,string> m;
  vector<char> aa = {'0','1','2','3','4','5','6','7','8','9'};
  vector<string> bb = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
  for(int i = 0;i<=9;i++)
  m.insert(make_pair(aa[i],bb[i]));
  for(char i:a){
    cout<<m[i];
    if(l>1)cout<<" ";
    l--;
  }
}
