#include <bits/stdc++.h>
using namespace std;
struct node
{
    int var;
    int l;
    int r;
};
vector<node> v;
vector<int> v1;
vector<int> v2;
vector<int> v3;
void inorder(node r)
{

    if (r.l != -1)
        inorder(v[r.l]);
    v2.push_back(r.var);
    if (r.r != -1)
        inorder(v[r.r]);
}
void bfs(node r)
{
   // cout<<"!!!!!"<<endl;
    queue<node> q;
    q.push(r);
    //cout<<r.var<<endl;
    while (!q.empty())
    {
        node t = q.front();
        //cout<<t.var;
        v3.push_back(t.var);
        q.pop();
        if (t.l != -1)
            q.push(v[t.l]);

        if (t.r != -1)
            q.push(v[t.r]);
    }
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        v.push_back(node{i, l, r});
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v1.push_back(t);
    }
    inorder(v[0]);
    sort(v1.begin(), v1.end());
    for (int i = 0; i < n; i++)
    {
        v[v2[i]].var = v1[i];
        //cout<<v1[i];
    }
    //cout<<v[0].var<<endl;
    bfs(v[0]);
    for(int i = 0; i < n-1; i++){
        cout<<v3[i]<<" ";
    }
     cout<<v3[n-1];
}