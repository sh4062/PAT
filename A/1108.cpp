/*
 * File: 1108.cpp
 * Project: A
 * File Created: Saturday, 23rd February 2019 4:45:05 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Saturday, 23rd February 2019 4:45:07 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
// double is_num(string s)
// {
//     stringstream sin(s);
//     double t;
//     char p;
//     if (!(sin >> t))
//     {
//         return 0;
//     }
//     if (sin >> p)
//         return 0;
//     else{
//         if((t*100)-(double)(int)(t*100)!=0) return 0;
//         return t;
//         }
// }
bool isLegal(string s, double &d)
{
  int len = s.size();

  int dotCnt = 0;
  int dotAfter = 0;

  for(int i=0;i<len;i++)
  {
    if(s[i] == '.')
    {
      dotCnt ++;
      if(dotCnt > 1)
        return false;
    }else if(s[i] == '-' || s[i] == '+')
    {
      if(i != 0)
        return false;
    }else if(s[i] >= '0' && s[i] <= '9')
    {
      if(dotCnt == 1)
      {
        dotAfter ++;
        if(dotAfter > 2)
          return false;
      }
    }else{
      return false;
    }
  }

  stringstream ss;
  ss << s;
  ss >> d;

  if( d >= -1000.00 && d <= 1000.00)
    return true;

  return false;
}
int main()
{
    int a;
    string s;
    cin>>a;
    double res;
    int count = 0;
    while(a--) {
        cin>>s;
        //int c0 = 0;
        // for(int i = 0;i<s.length();i++){
        //     if(s[i]=='0'||(s[i]=='-'&&i==0)){
        //         c0++;
        //     }
        // }
        // if(c0==s.length()){
        //     count++;
        //     continue;
        // }
        // if(is_num(s)&&(is_num(s)>=-1000&&is_num(s)<=1000)){
        //     count++;
        //     res+=is_num(s);
        // }
        double t;
        if(isLegal(s,t)){
            count++;
            res+=t;
        }
        else{
            cout<<"ERROR: "<<s<<" is not a legal number\n";
        }

    }
    if(count == 0){
        cout<<"The average of 0 numbers is Undefined\n";
    }else    if(count == 1){
        printf("The average of %d number is %.2lf",count,res/(double)count);
    }
    else{
        printf("The average of %d numbers is %.2lf",count,res/(double)count);
    }
}