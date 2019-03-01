#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v(1005);
vector<int>visited(1005,0);
int N, L;
int BFS(int source){  
    for(int i = 0; i <= N; i++)  
        visited[i] = false;  
    queue<int> q;  
    q.push(source);  
    int level = 0, last = source, tail = source;  
    visited[source] = true;  
    int cnt = 0;  
    while(!q.empty()){  
        int p = q.front();  
        q.pop();  
        for(int i = 0; i < v[p].size(); i++){  
            int w = v[p][i];  
            if(visited[w]) continue;  
            q.push(w);  
            tail = w;  
            visited[w] = true;  
        }  
        if(level >= 1 && level <= L){  
            cnt++;  
        }  
        if(p == last){  
            level ++;  
            last = tail;  
        }  
  
        if(level > L) break;  
    }  
  
    return cnt;  
  
}  
int main()
{
    
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            v[t].push_back(i);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int q1;
        cin >> q1;
        // unordered_set<int> res;
        // int l = L;
        // for (int j = 0; j < v[q1].size(); j++)
        // {
        //     res.insert(v[q1][j]);
        // }
        // l--;
        // if (l == 0)
        // {
        //     cout << res.size();
        //     continue;
        // }
        // while (l != 0)
        // {
        //     for (auto j : res)
        //     {
        //         for (int k = 0; k < v[j].size(); k++)
        //         {
        //             if(v[j][k]!=q1)
        //             res.insert(v[j][k]);
        //         }
        //     }
        //     l--;
        // }
        // cout<<res.size()<<endl;
        cout<<BFS(q1)<<endl;
    }
}
