/*
 * File: 1144.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 10:10:49 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 10:10:50 am
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
    set<int> s;
    while(a--){
        int b;
        cin>>b;
        if(b>0&&s.find(b)==s.end()){
            s.insert(b);
        }
    }
    if(s.size()==0) {
        cout<<1;
        return 0;
    }
    int i = *(s.begin()); 
        for(auto j:s) {
            //cout<<j;
            if(i==j){i++;}
            else if(j!=i){
                cout<<i;
                return 0;
            }
        
    }
    cout<<i;

}