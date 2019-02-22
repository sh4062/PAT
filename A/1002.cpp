/*
 * File: 1002.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 8:02:25 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 8:02:26 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Outer Heaven
 */
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1002;
int main()
{
    double a[maxn] = {0}, b[maxn] = {0};
    int t1;
    double n1, n2, t2;
    cin >> n1;
    while (n1--)
    {
        cin >> t1 >> t2;
        a[t1] = t2;
    }
    cin >> n2;
    while (n2--)
    {
        cin >> t1 >> t2;
        b[t1] = t2;
    }
    double res[maxn] = {0};
    for (int i = 0; i <= 1001; i++)
    {
        res[i] = a[i] + b[i];
    }
    int tt = 1001, count = 0;
    for (tt; tt >= 0; tt--)
    {

        if (res[tt] != 0)
        {
            count++;
        }
    }
    printf("%d", count);
    tt = 1001;
    for (tt; tt >= 0; tt--)
    {

        if (res[tt] != 0)
        {
            printf(" %d %.1f", tt, res[tt]);
        }
    }
}
