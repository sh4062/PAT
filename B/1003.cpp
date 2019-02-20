/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1003.cpp
*   Creator    ：Max
*   Date       ：2019/02/19
*   Description：
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;

 
void isPAT(string str);
int main() {
	
	int n(0); // 字符串个数
	cin >>n;
	for(int i=0;i<n;i++){
		string temp;
		cin >> temp;
		isPAT(temp); 
	} 
	return 0;
}
 
void isPAT(string str){
	 
	int P_j(0),T_j(0);  //记录P,T的位置 
	int countP(0), countT(0);  //记录P,T的个数 
	bool status= true;  // 当有不合法的字符出现时变为false 
	for(int i=0;i<str.length();i++){
		//有不是P,A,T三种字符的输出NO
		if(str[i]!='P' && str[i]!='A'&& str[i]!='T'){ 
			status = false;
		} 
		if(str[i]=='P'){
			P_j=i;
			countP++;
		} 
		if(str[i]=='T'){
			T_j=i;
			countT++;
			break;
		}
		
	}
	
	if((T_j-1-P_j)>=1 && P_j*(T_j-1-P_j)==(str.length()-1-T_j) && countP==1 && countT==1 && status){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	 
}

