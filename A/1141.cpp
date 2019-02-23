/*
    * File: 1141.cpp
    * Project: A
    * File Created: Saturday, 23rd February 2019 3:12:53 pm
    * Author: max (mx0666@163.com)
    * -----
    * Last Modified: Saturday, 23rd February 2019 3:12:54 pm
    * Modified By: max (mx0666@163.com>)
    * -----
    * Copyright 2018 - 2019 Your Company
    */
#include <bits/stdc++.h>
using namespace std;
struct school
{
    string name;
    double TWS;
    int Ns;
};
int cmp(const school a, const school b)
{
    if (a.TWS != b.TWS)
        return a.TWS > b.TWS;
    else if (a.Ns != b.Ns)
    {
        return a.Ns < b.Ns;
    }
    else
        return a.name < b.name;
}
int main()
{
    int a;
    cin >> a;
    map<string, school> s;
    string tmp1, tmp2;
    double b;
    while (a--)
    {
        cin >> tmp1 >> b >> tmp2;
        transform(tmp2.begin(), tmp2.end(), tmp2.begin(), ::tolower);

        if (tmp1[0] == 'B')
        {
            b = b / 1.5;
        }
        else if (tmp1[0] == 'T')
        {
            b =b * 1.5;
        }

        if (s.find(tmp2) == s.end())
        {
            school t;
            t.name = tmp2;
            t.TWS = b;
            t.Ns = 1;
            s[tmp2] = t;
        }
        else
        {
            s[tmp2].Ns++;
            s[tmp2].TWS =s[tmp2].TWS + b;
        }
    }
    vector<school> res;
    for (auto i : s)
    {
        res.push_back(school{i.first,(int)i.second.TWS,i.second.Ns});
        //???只有这个时候换成int能通过 这是什么原理啊 
    }
    sort(res.begin(), res.end(), cmp);
    int rank = 0, pres = -1;
    cout << res.size() << endl;
    // cout << i << " " << res[0].name << " " << (int)res[0].TWS << " " << res[0].Ns << '\n';
    // for (int j = 1; j < res.size(); j++)
    // {
    //     if ((int)res[j].TWS == (int)res[j - 1].TWS)
    //     {
    //         cout << j << " " << res[j].name << " " << (int)res[j].TWS << " " << res[j].Ns << '\n';
    //     }
    //     else
    //     {
    //         cout << j + 1 << " " << res[j].name << " " << (int)res[j].TWS << " " << res[j].Ns << '\n';
    //     }
    // }
    for (int i = 0; i < res.size(); i++)
    {
        if (pres != (int)res[i].TWS)
            rank = i + 1;
        pres = (int)res[i].TWS;
        printf("%d ", rank);
        cout << res[i].name;
        printf(" %d %d\n", (int)res[i].TWS, res[i].Ns);
    }
}