/*
 * File: 1146.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 11:22:59 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 11:23:00 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int rudu [1001] = {0};
int main()
{
    int N, M, a, b;
    cin>>N>>M;
    vector<vector<int>> linjiebiao(N+1);
    while(M--){
        cin>>a>>b;
        linjiebiao[a].push_back(b);
        rudu[b]++;
    }
    int q;
    cin>>q;    
    set<int> res;
    int input;
    for(int i = 0; i < q; i++)
    {
        vector<int> rudu2(rudu,rudu+1001);
        for(int j = 1; j <= N; j++) {
            cin>>input;
            if(rudu2[input] != 0) {
                res.insert(i);
            }
            for(int k = 0;k<linjiebiao[input].size();k++) {
                rudu2[linjiebiao[input][k]]--;
            }

        }
        
    }
    auto i = res.begin();
    cout<<*(i);
    i++;
    for(i;i!=res.end();i++) {
        cout<<" "<<*(i);;
    }
    

}