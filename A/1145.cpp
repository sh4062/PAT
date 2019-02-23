/*
 * File: 1145.cpp
 * Project: A
 * File Created: Saturday, 23rd February 2019 12:11:51 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Saturday, 23rd February 2019 12:11:52 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int isPrime(int a)
{
    if (a == 1)
        return 0;
    if (a == 2 || a == 3)
        return 1;
    if (a % 2 == 0)
        return 0;
    if (a % 3 == 0)
        return 0;
    for (int i = 3; i < sqrt(a); i += 2)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int a, b, c,tmp;
    cin >> a >> b >> c;
    if (isPrime(a) == 0)
    {
        for (int i = a;  ;i++)
        {
            if (isPrime(i))
                {a = i;
                break;}
        }
    }
    //cout<<a;
    vector<int> maap(a,-1);
    int m = a/2;
    int res = 0;
    for(int i = 0;i < b;i++) {
        cin>>tmp;
        bool ins = false;
        for(int j = 0;j<a;j++) {
            int k = j*j;
            if(maap[(tmp+k)%a]==-1) {                
                maap[(tmp+k)%a] = tmp;
                ins = true;
                break;
            }
        }
        if(ins == false) {
            cout<<tmp<<" cannot be inserted.\n";
        }
    }
    for(int i = 0;i < c;i++) {
        cin>>tmp;
        bool ins = false;
        for(int j = 0;j<a;j++) {
            res++;
            int k = j*j;
            if(maap[(tmp+k)%a]==-1||maap[(tmp+k)%a]==tmp) {
                ins = true;
                break;
               
            }
        }
        if(ins == false) {
            res++;
        }
    }   
    printf("%.1lf\n", res * 1.0 / c);
}