#include <bits/stdc++.h>
using namespace std;
int maxdepth, maxnum;
vector<vector<int>> e;
int n, x;
double p, r;
void dfs(int depth, int u)
{
    if (depth == maxdepth)
        maxnum++;
    if (depth > maxdepth)
    {
        maxnum = 1;
        maxdepth = depth;
    }
    for (int v = 0; v < e[u].size(); v++)
        dfs(depth + 1, e[u][v]);
}

int main()
{
    int n;
    double P, r;
    cin >> n >> P >> r;
    r/=100;
    int root = 0;
    e.resize(n+1);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t == -1)
            root = i;
        else
            e[t].push_back(i);
    }
    dfs(0, root);
    printf("%.2f %d", P * pow(1 + r, maxdepth), maxnum);
}