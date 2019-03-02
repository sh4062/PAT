#include <bits/stdc++.h>
using namespace std;
struct node
{
    char id[8];
    int t, status; // 时间 and 状态.
};
int n, k, maxtime = -1; // 莫非真的存在不停车呢。。。
vector<node> t(10001);
int cmpt1(const node &a, const node &b)
{
    return strcmp(a.id, b.id) == 0 ? a.t < b.t : strcmp(a.id, b.id) < 0;
}
int cmpt2(const node &a, const node &b)
{
    return a.t < b.t;
}
int main()
{
    scanf("%d%d", &n, &k);
    int h, m, s;
    char status[4];
    t.resize(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s %d:%d:%d %s", t[i].id, &h, &m, &s, status);
        t[i].status = strcmp(status, "in") == 0 ? 1 : -1; // in 表示1， -1表示out，便于后面计算车辆
        t[i].t = h * 3600 + m * 60 + s;
    }
    sort(t.begin(), t.end(), cmpt1);
    vector<node> tt;
    map<string, int> st;
    for (int i = 0; i < n - 1; ++i)
    {
        //cout<<t[i].id<<endl;
        if (t[i].status == 1 && t[i + 1].status == -1 && strcmp(t[i].id, t[i + 1].id) == 0)
        {

            t[i].status = 2;
            t[i + 1].status = -2;
            tt.push_back(t[i]);
            tt.push_back(t[i + 1]);
            st[t[i].id] += t[i + 1].t - t[i].t;

            if (maxtime < st[t[i].id])
                maxtime = st[t[i].id];
        }
    }
    sort(tt.begin(), tt.end(), cmpt2);
    vector<pair<int, int>> mp(tt.size()+1);
    int count = 0;
    mp[0] = make_pair(0,0);
    for (int i = 0; i < tt.size(); i++)
    {
        if (tt[i].status == 2)
        {
            // cout << t[i].id << endl;
            // cout << t[i].t << endl;
            // cout << times << endl;
            count++;
            mp[i+1]=(make_pair(tt[i].t,count));
            //res.insert(t[i].id);
        }
        else if (tt[i].status == -2)
        {
            count--;
            mp[i+1]=(make_pair(tt[i].t,count));
            //res.erase(t[i].id);
        }
    }
    for (int i = 0; i < k; ++i)
    {
        scanf("%d:%d:%d", &h, &m, &s);
        int times = h * 3600 + m * 60 + s;
        int res = 0;
        // for (int i = 0; i < tt.size(); i++)
        // {
        //     if (tt[i].t <= times)
        //     {
        //         if (tt[i].status == 2)
        //         {
                   
        //             res++;
        //         }
        //         else if (tt[i].status == -2)
        //         {
        //             res--;
        //         }
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        vector<pair<int, int>>::iterator it = mp.begin();
        for (; it != mp.end(); ++it){
            if((*it).first>times)break;
        }
        it--;
        printf("%d\n", (*it).second);
    }
    for (map<string, int>::iterator it = st.begin(); it != st.end(); ++it)
        if (it->second == maxtime)
        {

            printf("%s ", (it->first).c_str());
        }
    // cout << st["JH007BD"] << endl
    //      << maxtime << endl;

    printf("%02d:%02d:%02d", maxtime / 3600, maxtime % 3600 / 60, maxtime % 60);
}