/*
 * File: 1129.cpp
 * Project: A
 * File Created: Monday, 25th February 2019 11:21:41 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Monday, 25th February 2019 3:20:45 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}
struct node
{
    int key, value;
    bool operator<(const node &a) const
    {
        return (value != a.value) ? value > a.value : key < a.key;
    }
};
int cnt[50001] = {0};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    set<node> ss;
    int n, s;
    cin >> n >> s;
    unordered_map<int, int> maps;
    int t;
    cin >> t;
    //vector<int> res;
    cnt[t] = 1;
    ss.insert(node{t, 1});
    for (int i = 1; i < n; i++)
    {
        int tt;
        cin >> tt;

        cout << tt << ": ";
        //vector<pair<int, int>> res(maps.begin(), maps.end());
        //sort(res.begin(), res.end(), cmp);
        auto it = ss.begin();
        for (int j = 0; j < ss.size() && j < s; j++)
        {
            cout << (*it).key;
            it++;
            if (j == ss.size() - 1 || j == s - 1)
            {
                cout << '\n';
            }
            else
            {
                cout << " ";
            }
        }
        auto its = ss.find(node{tt, cnt[tt]});
        if (its != ss.end())
            ss.erase(its);
        cnt[tt]++;
        ss.insert(node{tt, cnt[tt]});
    }
}