#include <bits/stdc++.h>
using namespace std;
struct p
{
    string n;
    string c;
    int s;
};
int cmp(const p &a, const p &b)
{
    return a.s < b.s;
}
int main()
{
    int N;
    cin >> N;
    vector<p> v;
    for (int i = 0; i < N; i++)
    {
        string a, b;
        int c;
        cin >> a >> b >> c;
        v.push_back(p{a, b, c});
    }
    sort(v.begin(), v.end(), cmp);
    int q1, q2;
    cin >> q1 >> q2;
    int flag = 1;
    for (int i = N-1; i >=0; i--)
    {
        if (v[i].s >= q1 && v[i].s <= q2)
        {
            flag = 0;
            cout << v[i].n << " " << v[i].c << endl;
        }
    }

    //cout << i1 << i2 << endl;

    if (flag)
    {
        cout << "NONE\n";
    }
}