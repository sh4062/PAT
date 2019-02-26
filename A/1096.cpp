#include <bits/stdc++.h>
using namespace std;
int main()
{
    int res = 0, ans = 0;
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= sqrt(n); ++i){
        int tmp = n;
        int start = i;
        int cnt = 0;
        while(tmp % start == 0){
            tmp /= start;
            start++;
            cnt++;
        }
        if(cnt > res){
            res = cnt;
            ans = i;
        }
    }
    if(res == 0){
        printf("%d\n%d", 1, n);
        return 0;
    }
    printf("%d\n", res);
    printf("%d", ans);
    for(int i = 1; i < res; ++i){
        printf("*%d", ans+i);
    }
    return 0;

}