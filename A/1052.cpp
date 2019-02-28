#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int now;
    int data;
    int next;
};
vector<Node> l;
Node org[10010];
int n, h;

bool cmp(Node n1, Node n2)
{
    return n1.data < n2.data;
}

int main()
{
    scanf("%d%d", &n, &h);
    Node t;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &t.now, &t.data, &t.next);
        org[t.now].now = t.now;
        org[t.now].data = t.data;
        org[t.now].next = t.next;
    }

    while (h != -1)
    {
        l.push_back(org[h]);
        h = org[h].next;
    }

    if (l.size() == 0)
    {
        printf("0 -1\n");
        return 0;
    }

    sort(l.begin(), l.end(), cmp);

    printf("%d %05d\n", l.size(), l[0].now);
    for (int i = 0; i < l.size() - 1; i++)
    {
        printf("%05d %d %05d\n", l[i].now, l[i].data, l[i + 1].now);
    }
    printf("%05d %d -1\n", l[l.size() - 1].now, l[l.size() - 1].data);

    return 0;
}
