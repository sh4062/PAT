/*
 * File: 1116.cpp
 * Project: A
 * File Created: Sunday, 24th February 2019 11:52:06 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Sunday, 24th February 2019 11:52:07 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int isPrime(int a)
{
    if (a == 1)
        return 0;
    if (a == 2 || a == 3)
        return 1;
    if (a % 2 == 0)
        return 0;
    if (a % 3 == 0)
        return 0;
    for (int i = 3; i <=(int)sqrt(double((a))); i += 2)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int a, q;
    cin >> a;
    unordered_map<string, int> r;
    int rr = 1;
    string t;
    for (int i = 0; i < a; i++)
    {
        cin >> t;
        r[t] = rr;
        rr++;
    }
    cin >> q;
    while (q--)
    {
        string tt;
        cin >> tt;
        if (r.count(tt) != 0)
        {
            if (r[tt] == -1)
            {
                cout << tt << ": Checked\n";
            }
            else if (r[tt] == 1)
            {
                cout << tt << ": Mystery Award\n";
                r[tt] = -1;
            }
            else if (isPrime(r[tt]))
            {
                cout << tt << ": Minion\n";
                r[tt] = -1;
            }

            else
            {
                cout << tt << ": Chocolate\n";
                r[tt] = -1;
            }
        }
        else
        {
            cout << tt << ": Are you kidding?\n";
        }
    }
}