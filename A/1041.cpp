/*
 * File: 1041.cpp
 * Project: A
 * File Created: Tuesday, 26th February 2019 4:19:19 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 4:19:21 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    vector<int>hash(10005,0);
    vector<int> seq;
    while(N--){
        int t;cin>>t;
        hash[t]++;
        seq.push_back(t);
    }
    for(auto i:seq){
        if(hash[i]==1){
            cout<<i;
            return 0 ;
        }
    }
    cout<<"None";
}