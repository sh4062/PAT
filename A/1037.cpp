#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, Q;
    cin >> N;
    vector<int> v1, v2;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        v1.push_back(t);
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int t;
        cin >> t;
        v2.push_back(t);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int v10 = 0, v20 = 0;
    auto v100 = upper_bound(v1.begin(), v1.end(), 0);
    v10 = v100 - v1.begin();
    auto v200 = upper_bound(v2.begin(), v2.end(), 0);
    v20 = v200 - v2.begin();
    //cout<<v10<<v20;
    int res = 0;
    int cnt = 0;
    auto j = v2.end() - 1;
    for (auto i = v1.end() - 1; i != v100 - 1; i--)
    {
        if (j == v200 - 1)
            break;
        if (cnt == N)
            break;

        cnt++;
        //cout<<res;
        res += (*(i)) * (*(j));
        j--;
    }
    //cout << res << endl;
    j = v2.begin();
    for (auto i = v1.begin(); i != v100; i++)
    {
        if (j == v200)
            break;
        if (cnt == N)
            break;

        cnt++;
        //cout << res;
        res += (*(i)) * (*(j));
        j++;
    }
    if (res >= 0)
        cout << res;
    else
        cout << 0;
}