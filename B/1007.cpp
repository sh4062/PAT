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
int pp[100001] = {0};
int prime(int a) {  
    if(a % 2 == 0 && a != 2) {  
        return 0;  
    }  
    for(int i = 3; i * i <= a; i++) {  
        if(a % i == 0) {  
            return 0;  
        }  
    }  
    return a != 1;  
}  
int main() {
    int n = 0;
    int sum = 0, sub = 0;
    cin>>n;
    for (int i = 2; i <= 100010; i++) {  //一次性筛选出最大范围内的所有素数   
        if(prime(i)) {  
            pp[sub++] = i;  
        }  
    }  
    for(int i = 1; pp[i] <= n; i++) {   //求出n以内的素数对的对数   
        if(pp[i] - pp[i - 1] == 2) {  
            sum++;  
        }  
    }  
    cout << sum << endl;  
    return 0;  
}