/*
 * File: 1079.cpp
 * Project: B
 * File Created: Friday, 22nd February 2019 12:19:23 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 12:19:27 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
string sum_s(string a,string b,string & sum){
    int flag = 0;
    for(int i = a.length()-1;i>=0;i--){
        if(a[i]-'0'+b[i]-'0' + flag>= 10){
            sum = char('0' +( a[i]-'0'+b[i]-'0' + flag)%10)+sum;
            flag = 1;
        }else{
            sum = char('0' +( a[i]-'0'+b[i]-'0' + flag))+sum;
            flag= 0;    
        }

    }
    if(flag){
        sum = '1'+sum;
    }
    return sum;
}
int isP(string a){
    string aa = a;
    reverse(a.begin(),a.end());
    if(aa == a)return 1;
    return 0;
}
int main()
{
    string a;
    cin >> a;
    int cnt = 10;
    string b,sum,temp; 
    if(isP(a)) {
            cout<<a<<" is a palindromic number.\n";
            return 0;
        }
    while(cnt--){
        int len = a.size();
        b = a;
        reverse(b.begin(),b.end());

        cout <<a<<" + "  <<b;
        cout <<" = "<<sum_s(a,b,sum)<<endl;
        if(isP(sum)) {
            cout<<sum<<" is a palindromic number.\n";
            return 0;
        }
        a = sum;
        sum="";
        
        
    }
    cout<<sum<<"Not found in 10 iterations.\n";
}