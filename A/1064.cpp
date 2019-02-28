#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> in;
void inorder(int r)
{
    if (r > N)
        return;
    inorder(2 * r);
    in.push_back(r);
    inorder(2 * r + 1);
}
int main()
{

    cin >> N;
    vector<int> v;
    v.push_back(-1);
    in.push_back(-1);
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    inorder(1);
    vector<int> v2(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        v2[in[i]] = v[i];
    }
    for (int i = 1; i < N; i++)
        cout << v2[i] << " ";
    cout << v2[N];
}