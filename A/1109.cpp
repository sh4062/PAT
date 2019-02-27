#include <bits/stdc++.h>
using namespace std;
struct p
{
    string name;
    int h;
};
bool cmp(p a, p b)
{
    if (a.h != b.h)
        return a.h > b.h;
    return a.name < b.name;
}
int main()
{
    int N, r;
    cin >> N >> r;
    int per_line = N / r;
    int last_line = per_line + (N - r * per_line);
    vector<p> v;
    for (int i = 0; i < N; i++)
    {
        string a;
        int b;
        cin >> a >> b;
        v.push_back(p{a, b});
    }
    sort(v.begin(), v.end(), cmp);
    int it = 0; //当前正在排序的人
    for (int i = 0; i < r; i++)
    {
        int this_line = i == 0 ? last_line : per_line; //这一行有多少人
        int pos_it = this_line / 2;                    //中间位置的下标
        vector<string> ans(N);                         //存储这一行的容器
        int direct = -1;
        while (pos_it >= 0 && pos_it < this_line)
        {
            ans[pos_it] = v[it].name;
            it++;
            pos_it += direct;
            if (direct < 0)
            {
                direct *= -1;
                direct++;
            }
            else
            {
                direct *= -1;
                direct--;
            }
        }
        for (int j = 0; j < this_line; j++)
        {
            cout << ans[j];
            if (j != this_line - 1)
                cout << ' ';
        }
        ans.clear();
        cout << endl;
    }
    return 0;
}