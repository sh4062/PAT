#include <bits/stdc++.h>
using namespace std;
int C_max, D, N;
double  D_avg;
struct gs
{
    double p;
    int d;
};
int cmp1(gs a, gs b)
{
    if (a.d != b.d)
        return a.d < b.d;
    else
    {
        return a.p < b.p;
    }
}
int main()
{
    cin >> C_max >> D >> D_avg >> N;
    vector<gs> v;
    for (int i = 0; i < N; i++)
    {
        double p;
        int d;
        cin >> p >> d;
        v.push_back(gs{p, d});
    }
    sort(v.begin(), v.end(), cmp1);
    if (v[0].d != 0)
    {
        cout << "The maximum travel distance = 0.00";
        return 0;
    }
    double tmpC = 0;
    double tmpD = 0;
    double res = 0;
    double max_to = C_max * D_avg;
    int s = 0;
    //res += v[0].p * C_max;
    while (1)
    {
        //cout<<s<<" "<<v[s].p<<" "<<res<<endl;
        int hasgs = 0;
        double min_P = -1;
        int index = s + 1;
        for (int j = index; j != N; j++)
        {
            if (tmpD + max_to >= v[j].d)
            {
                hasgs = 1;
                if (v[s].p > v[j].p)
                {
                    min_P = v[j].p;
                    index = j;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (!hasgs)
        { //没有gs了
            if (tmpD + max_to >= D)
            {
                double need = D - tmpD;
                if (tmpC * D_avg >= need)
                    break; // 油足够到达
                else
                { // 油不够，加
                    double last = need - tmpC * D_avg;
                    res += (last / D_avg) * v[s].p;
                    break;
                }
            }
            else
            {
                double sumDis = tmpD + max_to;
                printf("The maximum travel distance = %.2lf\n", sumDis);
                return 0;
            }
        }
        else //有可到的gs
        {
            if (min_P != -1) // 找到了比当前便宜且距离当前最近的加油站，加油到跑到那里，然后继续在那个站点考虑
            {
                double need = v[index].d - tmpD;
                if (need <= tmpC * D_avg)
                { // 油足够到达
                    tmpC -= need / D_avg;
                }
                else
                { // 油不够，补齐
                    res += (need - tmpC * D_avg) / D_avg * v[s].p;
                    //cout<<(need - tmpC * D_avg) / D_avg * v[s].p<<"！"<<endl;
                    tmpC = 0; // 跑过去就没有油了
                }
                s = index;
                tmpD = v[index].d;
            }
            else // 没有便宜的，选择那个最便宜的加油跑过去。
            {
                if (tmpD + max_to >= D)
                {
                    double need = D - tmpD;
                    if (tmpC * D_avg <= need)
                    {
                        double last = need - tmpC * D_avg;
                        res += (last / D_avg) * v[s].p;
                    }
                    break; // 油足够到达
                }
                min_P = INT_MAX;
                for (int j = s+1; j != N; j++)
                {
                    if (tmpD + max_to >= v[j].d)
                    {
                        if (min_P > v[j].p)
                        {
                            
                            min_P = v[j].p;
                            index = j;
                            //cout<<min_P<<v[j].p<<"!!!!!!!"<<endl;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                //cout<<index<<"!!!!!!!"<<endl;
                res += (C_max - tmpC) * v[s].p; 
                tmpC = C_max - (v[index].d-v[s].d ) / D_avg;
                tmpD = v[index].d;
                s = index;
            }
        }
    }
    printf("%.2lf", res);
    return 0;
}