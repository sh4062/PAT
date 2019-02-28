#include <bits/stdc++.h>
using namespace std;
struct node
{
    int var;
    node *l;
    node *r;
};

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
int main(){
    int N;
    cin>>N;
    node * root = NULL;
    for(int i = 0; i < N; i++)
    {
        int t;
        cin>>t;
        root = build(root,t);
    }
    cout<<root->var;
    
}