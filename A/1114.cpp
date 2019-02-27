/*
 * File: 1114.cpp
 * Project: A
 * File Created: Wednesday, 27th February 2019 7:58:21 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 27th February 2019 8:00:48 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int fa[10001];
int ex[10001] = {0};
int Find(int a)
{
    int x = a;
    while (fa[a] != a)
    {
        a = fa[a];
    }
    while (fa[x] != x)
    {
        int z = x;
        fa[z] = a;
        x = fa[x];
    }
    return a;
}
int Union(int a, int b)
{
    int aa = Find(a);
    int bb = Find(b);
    if (aa != bb)
        fa[aa] = bb;
}
int nums[10001] = {0};
int areas[10001] = {0};
struct re
{
    int maxid;
    int numid;
    double s;
    double a;
};
int cmp(re a,re b){
    if(a.s/a.numid!=b.s/b.numid)return a.s/a.numid>b.s/b.numid;
    else return a.maxid<b.maxid;
}
int main()
{
    for (int i = 0; i < 10001; i++)
    {
        fa[i] = i;
    }
    int N;
    cin >> N;
    int fn = 0, fid, M, avgs, avga;
    int id, p1, p2, kn, kid, se, area;
    for (int i = 0; i < N; i++)
    {
        cin >> id >> p1 >> p2 >> kn;
        ex[id] = 1;
        if (p1 != -1)
        {
            ex[p1] = 1;
            Union(id, p1);
        }
        if (p2 != -1)
        {
            Union(id, p2);
            ex[p2] = 1;
        }
        for (int j = 0; j < kn; j++)
        {
            cin >> kid;
            Union(id, kid);
            ex[kid] = 1;
        }
        cin >> se >> area;
        nums[id] += se;
        areas[id] += area;
    }
    unordered_map<int, set<int>> mp;
    for (int i = 0; i < 10001; i++)
    {
        if (fa[i] == i && ex[i] == 1)
        {
            fn++;
            mp[i].insert(i);
        }
    }
    cout << fn << endl;
    for (int i = 0; i < 10001; i++)
    {
        if (fa[i] != i && ex[i] == 1)
        {
            //cout<<i<<endl;
            mp[Find(i)].insert(i);
        }
    }
    vector<set<int >> res;
    for (auto i : mp)
    {
        res.push_back(i.second);
    }
    vector<re> ress;
    for (auto i : res)
        ress.push_back(re{*(i.begin()), (int)i.size(), 0, 0});
    for (int i = 0; i < fn; i++)
    {
        for (auto j : res[i])
        {
            if (nums[j] != 0)
            {
                ress[i].a += nums[j];
                ress[i].s += areas[j];
            }
        }
    }
    sort(ress.begin(),ress.end(),cmp);
    for(auto i :ress){
        cout<<setfill('0')<<setw(4)<<i.maxid;
        cout<<" "<<i.numid<<" ";
        cout<<fixed<<setprecision(3)<<i.a/i.numid;
        cout<<" ";
        cout<<fixed<<setprecision(3)<<i.s/i.numid;
        cout<<endl;
    }
}