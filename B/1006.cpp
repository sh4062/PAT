/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1040.cpp
*   Creator    ：Max
*   Date       ：2019/02/19
*   Description：
*
================================================================*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    int p3 = a/100;
    while(p3>0){
        cout<<"B";
        p3--;
    }
    int p2 = (a%100)/10;
    while(p2>0){
        cout<<"S";
        p2--;
    }
    int p1 = a%10;
    for(int i = 1;i<=p1;i++){
        cout<<i;
    }

}