/*
 * File: 1070.cpp
 * Project: A
 * File Created: Sunday, 24th February 2019 10:12:29 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Sunday, 24th February 2019 10:12:30 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1005;
struct m
{
    double store;
    double price;
};
m t[1001];
bool cmp(m a, m b)
{
    return a.price > b.price;
}

int main()
{
    double kc[maxn];
    int k;
    double d, s, p;
    cin >> k >> d;
    //vector<m> t;

    for (int i = 0; i < k; i++)
    {
        cin >> t[i].store;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> p;
        t[i].price = p / t[i].store;
    }
    double res = 0;
    sort(t, t + k, cmp);
    //for(int i = 0;i<k;i++){cout<<t[i].price;}
    int i = 0;
    for (i = 0; i < k; i++)
    {
        if (t[i].store <= d)
        {
            d = d - t[i].store;
            res = res + t[i].store * t[i].price;
        }
        else
            break;
    }
    res = res + t[i].price * d;
    printf("%.2f", res);
}
