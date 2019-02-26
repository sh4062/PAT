/*
 * File: 1050.cpp
 * Project: A
 * File Created: Tuesday, 26th February 2019 11:57:14 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 11:57:16 am
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
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    //set<char> TMP;
    for (int i = 0; i < b.size(); i++)
        //    TMP.insert(b[i]);
        a.erase(std::remove(a.begin(), a.end(), b[i]), a.end());
    cout << a;
    return 0;
}