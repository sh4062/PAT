/*================================================================
 *   Copyright (C) 2019 Max. All rights reserved.
 *   
 *   Filename   ：1081.cpp
 *   Creator    ：Max
 *   Date       ：2019/02/20
 *   Description：
 *
 ================================================================*/
#include<bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin>>a;
  getchar();
  string S;
  while(a--){
    int shuzi = 0,zimu = 0;
    getline(cin,S);
    if(S.length()<6){
      cout<<"Your password is tai duan le.\n";
      continue;
    }else{
      for(char i:S){
        if(i!='.'&&(isdigit(i)==0)&&(isalpha(i)==0)){
          goto res;
        }
        if(isdigit(i)){shuzi = 1;}
        if(isalpha(i)){zimu = 1;}
      }
      if(shuzi&&zimu){
        cout<<"Your password is wan mei.\n";
        continue;
      }
      else if(shuzi==1&&zimu==0){
        cout<<"Your password needs zi mu.\n";
        continue;
      }
      else if(shuzi==0&&zimu==1){
        cout<<"Your password needs shu zi.\n";
        continue;
      }
    }

res:
    cout<<"Your password is tai luan le.\n";
  }  

}

