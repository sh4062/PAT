/*
 * File: 1035.cpp
 * Project: A
 * File Created: Wednesday, 27th February 2019 10:50:19 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 27th February 2019 10:50:20 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
struct p
{
    string id;
    string pw;
};
int judge(string &s)
{
    int flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            s[i] = '%';
            flag = 1;
        }
        else if (s[i] == '1')
        {
            s[i] = '@';
            flag = 1;
        }
        else if (s[i] == 'l')
        {
            s[i] = 'L';
            flag = 1;
        }
        else if (s[i] == 'O')
        {
            s[i] = 'o';
            flag = 1;
        }
    }
    return flag;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string a, b;
    cin >> n;
    queue<p> res;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (judge(b) == 1)
        {
            cnt++;
            res.push(p{a, b});
        }
    }
    if (cnt == 0)
    {
        if (n == 1)
            printf("There is 1 account and no account is modified");
        else if (n != 1)
            printf("There are %d accounts and no account is modified", n);
    }

    else
    {
        cout << cnt << '\n';
        while (!res.empty())
        {
            cout << res.front().id << " " << res.front().pw << endl;
            res.pop();
        }
    }
}