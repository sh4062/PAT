#include <bits/stdc++.h>
using namespace std;
//这题可真牛逼 a+b<b+a
int cmp(const string &a, const string &b)
{
    if (a + b < b + a)
    {
        return 1;
    }
    return 0;
}
vector<string> v;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string b;
        cin >> b;
        v.push_back(b);
    }
    sort(v.begin(), v.end(), cmp);
    string res = "";
    for (int i = 0; i < n; i++)
    {
        res = res + v[i];
    }
    int i = 0;
    for (; i < res.size(); i++)
    {
        if (res[i] != '0')
            break;
    }
    
    if (i-1 == res.size() - 1)
    {
        cout << 0;
        
    }
    else
    {
        for (; i < res.size(); i++)
        {
            cout << res[i];
        }
    }
}