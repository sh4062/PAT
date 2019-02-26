/*
 * File: 1123.cpp
 * Project: A
 * File Created: Tuesday, 26th February 2019 12:00:29 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 1:49:40 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
//这个题好难啊 写出4种旋转
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int var;
    node *l;
    node *r;
};
int isC = 1, aft = 0;

node *ll(node *rn)
{
    node *tmp = rn->r;//tmp->r=rn->r->r;tmp->l=NULL;
    rn->r = tmp->l;//tmp = tmp->l
    tmp->l = rn;//tmp->l = rn
    return tmp;
}

node *rr(node *rn)
{
    node *tmp = rn->l;
    rn->l = tmp->r;
    tmp->r = rn;
    return tmp;
}
node *rl(node *rn)
{       
    rn->r = rr(rn->r);
    return ll(rn);

}
node *lr(node *rn)
{
    rn->l = ll(rn->l);
    return rr(rn);
}
int height(node *rn)
{
    if (rn == nullptr)
        return 0;
    int l = height(rn->l);
    int r = height(rn->r);
    return max(l, r) + 1;
}

node *build(node *root, int val)
{
    if (root == NULL)
    {
        root = new node();
        root->var = val;
        
    }
    else if (root->var > val)
    {
        root->l = build(root->l, val);
        int l = height(root->l), r = height(root->r);
        if (l - r >= 2)
        {
            if (val < root->l->var)
                root = rr(root);
            else
                root = lr(root);
        }
    }
    else
    {
        root->r = build(root->r, val);
        int l = height(root->l), r = height(root->r);
        if (r - l >= 2)
        {
            if (val > root->r->var)
                root = ll(root);
            else
                root = rl(root);
        }
    }
    return root;
}
vector<int> levelorder(node *rn)
{
    vector<int> v;
    queue<node *> queue;
    queue.push(rn);
    while (!queue.empty())
    {
        node *temp = queue.front();
        queue.pop();
        v.push_back(temp->var);
        if (temp->l != NULL)
        {
            if (aft)
                isC = 0;
            queue.push(temp->l);
        }
        else
        {
            aft = 1;
        }
        if (temp->r != NULL)
        {
            if (aft)
                isC = 0;
            queue.push(temp->r);
        }
        else
        {
            aft = 1;
        }
    }
    return v;
}
int main()
{
    int N;
    cin >> N;
    node *root = nullptr;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        root = build(root, t);
    }
    //cout<<height(root)<<root->l->var<<root->r->var;
    vector<int> v = levelorder(root);
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << v[i];
    }
    if (isC)
    {
        cout << "\nYES";
    }
    else
    {
        cout << "\nNO";
    }
}