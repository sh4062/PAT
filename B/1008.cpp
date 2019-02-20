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
int main(){
    int l,p,i;
    cin>>l>>p;
    int m = l;
    vector<int> v;
    while(l--) {
        cin>>i;
        v.push_back(i);
        
    } 
    if(p>m)
    p = p%m;
    reverse(v.begin(), v.end()-p);
    reverse(v.end()-p, v.end());
    reverse(v.begin(), v.end());
    cout<<v[0];
    for (std::vector<int>::iterator it=v.begin()+1; it!=v.end(); ++it)
        std::cout << ' ' << *it;

    
}