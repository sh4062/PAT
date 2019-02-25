/*
 * File: 1128.cpp
 * Project: A
 * File Created: Sunday, 24th February 2019 9:46:44 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Sunday, 24th February 2019 11:34:30 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>

const int MAXN = 1001;
using namespace std;
int a[MAXN], n, t;
int c[3][2*MAXN];
int main()
{
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		int flag = 1;
		for(int i=1 ;i<=n ;i++){
			scanf("%d",&a[i]);
			if(c[0][a[i]]||c[1][a[i]-i+n]||c[2][a[i]+i]) flag = 0;
			c[0][a[i]] = 1; //row 
			c[1][a[i]-i+n] = 1; //diagonal 
			c[2][a[i]+i] = 1; //diagonal 
		}
	
		if(flag)puts("YES");
		else puts("NO");
	}
	
	return 0;
}