/*
 * File: 1093.cpp
 * Project: A
 * File Created: Saturday, 23rd February 2019 12:00:02 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Saturday, 23rd February 2019 12:00:09 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{   
    string s;
    cin>>s;
    int l = s.length();
    int count_T = 0;
    int count_A = 0;
    int count_P = 0;
    
    for(int i = s.length()-1; i >= 0; i--)
    {
        if(s[i]=='T'){
            count_T++;
        }
        else if(s[i] =='A'){
            count_A+=count_T;
            count_A = count_A%1000000007;
        }
        else if(s[i] =='P'){
            count_P+=count_A;
            count_P = count_P%1000000007;
        }
    }
    cout<<count_P%1000000007;
}