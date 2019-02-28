#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
    {
        return gcd(b, a % b);
    }
}
struct rn
{
    long long up;
    long long down;
};
int main()
{
    long long n;
    cin >> n;
    vector<rn> v(105);
    for (int i = 0; i < n; i++)
    {
        long long a, b;
        scanf("%lld/%lld", &a, &b);
        v[i] = rn{a, b};
    }
    for (int i = 0; i < n - 1; i++)
    {
        long long u1 = v[i].up;
        long long u2 = v[i + 1].up;
        long long d1 = v[i].down;
        long long d2 = v[i + 1].down;
        long long g = d1 * d2;
        v[i + 1].up = g / d1 * u1 + g / d2 * u2;
        v[i + 1].down = g;
        long long gg = gcd(v[i + 1].up, v[i + 1].down);
         v[i + 1].up/=gg;
         v[i + 1].down/=gg;
        //cout<<g<<endl;
    }
    long long g = gcd(v[n - 1].up, v[n - 1].down);
    v[n - 1].up = v[n - 1].up / g;
    v[n - 1].down = v[n - 1].down / g;
    if (v[n - 1].up / v[n - 1].down)
        cout << v[n - 1].up / v[n - 1].down;
    if (v[n - 1].up % v[n - 1].down != 0 && v[n - 1].up / v[n - 1].down)
        cout << " " << v[n - 1].up - v[n - 1].down * (v[n - 1].up / v[n - 1].down) << "/" << v[n - 1].down;
    else if(v[n - 1].up % v[n - 1].down != 0)
    {
        cout << v[n - 1].up - v[n - 1].down * (v[n - 1].up / v[n - 1].down) << "/" << v[n - 1].down;
    }
    else if(v[n - 1].up/v[n - 1].down == 0 && v[n - 1].up%v[n - 1].down == 0 )
		cout<<0;

}