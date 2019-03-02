
#include <bits/stdc++.h>
using namespace std;
int flag = 0;
vector<int> fa(401, 0);
int res[401];
int ans[401];
int a, b, c;
int maxsum = 0;
int fidx = 0;
/*
num为当前的总和
cnt为还剩几个i^p项，即当前的k
sum为各因子的总和，因为要取和最大的
last为上一个因子的索引，因为要保证因子从大到小输出，
所以dfs后一个因子在factor中的索引不能大于上一个
*/
void dfs(int num,int cnt,int sum,int last){
    if(num==0&&cnt==0){
        if(sum>maxsum){
            flag=true;
            for(int i=1;i<=b;i++){
                //cout<<res[i];
                ans[i]=res[i];}
            maxsum=sum;
        }
        return;
    }
    else if(cnt==0)
        return;
    for(int i=min(fidx,last);i>0;i--){
        int left=num-fa[i];
        if(left>=cnt-1){
            //cout<<left<<endl;
            res[cnt]=i;
            dfs(left,cnt-1,sum+i,i);
        }
    }
}
int main()
{
    
    cin >> a >> b >> c;
    //cout << "Impossible";
    int i = 0;
    for (i = 0; i < 401; i++)
    {
        fa[i] = pow(i, c);
        if (fa[i] > a)
            break;
    }
    fidx = i-1;
    int cnt = 0;
    int last = i - 1;
    dfs(a,b,0,last);
    if (flag)
    {
        printf("%d =", a);
        for (int i = b; i >= 2; i--)
        {
            printf(" %d^%d +", ans[i], c);
        }
        printf(" %d^%d", ans[1], c);
    }
    else
    {
        printf("Impossible");
    }
}