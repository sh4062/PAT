/*
 * File: 1115.cpp
 * Project: A
 * File Created: Wednesday, 27th February 2019 9:33:47 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 27th February 2019 9:34:17 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
struct Tnode
{
    int val;
    struct Tnode *l;
    struct Tnode *r;
};
vector<int> tree;
Tnode *create_tree(Tnode *root, int v)
{
    if (root == NULL)
    {

        root = new Tnode();
        root->val = v;
        root->l = root->r = NULL;
    }
    else if ((v) <= (root->val))
        root->l = create_tree(root->l, v);
    else
        root->r = create_tree(root->r, v);
    return root;
}
vector<int> res;
int tra(Tnode *r)
{
    queue<Tnode*>q;
    q.push(r);
    int w = 0;
    while(1){
        w = q.size();
        res.push_back(w);
        if(w==0)
        break;
        while(w>0){
            Tnode * p = q.front();
            q.pop();
            if(p->l)q.push(p->l);
            if(p->r)q.push(p->r);
            w--;
        }
    }
}
int main()
{
    int q;
    cin>>q;
    Tnode *root = nullptr;
    while (q--)
    {
        int t;
        cin >> t;
        root = create_tree(root, t);
    }
    tra(root);
    cout<<*(res.end()-2)<<" + ";
    cout<<*(res.end()-3)<<" = ";
    cout<<*(res.end()-2)+*(res.end()-3);

}