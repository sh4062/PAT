#include <bits/stdc++.h>
using namespace std;
int G[1300][130][70] = {0};
bool visit[1300][130][70] = {false};
//给定一个三维数组，0表示正常1表示有肿瘤，肿瘤块的大小大于等于t才算作是肿瘤，让计算所有满足肿瘤块的大小
int M, N, L, T;
struct cd
{
    int x;
    int y;
    int z;
};
//精髓啊精髓
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};

bool judge(int x, int y, int z)
{
    if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= L)
        return false;
    if (G[x][y][z] == 0 || visit[x][y][z] == true)
        return false;
    return true;
}
int bfs(int j, int k, int i)
{
    int cnt = 0;
    cd temp = {j, k, i};
    queue<cd> q;
    q.push(temp);
    visit[j][k][i] = true;
    while (!q.empty())
    {
        cd t = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 6; i++)
        {
            int tx = t.x + X[i];
            int ty = t.y + Y[i];
            int tz = t.z + Z[i];
            if (judge(tx, ty, tz))
            {
                visit[tx][ty][tz] = true;
                temp.x = tx, temp.y = ty, temp.z = tz;
                q.push(temp);
            }
        }
    }
    if (cnt >= T)
        return cnt;
    return 0;
}
int main()
{

    cin >> M >> N >> L >> T;
    int res = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                scanf("%d", &G[j][k][i]);
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
            {
                if (visit[j][k][i] == false && G[j][k][i] == 1)
                {
                    res+=bfs(j,k,i);
                }
            }

    cout << res;
}