/*
 * File: 1008.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 11:18:04 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 11:18:09 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >>n;
    vector<int> v(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int res = 0;
    res += 6 * v[0];
    res += n * 5;
    int i = 0, j = 1;
    while (j < n)
    {
        if (v[i] >= v[j])
        {
            res += 4 * (v[i] - v[j]);
        }
        else if (v[i] < v[j])
        {
            res += 6 * (v[j] - v[i]);
        }
        i++;
        j++;
    }
    cout << res;
}
