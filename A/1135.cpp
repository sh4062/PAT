/*
 * File: 1135.cpp
 * Project: A
 * File Created: Sunday, 24th February 2019 12:28:29 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Sunday, 24th February 2019 12:28:30 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
//主要是建立BST的过程 先序直接建立就行了啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
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
    else if (abs(v) <= abs(root->val))
        root->l = create_tree(root->l, v);
    else
        root->r = create_tree(root->r, v);
    return root;
}
bool isBRT1(Tnode *root) //判断红的节点2个孩子都是黑的
{
    if (root == NULL)
    {
        return true;
    }
    if (root->val < 0)
    {
        if (root->l && root->l->val < 0)
            return false;
        if (root->r && root->r->val < 0)
            return false;
    }
    return isBRT1(root->l) && isBRT1(root->r);
}
int getNum(Tnode *root) //到叶子黑色节点数量
{
    if (root == NULL)
        return 0;
    int ln = getNum(root->l);   
    int rn = getNum(root->r);
    return root->val > 0 ? max(ln, rn) + 1 : max(ln, rn);
}
bool isBRT2(Tnode *root)
{
    if (root == NULL)
        return true;
    int l = getNum(root->l);    
    int r = getNum(root->r);
    if (l != r)
        return false;
    return isBRT2(root->l) && isBRT2(root->r);
}
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        Tnode *r = NULL;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            
            tree.push_back(t);
            r = create_tree(r, tree[i]);
        }
        if (isBRT1(r) && isBRT2(r)&&tree[0]>0)
        {
            
            puts("Yes\n");
        }
        else
        {
            puts("No\n");
        }
        tree.clear();
    }
}