#include <bits/stdc++.h>
using namespace std;
#define pi 4.0 * atan(1.0)

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 4 == 0)
    {
        if (n % 100 != 0)
        {
            printf("Yes\n");
        }
        else
        {
            if (n % 400 == 0)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    else
    {
        printf("No\n");
    }
}