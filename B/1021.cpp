/*================================================================
 *   Copyright (C) 2019 Max. All rights reserved.
 *   
 *   Filename   ：1021.cpp
 *   Creator    ：Max
 *   Date       ：2019/02/20
 *   Description：
 *
 ================================================================*/
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
int main(){
  string a;
  cin>>a;
  int cnt = 0;
  vector<int> mp(10);
  for(unsigned int i = 0;i<a.size();i++){
    mp[int(a[i])-48]++;}
  for(int i = 0;i<10;i++){
    if(mp[i] != 0){
      printf("%d:%d\n",i,mp[i]);
    }}
}
