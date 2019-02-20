/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1001.cpp
*   Creator    ：Max
*   Date       ：2019/02/18
*   Description：
*
================================================================*/

#include<iostream>
using namespace std;
int main(){
  int count = 0;
  int a = 0;
  cin>>a;
  while(a!=1){
  if(a%2==0)a=a/2;
  else(a =(3*a+1)/2);
  count++;
  }
  cout<<count;
}
