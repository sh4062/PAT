#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int p, c;
    cin >> p >> c;
    unordered_map<string, set<int>> mp;

    for (int i = 0; i < c; i++)
    {
        int id, num;
        cin >> id >> num;
        for (int ii = 0; ii < num; ii++)
        {
            string tmp;
            cin >> tmp;
            mp[tmp].insert(id);
        }
    }
    for (int i = 0; i < p; i++)
    {
        string tmp;
        cin >> tmp;
        cout << tmp << " " << mp[tmp].size();
        for (auto j : mp[tmp])
        {
            cout << " " << j;
        }
        cout << endl;
    }
}