/*
 * File: 1112.cpp
 * Project: A
 * File Created: Wednesday, 27th February 2019 9:34:46 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 27th February 2019 10:01:55 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    string s;
    cin >> k >> s;
    map<char, bool> m;
    set<char> out;
    char pre = '#';
    int cnt = 1;
    s = s + '#';
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == pre)
        {
            cnt++;
        }
        else
        {
            if (cnt % k == 0)
            {
                if(m.find(pre)==m.end())
                m[pre] = true;

                //cout<<s[i]<<endl;
            }else {
               
                m[pre] = false;
                // cout<<m[pre]<<cnt;
            }

            cnt = 1;
            pre = s[i];
        }
    }
    for (int i = 0; i < s.length(); i++)
    {

        if (m[s[i]] == true && out.find(s[i]) == out.end())
        {

            cout << s[i];
            out.insert(s[i]);
        }
    }
    cout << endl;
    for (int i = 0; i < s.length()&&s[i]!='#'; i++)
    {
        if (out.find(s[i]) != out.end())
        {
            cout<<s[i];
            i = i + k - 1;
        }
        else
        {
            cout << s[i];
        }
    }
}