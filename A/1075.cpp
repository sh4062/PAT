#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int rank;
    int id;
    int flag;
    int isshow;
    int total;
    int s[10];
    int perfect;
    node()
    {
        flag = 0;
        total = 0;
        perfect = 0;
        isshow = 0;
        for (int i = 0; i < 10; i++)
            s[i] = -2;
    }
} A[10010];
int p[10];
bool cmp(node a, node b)
{
    if (a.flag != b.flag)
        return a.flag > b.flag;
    else if (a.total != b.total)
        return a.total > b.total;
    else if (a.perfect != b.perfect)
        return a.perfect > b.perfect;
    else
        return a.id < b.id;
}
int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < m; i++)
    {
        int uid, pid, score;
        scanf("%d%d%d", &uid, &pid, &score);
        A[uid].flag = 1;
        A[uid].id = uid;
        if (score >= 0)
            A[uid].isshow = 1;
        if (A[uid].s[pid] < score)
        {
            if (score != -1)
            {
                if (A[uid].s[pid] == -2 || A[uid].s[pid] == -1)
                    A[uid].total = A[uid].total + score;
                else
                    A[uid].total = A[uid].total - A[uid].s[pid] + score;
            }

            A[uid].s[pid] = score;
            if (score == p[pid])
                A[uid].perfect++;
        }
    }
    sort(A, A + 10010, cmp);
    A[0].rank = 1;
    int count = 1;
    for (int i = 1; i < 10010; i++)
    {
        if (A[i].flag == 0)
            break;
        count++;
        if (A[i].total == A[i - 1].total)
            A[i].rank = A[i - 1].rank;
        else
            A[i].rank = i + 1;
    }
    for (int i = 0; i < count; i++)
    {
        if (A[i].isshow == 0)
            continue;
        printf("%d %05d %d", A[i].rank, A[i].id, A[i].total);
        for (int j = 1; j <= k; j++)
        {
            printf(" ");
            if (A[i].s[j] == -2)
                printf("-");
            else if (A[i].s[j] == -1)
                printf("0");
            else
                printf("%d", A[i].s[j]);
        }
        printf("\n");
    }
    return 0;
}
