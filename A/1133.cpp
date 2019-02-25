/*
 * File: 1133.cpp
 * Project: A
 * File Created: Sunday, 24th February 2019 5:28:21 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Sunday, 24th February 2019 5:28:24 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int add;
    int data;
    int next_add;
};
vector<node> v;
vector<node> vv;
vector<node> m0;
vector<node> k0;
map<int, node> order;
int main()
{
    int start;
    int n, k;
    cin >> start >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int add;
        int data;
        int next_add;
        cin >> add >> data >> next_add;
        v.push_back(node{add, data, next_add});
        order[add] = v[i];
    }
    int s = start;
    while (1)
    {
        if (order[s].next_add == -1)
        {
            vv.push_back(order[s]);
            break;
        }
        vv.push_back(order[s]);
        s = order[s].next_add;
    }
    int i = 0;
    for (; i < vv.size(); i++)
    {
        if (vv[i].data < 0)
        {
            m0.push_back(vv[i]);
        }
    }
    i = 0;
    for (; i < vv.size(); i++)
    {
        if (vv[i].data >= 0 && vv[i].data <= k)
        {
            m0.push_back(vv[i]);
        }
    }
    i = 0;
    for (; i < vv.size(); i++)
    {
        if (vv[i].data > k)
        {
            m0.push_back(vv[i]);
        }
    }
    for (int it = 0; it < vv.size() - 1; it++)
    {
        printf("%05d %d %05d\n", m0[it].add, m0[it].data, m0[it + 1].add);
    }
    printf("%05d %d %d", m0[vv.size() - 1].add, m0[vv.size() - 1].data, -1);
}