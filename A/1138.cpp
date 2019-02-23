/*
 * File: 1138.cpp
 * Project: A
 * File Created: Saturday, 23rd February 2019 9:40:06 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Saturday, 23rd February 2019 9:41:01 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int res;
vector<int> pre(50001), in(50001),post;
map<int, int> mp;

void findT(int pos1, int pos2, int n)
{

    if (n == 1)//只有一个根了
    {
        post.push_back(pre[pos1]);
        
        return;
    }
    if (n == 0)
        return;

    int i = 0;
    for (; ; i++)
        if(pre[pos1] == in[pos2 + i])break;

    findT(pos1 + 1, pos2, i);//左 i是左边长度
    findT(pos1 + i + 1, pos2 + i + 1, n - i - 1);//右
    post.push_back( pre[pos1]);
}
int main()
{
    int m;
    cin >> m;
    pre.resize(m);
    in.resize(m);

    for (int i = 0; i < m; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> in[i];
        mp[in[i]] = i;
    }
    if (m == 1)
    {
        cout << pre[0];
        return 0;
    }
    int root = pre[0];
    int pos1 = 0, pos2 = 0;
    pos2 = mp[root];
    findT(0,0,m);
    cout<<post[0];
}