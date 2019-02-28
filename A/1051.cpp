#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N, K;
    cin >> M >> N >> K;
    
    for (int i = 0; i < K; i++)
    {
        vector<int> v;
        stack<int> st;
        int flag = 1;
        for (int j = 0; j < N; j++)
        {
            int t;
            cin >> t;
            v.push_back(t);
        }
        int t = 0;
        for (int ii = 0; ii < N; ii++)
        {
            st.push(ii + 1);
            if (st.size() > M)
            {
                flag = 0;
                break;
            }
            while (st.top() == v[t])
            {
                st.pop();
                t++;
                if (st.empty())
                {
                    break;
                }
            }
        }
        if (!st.empty())
        {
            flag = 0;
        }
        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}