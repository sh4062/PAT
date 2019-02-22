/*
 * File: 1004.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 9:08:58 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 10:07:21 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */

#include <bits/stdc++.h>
using namespace std;
int maxdepth = -1;
struct TN
{
    int level;
    int k;
    vector<int> child;
    TN(int a, int b, vector<int> c)
    {
        level = a;
        k = b;
        child = c;
    }
};
// void bfs() {
//     queue<int> q;
//     q.push(1);
//     level[1] = 0;
//     while(!q.empty()) {
//         int index = q.front();
//         q.pop();
//         maxlevel = max(level[index], maxlevel);
//         if(v[index].size() == 0)
//             book[level[index]]++;
//         for(int i = 0; i < v[index].size(); i++) {
//             q.push(v[index][i]);
//             level[v[index][i]] = level[index] + 1;
//         }
//     }
// }
set<int> nl;
void dfs(vector<vector<int>> v, int index, int depth, vector<int> &res)
{
    if (nl.find(index)==nl.end())
    {
        res[depth]++;
        maxdepth = max(maxdepth, depth);
        return;
    }
    for (int i = 0; i < v[index].size(); i++){
        
        dfs(v, v[index][i], depth + 1, res);}
}
// int level[100], maxlevel = -1;
// void bfs(vector<TN> v, vector<int> &res)
// {
//     queue<TN> q;
//     q.push(v[0]);
//     level[0] = 0;
//     while (!q.empty())
//     {
        
//         TN p = q.front();
//         q.pop();
//         int index = p.level;
//         maxlevel = max(level[index], maxlevel);
//         if (v[index].k == 0)
//             res[level[index]]++;
//         for (int i = 0; i < v[index].k; i++)
//         {
//             q.push(v[index].child[i]);
//             level[v[index].child[i]] = level[index] + 1;
//         }
//     }
// }

int main()
{
    int numofnode, numofnonleaf;
    cin >> numofnode >> numofnonleaf;
    vector<vector<int>> v(numofnode,vector<int>(numofnode, 0));
    vector<int> res(numofnode);
    int level, k;
    for (int i = 0; i < numofnonleaf; i++)
    {
        cin >> level >> k;
        nl.insert(level);
        vector<int> tmp(k);
        for (int j = 0; j < k; j++)
        {
            cin >> tmp[j];
            
        }
        v[level]=(tmp);
        //TN n(level, k, tmp);
        
    }
    //cout<<"DFS";
    dfs(v, 1, 0, res);
    // bfs(v, res);
    //cout<<(nl.find(2)==nl.end());
    printf("%d", res[0]);
    for (int i = 1; i <= maxdepth; i++)
        printf(" %d", res[i]);
    return 0;
    // for (int i = 1; i <= maxlevel; i++)
    //     printf(" %d", res[i]);
   // return 0;
}
