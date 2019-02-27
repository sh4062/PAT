/*
 * File: 1044.cpp
 * Project: B
 * File Created: Monday, 25th February 2019 8:10:21 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 27th February 2019 11:09:03 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
string map1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string map2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main()
{
    int N;
    cin >> N;
    getchar();
    while (N--)
    {
        string t;
        //cin >> t;
        map<string, int> mp1;
        map<string, int> mp2;
        for (int i = 0; i < 13; i++)
        {
            mp1[map1[i]] = i;
            mp2[map2[i]] = i;
        }
        getline(cin, t);
        if (t[0] >= '0' && t[0] <= '9')
        {
            int tt = stoi(t);
            int ttt = tt / 13;
            int tttt = tt % 13;
            if(tt==0){
                cout<<"tret"<<endl;
                continue;
            }
            if (ttt != 0)
            {
                cout << map2[ttt] ;
            }
            if(ttt!=0&&tttt!=0){
                cout<< " ";
            }
            if(tttt!=0)  
            cout << map1[tttt]<<endl;
            else{cout<<endl;}
        }
        else
        {
            stringstream ss(t);
            vector<string> vec;
            string buf;
            while (ss >> buf)
                vec.push_back(buf);
            int res = 0;
            //cout<<vec.size()<<vec[0];
            if (vec.size() == 2)
            {
                cout << mp2[vec[0]] * 13 + mp1[vec[1]]<<endl;
            }
            else
            {
                if(mp1.find(vec[0])!=mp1.end())
                cout << mp1[vec[0]]<<endl;
                else if(mp2.find(vec[0])!=mp2.end())
                cout << mp2[vec[0]]*13<<endl;
            }
        }
    }
}