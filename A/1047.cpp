#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int N, K;
    cin >> N >> K;
    //unordered_map<int, vector<string>> mp;
    vector<vector<string>>mp(3000);
    while (N--)
    {
        string name;
        int n;
        cin >> name >> n;
        while (n--)
        {
            int t;
            cin >> t;
            mp[t].push_back(name);
        }
    }
    for (int i = 1; i <= K; i++)
    {
        //cout << i << " " << mp[i].size()<<endl;
        printf("%d %d\n",i,mp[i].size() );
        sort(mp[i].begin(),mp[i].end());
        for (auto j : mp[i])
        {
            printf("%s\n",j.c_str());
            //cout << j << endl;
        }
    }
}
