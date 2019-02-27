#include <bits/stdc++.h>
using namespace std;
long long isPrime(long long a)
{
    if (a == 1)
        return 0;
    if (a == 2 || a == 3)
        return 1;
    if (a % 2 == 0)
        return 0;
    if (a % 3 == 0)
        return 0;
    for (long i = 3; i <= sqrt(a); i += 2)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    map<int, int> mp;
    long long a;
    cin >> a;
     if (a == 1)
    {
        cout << "1=1";
        return 0;
    }
    if (a == 2)
    {
        cout << "2=2";
        return 0;
    }
    if (a == 3)
    {
        cout << "3=3";
        return 0;
    }
    int f, cnt = 0;
    if (a % 2 == 0)
    {
        mp[2] = 1;
        for (long long j = 2; j <= sqrt(a); j++)
        {
            if (a % (long long)pow(2, j) == 0)
            {
                mp[2]++;
            }
            else
            {
                break;
            }
        }
    }
    for (long long i = 3; i <= sqrt(a); i += 2)
    {
        if (isPrime(i)&&a%i==0)
        {

            mp[i] = 1;

            for (long long j = 2; j <= sqrt(a); j++)
            {
                if (a % (long long)pow(i, j) == 0)
                {
                    mp[i]++;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout << a << "=";
    map<int, int>::iterator it = mp.end();
    it--;
    for (auto i : mp)
    {
        cout<<i.first;
        if(i.second!=1){
            cout<<"^"<<i.second;
            if(i!=*(it))
            cout<<"*";
        }
        else{
            if(i!=*(it))
            
            cout<<"*";
        }
    
    }
}