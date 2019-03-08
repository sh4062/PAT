#include <bits/stdc++.h>
int a[102000];
int n,m;
using namespace std;
std::vector<int> v;
void show(){
    int flag=0;
    for(int i=0;i<v.size();i++){
        if(!flag){
            flag=1;
            printf("%d",v[i]);
        }
        else{
            printf(" %d",v[i]);
        }
    }
    printf("\n");
}
int ok=0;
void dfs(int index,int sum,int cnt){
    if(ok) return;
    if(sum==m){
        ok=1;
        show();
        return;
    }
    if(sum>m){
        return;
    }
    for(int i=index;i<=n;i++){
        v.push_back(a[i]);
        dfs(i+1,sum+a[i],cnt+1);
        v.pop_back();//删掉最后那个元素
    }
}
int main(){
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<m){//所有coin都不夠
        printf("No Solution\n");
        return 0;
    }
    sort(a+1,a+1+n);//从小到大排序
    dfs(1,0,0);//从第一个开始找
    if(!ok){
        printf("No Solution\n");
    }
    return 0;
}
