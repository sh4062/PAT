//提供一棵树，在树根处货物的价格为p，从根结点开始每往下一层，该层货物价格将会在父亲结点的价格上增加r%。求叶子结点出能获得的最低价格以及能提供最低价格的叶子结点数
#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int mindepth = INT_MAX;
int minnum = 1;
void dfs(int index, int depth)
{
    if (mindepth < depth)
        return;
    if (v[index].size() == 0)
    {
        if (mindepth == depth)
            minnum++;
        else if (mindepth > depth)
        {
            mindepth = depth;
            minnum = 1;
        }
    }
    for (int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main()
{
    int N, K, C;
    double p, r;
    cin >> N >> p >> r;

    for (int i = 0; i < N; i++)
    {
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> C;
            v[i].push_back(C);
        }
    }
    dfs(0, 0);
    printf("%.4f %d", p * pow(1 + r / 100, mindepth), minnum);
}