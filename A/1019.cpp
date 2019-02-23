/*
 * File: 1019.cpp
 * Project: A
 * File Created: Saturday, 23rd February 2019 4:37:53 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Saturday, 23rd February 2019 4:37:54 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, b;
    cin >> a >> b;
    string res;
    vector<int> out;
    if (a == 0)
    { //如果是0的话，不论什么进制都是回文数字
        puts("Yes");
        printf("0\n");
        return 0;
    }
    long long t = a;
    while (t)
    {
        long long tt = t % b;

        out.push_back(tt);
        res = to_string(tt) + res;
        t = t / b;
    }
    for (int i = 0, j = out.size() - 1; i < j;)
    {
        if (out[i] == out[j])
        {
            i++;
            j--;
            continue;
        }
        else
        {

            cout << "No" << '\n';
            cout << out[out.size() - 1];
            for (int i = out.size() - 2; i >= 0; i--)
            {
                cout << " " << out[i];
            }
            return 0;
        }
    }
    cout << "Yes" << '\n';
    cout << out[out.size() - 1];
    for (int i = out.size() - 2; i >= 0; i--)
    {
        cout << " " << out[i];
    }
    return 0;
}