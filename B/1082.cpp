/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1082.cpp
*   Creator    ：Max
*   Date       ：2019/02/20
*   Description：
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
struct shooter{
    string num;
    int x;
    int y;
};
vector<shooter> vec;
bool cmp(shooter a, shooter b){
    if((a.x)*(a.x)+a.y*a.y<b.x*b.x+b.y*b.y) return true;
    else return false;
}

int main() {
  int n;
  cin>>n;
  while(n--){
      shooter in;
      cin>>in.num>>in.x>>in.y;
      vec.push_back(in);
  }
  sort(vec.begin(),vec.end(),cmp);
  cout<<vec[0].num<<' '<<vec[vec.size()-1].num;

}
