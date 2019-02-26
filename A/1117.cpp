/*
 * File: 1117.cpp
 * Project: A
 * File Created: Tuesday, 26th February 2019 4:06:18 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 4:06:25 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int N;
    cin >> N;
    vector<int> v;
    unordered_map<int, int> m;
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
        // s.insert(t);
        // if (m.find(t) == m.end())
        // {
        //     m[t] = 1;
        // }
        // else
        // {
        //     m[t]++;
        // }
    }
    // int res = 0;
    // int ma = 0;
    // for (res = 0; res <= N; res++)
    // {
    //     int cnt = 0;

    //     for (auto i : m)
    //     {
    //         if (i.first > res)
    //         {
    //             //cout<<i.first<<" "<<i.second;
    //             cnt += i.second;
    //         }
    //     }
    //     if (cnt >= res && ma < res)
    //     {
    //         ma = res;
    //         //cout<<ma<<endl;
    //     }
    // }
    // cout << ma;
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (i + 1 < v[i])//i+1是天数 v[i]是运动量
        {
            ans = i + 1;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
}