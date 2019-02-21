/*================================================================
 *   Copyright (C) 2019 Max. All rights reserved.
 *   
 *   Filename   ：1153.cpp
 *   Creator    ：Max
 *   Date       ：2019/02/21
 *   Description：
 *
 ================================================================*/

#include <bits/stdc++.h>
using namespace std;
struct PAT
{
  string A;
  int score;
};
bool cmp(PAT a, PAT b)
{
  if (a.score > b.score)
    return 1;
  else if (a.score == b.score)
  {
    if (a.A < b.A)
      return 1;
    else
      return 0;
  }
  else
    return 0;
}
bool cmp2(const pair<string, int> &a, const pair<string, int> &b)
{
  if (a.second > b.second)
    return 1;
  else if (a.second == b.second)
  {
    return a.first < b.first;
  }

  else
    return 0;
}
int main()
{
  std::ios::sync_with_stdio(false);
std::cin.tie(0);


  int a, b;
  cin>>a>>b;
   vector<PAT> v(a);
  int type;
  string tt;
   for (int ii = 0; ii < a; ii++)
  {
    cin >> v[ii].A >> v[ii].score;
  }
  for (int casei = 1; casei <= b; casei++)
  {
    cin >> type >> tt;
    cout << "Case " << casei << ": " << type << ' ' << tt << endl;
    if (type == 1)
    {
      vector<PAT> type1;
      if (tt[0] == 'A')
      {
        for (auto &i : v)
        {
          if (i.A[0] == 'A')
          {
            type1.push_back(i);
          } 
        }
        sort(type1.begin(), type1.end(), cmp);
        
        if (type1.size() == 0)
        {
          cout << "NA";
            cout << '\n';
        }
        else
        {
          for (int ii = 0; ii < type1.size(); ii++)
          {
            cout << type1[ii].A << ' ' << type1[ii].score;
              cout << '\n';
          }
        }
      }
      else if (tt[0] == 'T')
      {
        for (auto &i : v)
        {
          if (i.A[0] == 'T')
          {
            type1.push_back(i);
          }
        }
        sort(type1.begin(), type1.end(), cmp);
        if (type1.size() == 0)
        {
          cout << "NA";
            cout << '\n';
        }
        else
        {
          for (int ii = 0; ii < type1.size(); ii++)
          {
            cout << type1[ii].A << ' ' << type1[ii].score;
              cout << '\n';
          }
        }
      }
      else
      {
        for (auto &i : v)
        {
          if (i.A[0] == 'B')
          {
            type1.push_back(i);
          }
        }
        sort(type1.begin(), type1.end(), cmp);
        if (type1.size() == 0)
        {
          cout << "NA";
            cout << '\n';
        }
        else
        {
          for (int ii = 0; ii < type1.size(); ii++)
          {
            cout << type1[ii].A << ' ' << type1[ii].score;
              cout << '\n';
          }
        }
      }
    }
    else if (type == 2)
    {
      int nt = 0, ns = 0;
      for (auto &i : v)
      {
       
        if (i.A.substr(1,3) == tt)
        {
          nt++;
          ns += i.score;
        }
      }
      if (nt == 0)
        cout << "NA\n";
      else
      {
        cout << nt << ' ' << ns << endl;
      }
      
    }
    else if (type == 3)
    {
      unordered_map<string, int> mp;
      
      for (auto &i : v)
      {
        
       
        if (i.A.substr(4,6) == tt)
        {
            mp[(i.A.substr(1,3))]++;
          
        }
      }
      vector<PAT> out3;
      for (auto it : mp) out3.push_back({it.first, it.second});
      sort(out3.begin(), out3.end(), cmp);
      if (out3.size() == 0)
      {
        cout << "NA\n";
        
      }
      else
      {
        for (int i = 0; i < out3.size(); i++)
        {
          //printf("%s %d\n", out3[i].A.c_str(), out3[i].score);
          //mmp啊 用cout就过不了了
              cout << out3[i].A << ' ' << out3[i].score<< '\n';
            
        }
        
      }
    }
    // {
    //   vector<PAT> ans;
    //   unordered_map<string, int> m;
    //         for (int j = 0; j < a; j++)
    //             if (v[j].A.substr(4, 6) == tt) m[v[j].A.substr(1, 3)]++;
    //         for (auto it : m) ans.push_back({it.first, it.second});
    //         sort(ans.begin(), ans.end(),cmp);
    //     for (int j = 0; j < ans.size(); j++)
    //         printf("%s %d\n", ans[j].A.c_str(), ans[j].score);
    //       if (ans.size() == 0)
    //   {
    //     cout << "NA\n";
        
    //   }

  }
  
}
