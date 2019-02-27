// 即找出某个元素在所有子序列中出现的次数。
// 不妨设a为第i个元素（从1开始），那么a前面有i-1元素，根据连续子序列的
// 构成方法，那么包含a的子序列有i个。然后再看后面，有N-i个元素。
// 则a和后面的可以构成N-i+1个已a开头的连续子序列。
// 根据组合方式，共有i*（N-i+1)个含有a的连续子序列。
// 所有总次数即为i*（N-i+1)。
// 剩下就累加好了。
// --------------------- 
// 作者：坚不萌 
// 来源：CSDN 
// 原文：https://blog.csdn.net/shepherd2010/article/details/71637973 
// 版权声明：本文为博主原创文章，转载请附上博文链接！
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n;
    double t ,res = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>t;
        res = res+ t*i*(n+1-i);
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<res;
}
