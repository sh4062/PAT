#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
vector<string> name; // 人名
map<string, int> idcache;
int N, K;
int e[MAXN][MAXN], w[MAXN];
bool vis[MAXN];
int ID(string x)
{
    if (idcache.count(x))
        return idcache[x];
    name.push_back(x);
    return idcache[x] = name.size() - 1;
}
void dfs(int s, int &head, int &num, int &totalw)
{
    vis[s] = true;
    num++;
    if (w[s] > w[head])
        head = s;
    for (int v = 0; v < name.size(); ++v)
    {
        if (e[s][v])
        {
            totalw += e[s][v];
            e[s][v] = e[v][s] = 0;
            if (vis[v] == false)
                dfs(v, head, num, totalw);
        }
    }
}
int main()
{

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        string A, B;
        int t;
        cin >> A >> B >> t;
        int a = ID(A);
        int b = ID(B);
        e[a][b] += t;
        e[b][a] += t;
        w[a] += t;
        w[b] += t;
    }

    map<string, int> ret;
    for (int i = 0; i < name.size(); ++i)
    {
        if (vis[i] == false)
        {
            int head = i, totalw = 0, num = 0;
            dfs(i, head, num, totalw);
            if (num > 2 && totalw > K)
                ret[name[head]] = num;
        }
    }
    cout << ret.size() << endl;
    for (auto it : ret)
        cout << it.first << " " << it.second << '\n';
}