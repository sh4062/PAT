/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1001.cpp
*   Creator    ：Max
*   Date       ：2019/02/20
*   Description：
*
================================================================*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    long a, b, c;
    cin >> a >> b;
    c = a + b;
    if (c < 0)
    {
        cout << '-';
        c = c * (-1);
    }

    if (c >= 1000000)
    {
        cout << c / 1000000;
        cout << ',';
        c = c % 1000000;
        cout << setfill('0') << setw(3) << c / 1000;
        cout << ',';
        c = c % 1000;
        cout << setfill('0') << setw(3) << c ;
    }
    else if (c >= 1000)
    {
        cout  << c / 1000;
        cout << ',';
        c = c % 1000;
        cout << setfill('0') << setw(3) << c ;
    }
    else
    {
        cout << c % 1000;
    }
}
