#include <bits/stdc++.h>
using namespace std;
#define pi 4.0*atan(1.0)

int main()
{
    int n;
    scanf("%d", &n);
    if(n*95>300)
    printf("%.3lf\n", n*95*0.85);
    else
    printf("%.3lf\n", n*95.0);
}