/*
 * File: 1058.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 6:58:07 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 6:58:12 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include<iostream>
using namespace std;
int main()
{
    int a1, a2, a3, b1, b2, b3;
    int r1,r2,r3;
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    int f1 = 0,f2 = 0,f3 = 0;
    if(a3+b3>=29)f3 = 1;
    if(a2+b2+f3>=17)f2 = 1;
    r3 = (a3+b3)%29;
    r2 = (a2+b2+f3)%17;
    r1 = (a1+b1+f2);
    cout<<r1<<"."<<r2<<"."<<r3;
}