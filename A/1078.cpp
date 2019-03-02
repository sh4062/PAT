#include <bits/stdc++.h>
using namespace std;
int isPrime(int a)
{
    if (a == 1)
        return 0;
    if (a == 2 || a == 3)
        return 1;
    if (a % 2 == 0)
        return 0;
    if (a % 3 == 0)
        return 0;
    for (int i = 3; i < sqrt(a); i += 2)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int a, b, c, tmp;
    cin >> a >> b;
    if (isPrime(a) == 0)
    {
        for (int i = a;; i++)
        {
            if (isPrime(i))
            {
                a = i;
                break;
            }
        }
    }
    vector<int> mp(a, -1);
    cin >> c;
    int p = c % a;
    if (mp[p])
    {
        p = -1;
        for (int k = 0; k <= a - 1; k++)
        {
            if (mp[(c + (int)pow(k, 2)) % a] == -1)
            {
                mp[(c + (int)pow(k, 2)) % a] = c;
                p = (c + (int)pow(k, 2)) % a;
                break;
            }
        }
    }
    else
    {
        mp[p] = c;
    }
    if (p != -1)
        cout << p;
    else
    {
        cout << "-";
    }
    for (int i = 1; i < b; i++)
    {
        cin >> c;
        int p = c % a;
        if (mp[p])
        {
            p = -1;
            for (int k = 0; k <= a - 1; k++)
            {
                if (mp[(c + (int)pow(k, 2)) % a] == -1)
                {
                    mp[(c + (int)pow(k, 2)) % a] = c;
                    p = (c + (int)pow(k, 2)) % a;
                    break;
                }
            }
        }
        else
        {
            mp[p] = c;
        }
        if (p != -1)
            cout <<" "<< p;
        else
        {
            cout <<" "<< "-";
        }
    }
}