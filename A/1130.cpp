/*
 * File: 1130.cpp
 * Project: A
 * File Created: Monday, 25th February 2019 10:11:00 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Monday, 25th February 2019 10:11:02 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;

struct node
{
    string var;
    int ll;
    int rr;
    struct node *l;
    struct node *r;
};
int n;
int roo = 0;
vector<node> v(21);
void inorder(node *r, int &res)
{
    if (r == nullptr)
        return;
    inorder(r->l, res);
    res = res+1;

    inorder(r->r, res);
}
void inorder2(node *r)
{
    if (r == nullptr)
        return;
    if(r!=&v[roo]&&(r->l||r->r)){cout<<"(";}
    inorder2(r->l);
    //res = res + r->var;
    cout<<r->var;
    inorder2(r->r);
    if(r!=&v[roo]&&(r->l||r->r)){cout<<")";}
}
int main()
{
    cin >> n;
    v.resize(n + 1);
    string in;
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        cin >> in >> l >> r;
        v[i] = node{in, l, r, nullptr, nullptr};
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i].ll != -1)
        {
            v[i].l = &v[v[i].ll];
        }
        if (v[i].rr != -1)
        {
            v[i].r = &v[v[i].rr];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        inorder(&v[i], res);
        if (res == n)
        {
            //cout<<res<<endl;
            roo = i;
            break;
        }
    }
    inorder2(&v[roo]);
    
}