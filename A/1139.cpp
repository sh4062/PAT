/*
 * File: 1139.cpp
 * Project: A
 * File Created: Saturday, 23rd February 2019 5:37:16 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Saturday, 23rd February 2019 5:37:18 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
// struct p
// {
//     int gender;
//     int code;
// };
int cmp(const pair<int, int> a, const pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}
int main()
{
    int people, relation;
    cin >> people >> relation;
    unordered_map<string, set<string>> ps;
    int q;
    string a, b;
    for (int i = 0; i < relation; i++)
    {
        cin >> a >> b;
        // if (ps.find(a) == ps.end())
        // {   
        //     set<string> as;
        //     as.insert(b);
        //     ps[a] = as;
        // }
        // else
        // {
            ps[a].insert(b);
        // }
        // if (ps.find(b) == ps.end())
        // {
        //     set<string> bs;
        //     bs.insert(b);
        //     ps[b] = bs;
        // }
        // else
        // {
            ps[b].insert(a);
        // }
    }
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        vector<string> afs, bfs;
        for (string i : ps[a])
        {
            if (i.length() == a.length()&&i!=b)
            {
                afs.push_back(i);
            }
        }
        for (string i : ps[b])
        {
            if (i.length() == b.length())
            {
                bfs.push_back(i);
            }
        }
        vector<pair<int, int>> res;
        int cnt = 0;
        for (auto i : afs)
        {
            if ((i == b || i == a))
            {
                continue;
            }
            for (auto j : bfs)
            {
                if ((j == b || j == a))
                {
                    continue;
                }
                if ((ps[i].find(j) != ps[i].end()))
                {
                    cnt++;
                    res.push_back(make_pair(abs(stoi(i)), abs(stoi(j))));
                }
            }
        }
        cout << cnt << '\n';
        sort(res.begin(), res.end(), cmp);
        for (auto i : res)
        {
            //cout<<i.first<<" "<<i.second<<'\n';
            printf("%04d %04d\n", i.first, i.second);
        }
    }
}