/*
 * File: 1040.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 12:22:19 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 12:22:20 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;

//char s[1000];
// char s_new[2000];
// int p[2000]; //p[i]是以i为中心的最长回文半径

// int Init()
// {
//     int i = 0, j = 2;
//     s_new[0] = '$';
//     s_new[1] = '#';
//     for (i; i < strlen(s); i++)
//     {
//         s_new[j++] = s[i];
//         s_new[j++] = '#';
//     }
//     s_new[j] = '\0';
//     return j;
// }

// int manacher()
// {
//     int len = Init();
//     int id = 0, mx = 0, maxlen = 0;
//     for (int i = 1; i < len; i++)
//     {
//         if (0 < mx - i)
//             p[i] = min(p[2 * id - i], mx - i);
//         else
//             p[i] = 1;
//         while (s_new[i + p[i]] == s_new[i - p[i]])
//             p[i]++;
//         if (mx < 1 + p[i])
//         {
//             id = i;
//             mx = 1 + p[i];
//         }
//         maxlen = max(maxlen, p[i] - 1);
//     }
//     return maxlen;
// }
string sub;
string s;
int maxLen;
void findLongestPalindrome(string s, int low, int high);
string longestPalindrome(string s)
{
    if (s.length() <= 1)
        return s;

    for (int i = 0; i < s.length() - 1; i++)
    {

        findLongestPalindrome(s, i, i); //单核回文

        findLongestPalindrome(s, i, i + 1); //双核回文
    }
    return sub;
}
void findLongestPalindrome(string s, int low, int high)
{
    while (low >= 0 && high <= s.length() - 1)
    {
        if (s[low] == s[high])
        {
            if (high - low + 1 > maxLen)
            {
                maxLen = high - low + 1;
                sub = s.substr(low, maxLen );
            }
            low--; //向两边扩散找当前字符为中心的最大回文子串
            high++;
        }
        else
            break;
    }
}

int main()
{

    //gets(s);
    //printf("%d\n", manacher());
    
    getline(cin,s);
    //cout<<longestPalindrome(s)<<endl;
    printf("%d\n", longestPalindrome(s).length());

    return 0;
}