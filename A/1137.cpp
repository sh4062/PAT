/*
 * File: 1137.cpp
 * Project: A
 * File Created: Sunday, 24th February 2019 9:45:22 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Sunday, 24th February 2019 10:20:39 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;

struct people
{
    string name;
    int gp;
    int gm;
    int gf;
    int g;
};
bool cmp(people a, people b)
{
    return a.g != b.g ? a.g > b.g : a.name < b.name;
}
unordered_map<string, people> ps;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    string as;
    int gi;
    for (int i = 0; i < a; i++)
    {
        cin >> as >> gi;
        if (gi >= 200)
        {
            ps[as] = people{as, gi, -1, -1, 0};
        }
    }
    for (int i = 0; i < b; i++)
    {
        cin >> as >> gi;
        if (ps.find(as) != ps.end())
        {
            ps[as].gm = gi;
        }
    }
    for (int i = 0; i < c; i++)
    {
        cin >> as >> gi;

        if (ps.find(as) != ps.end())
        {
            ps[as].gf = gi;
            if (ps[as].gf > ps[as].gm)
            {
                ps[as].g = ps[as].gf;
            }
            else
            {
                ps[as].g = (double)ps[as].gf * 0.6 + (double)ps[as].gm * 0.4 +0.5> 100 ? 100 : 0.5+(double)ps[as].gf * 0.6 + (double)ps[as].gm * 0.4;
            }
        }
    }

    vector<people> res;
    for (auto i : ps)
    {
        //cout << i.second.gp;
        if (i.second.g >= 60)
        {
            res.push_back(i.second);
        }
    }
    sort(res.begin(), res.end(), cmp);
    for (auto i : res)
    {
        cout << i.name << " " << i.gp << " " << i.gm << " " << i.gf << " " << i.g << endl;
    }
}