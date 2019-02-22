/*
 * File: 1132.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 12:21:16 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 12:21:17 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    string b,c,d;
    while(a--){
        cin>>b;
        int k = b.length()/2;
        c = b.substr(0,k);
        d = b.substr(k,k);
        if((stol(c)!=0&&stol(d)!=0)&&stol(b)%(stol(c)*stol(d))==0){
            //  cout<<c<<d;
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }

}