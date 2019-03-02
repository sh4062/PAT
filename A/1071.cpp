#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    getline(cin, S);
    string tmp = "";
    map<string, int> mp;
    for (char i : S)
    {
        if (isalnum(i))
        {
            if (isalpha(i))
                i = tolower(i);
            tmp = tmp + i;
        }
        else
        {
            if (mp.find(tmp) == mp.end() && tmp != "")
            {
                mp[tmp] = 1;
            }
            else
            {
                if (tmp != "")
                    mp[tmp]++;
            }
            tmp = "";
        }
    }
    //注意处理最后一个！！！
    if (mp.find(tmp) == mp.end() && tmp != "")
    {
        mp[tmp] = 1;
    }
    else
    {
        if (tmp != "")
            mp[tmp]++;
    }
    tmp = "";
    int max = 0;
    string r = "";
    for (auto i : mp)
    {
        if (i.second == max && r > i.first)
            r = i.first;
        if (i.second > max)
        {
            r = i.first;
            max = i.second;
        }
        //cout << i.first << " " << i.second << endl;
    }
    cout << r << " " << mp[r] << endl;
}