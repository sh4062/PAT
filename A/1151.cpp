/*
 * File: 1151.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 10:07:45 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 10:07:47 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
vector<int> in, pre;
//p_root:先序的根位置
void lca(int l, int r, int p_root, int a, int b)
{
    if (l > r)
        return;
    int root = mp[pre[p_root]], aa = mp[a], bb = mp[b];
    //都在左边
    if (aa < root && bb < root)
    {
        lca(l, root - 1, p_root + 1, a, b);
    }
    //一左一右
    else if ((aa < root && bb > root) || (aa > root && bb < root))
    {
        cout << "LCA of " << a << " and " << b << " is " << in[root]<<".\n";
    }
    //都在右边
    else if (aa > root && bb > root)
    {
        lca(root + 1, r, p_root + 1 + root - l,  a, b);
    }
    else if (aa == root)
    {
        cout << a << " is an ancestor of " << b << ".\n";
    }
    else if (bb == root)
    {
        cout << b << " is an ancestor of " << a << ".\n";
    }
}

int main()
{
    int m, n;
    int a, b;
    cin >> m >> n;
    in.resize(n + 1);
    pre.resize(n + 1);

    for (size_t i = 1; i <= n; i++)
    {
        cin >> in[i];
        mp[in[i]] = i;
    }
    for (size_t i = 1; i <= n; i++)
    {
        cin >> pre[i];
    }

    for (size_t i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (mp[a] == 0 && mp[b] == 0)
        {
            cout << "ERROR: "<<a<<" and "<<b<<" are not found.\n";
        }
        else if (mp[a] == 0 || mp[b] == 0)
        {
            if (mp[a] == 0)
                cout << "ERROR: " << a << " is not found.\n";
            else
                cout << "ERROR: " << b << " is not found.\n";
        }
        else
        {
            lca(1, n, 1, a, b);
        }
    }
}