/*
 * File: 1120.cpp
 * Project: A
 * File Created: Sunday, 24th February 2019 9:48:28 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Sunday, 24th February 2019 9:48:33 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
set<int> ret;
int sum; 
void sums(string s){
    sum = 0;
    for(char i:s){
        sum+=i-'0';
    }
    ret.insert(sum);    
}
int main(){
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        sums(s);

    }
    cout<<s.size()<<endl;
    int cnt = 0;
    for(auto i:ret) {
        cnt++;
        if(cnt==ret.size()){
            cout<<i;

        }else{
            cout<<i<<" ";

        }

    }


}