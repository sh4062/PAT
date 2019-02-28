#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 100000;
struct NODE
{
    int address, key, next, num = 2 * maxn;
} node[maxn];
bool exist[maxn];
int cmp1(NODE a, NODE b)
{
    return a.num < b.num;
}
int main()
{
    int begin, n, cnt1 = 0, cnt2 = 0, a;
    scanf("%d%d", &begin, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        scanf("%d%d", &node[a].key, &node[a].next);
        node[a].address = a; //将所有的点保存。
    }
    for (int i = begin; i != -1; i = node[i].next)
    {
        if (exist[abs(node[i].key)] == false)
        {
            exist[abs(node[i].key)] = true;
            node[i].num = cnt1;
            cnt1++; //通过这个来计数，厉害了啦！解决了链表的顺序问题。
        }
        else
        {
            node[i].num = maxn + cnt2;
            cnt2++; //对重复的计数。
        }
    }
    sort(node, node + maxn, cmp1); //使用sort排序之后，就没有地址下下标的区分了。
    //这样排序之后保证了重复的排在后面，同时也保证了链表的顺序。
    int cnt = cnt1 + cnt2;
    for (int i = 0; i < cnt; i++)
    {
        if (i != cnt1 - 1 && i != cnt - 1)
        { //这两个涵盖的情况是正常链最后一个，和非正常链最后一个
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);
        }
        else
        {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
    }
    return 0;
}
