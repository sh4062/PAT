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

int main(){
    int a[1010] = {0};
    int k, e, count = 0;
    while((cin>>k>>e),!cin.eof()){
        a[e] = k;
    }
    a[0] = 0;
    for(int i = 1;i <= 1000;i++){
        a[i-1] = a[i] * i;
        a[i] = 0;
        if(a[i-1] != 0)count++;
    }
    if(count == 0) cout<<"0 0";
    else{
        for(int i = 1000;i>=0;i--){
            if(a[i] != 0){
                cout<<a[i]<<" "<<i;
                count--;
                if(count != 0) cout<<" ";}
        }
    }
}