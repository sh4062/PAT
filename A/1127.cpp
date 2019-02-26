/*
 * File: 1127.cpp
 * Project: A
 * File Created: Tuesday, 26th February 2019 10:08:51 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 26th February 2019 10:17:26 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int var;
    struct node *l;
    struct node *r;
};
vector<int> res;
int flag = 1;
node *build_tree(vector<int> &in, int ins, int ine, vector<int> &post, int posts, int poste)
{
    if (ins > ine || posts > poste)
        return nullptr;
    //根节点t
    node *r = new node(node{post[poste], nullptr, nullptr});
    //cout<<r->var<<endl;
    //中序寻找左右子树
    vector<int>::iterator iter = find(in.begin() + ins, in.begin() + ine, post[poste]);
    int index = iter - in.begin(); //根节点的位置
    r->l = build_tree(in, ins, index - 1, post, posts, posts + index - 1 - ins);
    r->r = build_tree(in, index + 1, ine, post, posts + index - ins, poste - 1);
    return r;
}
void tra(node *r)
{
    int flag = 1;
    //deque<int> q;
    deque<node *> qq;
    qq.push_back(r);
    int wid = qq.size();
    int level = -1;
    while (1)
    {

        wid = qq.size();
        if (level % 2 == 0)
        {
            for (auto i : qq)
                res.push_back(i->var);
        }
        else
        {
            for (auto i = qq.end() - 1; i >= qq.begin(); i--)
                res.push_back((*i)->var);
        }
        if (wid == 0)
            break;
        level++;
        //cout << level << endl;
        while (wid > 0)
        {
            node *p = qq.front();

            qq.pop_front();
            wid--;
            if (p->l)
            {
                qq.push_back(p->l);
            }
            if (p->r)
            {
                qq.push_back(p->r);
            }
        }
    }
}
int main()
{
    int N;
    cin >> N;
    vector<int> post;
    vector<int> in;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        in.push_back(t);
    }
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        post.push_back(t);
    }
    //cout<<post[N-1];
    node *root = build_tree(in, 0, in.size() - 1, post, 0, post.size() - 1);
    //cout<<root->var<<endl;
    tra(root);
    int count = 0;
    for (auto i : res)
    {
        if (count == res.size() - 1)
        {
            break;
        }
        count++;

        cout << i << " ";
    }
    cout << res[N-1];
}