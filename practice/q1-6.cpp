#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c)
    {
        printf("No\n");
        return 0;
    }
    else if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (c * c + b * b == a * a))
    {
        printf("Yes\n");
        return 0;
    }
    else
    {
        printf("No\n");
        return 0;
    }
}