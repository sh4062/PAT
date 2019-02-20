/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1040.cpp
*   Creator    ：Max
*   Date       ：2019/02/19
*   Description：
*
================================================================*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a = "";
    //getline(cin, a);
    cin>>a;
    long long count = 0;
    long long t = a.size() - 1;
    long long ct = 0;
    long long ca = 0;
    long long len = a.size();
    while (len >= 0)
    {
        if(a[len]=='T'){
            ct++;
            
        }
        else if(a[len]=='A'){
            ca+=ct;
        }
        else {count+=ca;}
        len--;
    }

    cout << count % 1000000007;
}
