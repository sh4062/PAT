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

string ReverseSentence(string str) {
    string res = "",tmp = "";
    for (unsigned int i = 0; i < str.size(); ++i)
    {//Blank
    if(str[i] == ' ')  
    {res = " " + tmp + res;
    tmp = "";}
    else{
        tmp += str[i];
    }}
    //Last word
    if(tmp.size())   
        res = tmp + res;  
  
    return res; 
}

int main(){
    string s;
    string res = "";
    getline(cin,s);
    res = ReverseSentence(s);
    cout<<res;
}