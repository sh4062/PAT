/*
 * File: 1009.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 11:20:00 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 11:20:01 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
const int maxn = 1111;
int main()
{
    double a[1001] = {0}, b[1001] = {0};
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
    double res[2005] = {0};
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {

            res[i + j] = res[i + j] + a[i] * b[j];
        }
    }
    int tt = 2004, count = 0;
    for (tt; tt >= 0; tt--)
    {

        if (res[tt] != 0)
        {
            count++;
        }
    }
    printf("%d", count);
    tt = 2004;
    for (tt; tt >= 0; tt--)
    {

        if (res[tt] != 0)
        {
            printf(" %d %.1f", tt, res[tt]);
        }
    }
}
