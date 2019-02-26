/*
 * File: 1125.cpp
 * Project: A
 * File Created: Tuesday, 26th February 2019 11:52:12 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 11:52:14 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<double> ropes;
    for(int i = 0; i < N; i++)
    {
        double t;
        cin>>t;
        ropes.push_back(t);
    }
    sort(ropes.begin(),ropes.end());
    for(int i = 0; i < N - 1; i++)
    {int j= i+1;
     ropes[j] = ropes[i]/2+ropes[j]/2;
    }
    cout<<(int)ropes[N-1];
}
