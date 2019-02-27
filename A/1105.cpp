/*
 * File: 1105.cpp
 * Project: A
 * File Created: Wednesday, 27th February 2019 5:43:00 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 27th February 2019 5:43:02 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int m = 1, n = a;
    for (int i = 1; i <= (int)sqrt((double)a); i++)
    {
        if (a % i == 0)
        {
            if (abs(i - a / i) < abs(m - n))
            {
                m = i;
                n = a / i;
            }
        }
    }
    //cout << m << n;
    vector<int> v;
    for (int i = 0; i < a; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), ::greater<int>());
    int f1 = m, f2 = n, f3 = m, f4 = n;
    int it = 0;
    int maxt[505][505] = {0};
    memset(maxt, -1, sizeof(maxt));
    int x = 0;
    int y = 0;
    while (it != a)
    {

        while (x >= 0 && y >= 0 && x < n && y < m && it != v.size() && maxt[x][y] == -1)
            maxt[x][y++] = v[it++];
        y--;
        x++;
        while (x >= 0 && y >= 0 && x < n && y < m && it != v.size()  && maxt[x][y] == -1)
            maxt[x++][y] = v[it++];
        x--;
        y--;
        while (x >= 0 && y >= 0 && x < n && y < m && it != v.size()  && maxt[x][y] == -1)
            maxt[x][y--] = v[it++];
        y++;
        x--;
        while (x >= 0 && y >= 0 && x < n && y < m && it != v.size()  && maxt[x][y] == -1)
            maxt[x--][y] = v[it++];
        x++;
        y++;
    }
    //cout<<x<<y<<it;
   // maxt[y][x]=v[it];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j != 0)
                printf(" ");
            printf("%d", maxt[i][j]);
        }
        printf("\n");
    }
}