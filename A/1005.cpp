/*
 * File: 1005.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 11:16:31 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 11:16:32 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <iostream>  
#include <cstdio>  
#include <cstring>  
char num[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};  
  
int main(int argc, const char * argv[]) {  
    char n[110];  
    scanf("%s", n);  
    int sum = 0;  
    int len = strlen(n);  
    for(int i =0; i < len; i++) {  
        sum += n[i] - '0';  
    }  
    int a[10];  
    int k = 0;  
    if(sum == 0) printf("zero\n");  
    while(sum > 0){  
        a[k] = sum % 10;  
        sum /= 10;  
        k++;  
    }  
    for(int i = k - 1; i >=0; i--){  
        printf("%s", num[a[i]]);  
        if(i > 0) printf(" ");  
    }  
    return 0;  
}  