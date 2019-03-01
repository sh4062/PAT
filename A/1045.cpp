#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int N, M, L;
    cin >> N;
    cin >> M;
    vector<int> v1;
    vector<int> v2;
    //vector<int> dp(205, 0);
    for (int i = 0; i < M; i++)
    {
        int t;
        cin >> t;
        
            v1.push_back(t);
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int t;
        cin >> t;
        v2.push_back(t);
    }
    vector<vector<int>> dp(M + 1, vector<int>(L + 1, 0));
    for (int i = 1; i <= v1.size(); i++)
    { //初始化边界数组
        if (v1[i-1] == v2[i-1])
            dp[i][1] = 1;
        else if (i == 1)
            dp[i][1] = 0;
        else
            dp[i][1] = dp[i - 1][1];
    }
    for (int i = 1; i <= v1.size(); i++)
    {
        for (int j = 2; j <= v2.size(); j++)
        {
            if (v1[i-1] == v2[j-1])
            { //如果相等，那么dp[i][j]由dp[i][j-1]和dp[i-1][j-1]的最大值构成
                if (i != 1)
                    dp[i][j] = max(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1);
                else
                    dp[i][j] = dp[i][j - 1] + 1;
            }
            else
            {
                if (i != 1)
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]); //取包含上一个f的长度和不包含上一个f的长度两者最大值
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    cout<<dp[M][L];
}

// int main()
// {
//     // ios::sync_with_stdio(false);
//     // cin.tie(0);
//     int N, M, L;
//     cin >> N;
//     cin >> M;
//     vector<int> v1(205, 0);
//     //vector<int> v2;
//     vector<int> dp(205, 0);
//     for (int i = 0; i < M; i++)
//     {
//         int t;
//         cin >> t;
//         if (v1[t] == 0)
//             v1[t] = i + 1;
//     }

//     cin >> L;
//     for (int i = 0; i < L; i++)
//     {
//         int t;
//         cin >> t;
//         //v2.push_back(t);
//         if (v1[t])
//         {
//             for (int j = M; j >= v1[t]; j--)
//             {
//                 for (int k = v1[t]; k >= 0; k--)
//                     dp[j] = max(dp[j], dp[k] + 1);
//             }
//         }
//     }
//     printf("%d\n",dp[M]);
// }