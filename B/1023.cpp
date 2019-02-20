/*================================================================
 *   Copyright (C) 2019 Max. All rights reserved.
 *   
 *   Filename   ：1023.cpp
 *   Creator    ：Max
 *   Date       ：2019/02/20
 *   Description：pat1023 
 *
 ================================================================*/

#include<bits/stdc++.h>
using namespace std;
vector<int> v(10,0);
int main() {
  for(int i = 0;i<10;i++) {
    cin>>v[i];
  }
  if(v[0]==0){
    for(int i = 0;i<10;i++) {
      for(int j = 0;j<v[i];j++){
        cout<<i;
      }
    }
  }
  else{
    int index = 0;
    for(int i = 1;i<10;i++){
      if(v[i]!=0){index=i;break;}
    }
      cout<<index;
      v[index]--;
    for(int i =0;i<v[0];i++)cout<<0;
    for(int i = 1;i<=9;i++){
      for(int j = 0;j<v[i];j++)
        cout<<i;
    }
  }
}
