#include <bits/stdc++.h>
using namespace std;
struct p
{
    string name;
    int age;
    int money;
} v[10005];
int cmp(p a, p b)
{
    if (a.money != b.money)
        return a.money > b.money;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return a.name < b.name;
}
int main()
{
    int N, q;
    cin >> N >> q;
    //vector<p> v;
    for (int i = 0; i < N; i++)
    {
        string name;
        int age;
        int money;
        //cin >> name >> age >> money;
        name.resize(9);
        scanf("%s %d %d", &name[0], &age, &money);
        v[i] = (p{name, age, money});
    }
    sort(v, v + N, cmp);
    for (int i = 0; i < q; i++)
    {
        int n, a1, a2;
        cin >> n >> a1 >> a2;
        printf("Case #%d:\n", i + 1);
        vector<p> res;
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (v[j].age >= a1 && v[j].age <= a2)
            {
                cnt++;
                res.push_back(v[j]);
                if (cnt == n)
                    break;
            }
        }
        if (res.size() == 0)
        {
            //cout << "None\n";
            printf("None\n");
        }
        else
        {
            for (auto i : res)
            {
                //cout << i.name << " " << i.age << " " << i.money << endl;
                printf("%s %d %d\n", i.name.c_str(), i.age, i.money);
            }
        }
    }
}