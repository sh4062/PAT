/*
 * File: 1118.cpp
 * Project: A
 * File Created: Tuesday, 26th February 2019 4:06:13 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 4:06:22 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int fa[maxn] = {0}, cnt[maxn] = {0};
bool exist[maxn] = {0};
int Find(int a)
{
    int z = a;
    //寻找
    while (fa[a] != a)
    {
        a = fa[a];
    }
    //路径压缩
    while (z != fa[z])
    {
        int zz = z;
        fa[zz] = a;
        z = fa[z];
    }
    return a;
}
int Union(int a, int b)
{
    int fa_ = Find(a);
    int fb_ = Find(b);
    if (fa_ != fb_)
        fa[fa_] = fb_;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    for (int i = 1; i <= maxn; i++)
        fa[i] = i;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        exist[b] = true;
        for (int j = 0; j < a - 1; j++)
        {
            int t;
            cin >> t;
            Union(b, t);
            exist[t] = true;
        }
    }
    for (int i = 1; i <= maxn; i++)
    {
        if (exist[i] == true)
        {
            int root = Find(i);
            cnt[root]++;
        }
    }
    int numTrees = 0, numBirds = 0;
    for (int i = 1; i <= maxn; i++)
    {
        if (exist[i] == true && cnt[i] != 0)
        {
            numTrees++;
            numBirds += cnt[i];
        }
    }
    printf("%d %d\n", numTrees, numBirds);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int q1, q2;
        cin >> q1 >> q2;
        printf("%s\n", (Find(q1) == Find(q2)) ? "Yes" : "No");
    }
}