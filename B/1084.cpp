/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1084.cpp
*   Creator    ：Max
*   Date       ：2019/02/20
*   Description：
*
================================================================*/

#include <bits/stdc++.h>
using namespace std;
string s, temp, ans;
int main()
{
    char a;
    int b;
    cin >> a >> b;
    s = a;
    int cnt = 1, num = 0;
    int len = 0;
    char t;
    while (cnt < b)
    {
        cnt++;
        len = s.length();
        num = 0;
        temp = "";
        t = s[0];
        for (int i = 0; i <=len; i++)
        {
            if (t == s[i])//一样则继续前进
            {
                num++;
            }
            else//不一样退回
            {
                temp += t;
                temp += static_cast<char>(num + '0');
                num = 0;
                t = s[i];
                i--;
            }
        }
        s = temp;
    }
    cout << s;
}