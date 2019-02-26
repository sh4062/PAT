#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    int m = N / 2;
    cout << abs(N - 2 * m) <<" ";
    sort(v.begin(), v.end());
    if (N % 2 == 0)
    {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < m; i++)
        {
            s1 += v[i];
        }
        for (int i = m; i < N; i++)
        {
            s2 += v[i];
            //cout<<s2;
        }
        cout << abs(s1 - s2);
    }
    else
    {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < m; i++)
        {
            s1 += v[i];
        }
        for (int i = m + 1; i < N; i++)
        {
            s2 += v[i];
            //cout<<s2;
        }
        cout << abs(s1 - s2)+v[m];
    }
}