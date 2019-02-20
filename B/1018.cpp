/*================================================================
*   Copyright (C) 2019 Max. All rights reserved.
*   
*   Filename   ：1018.cpp
*   Creator    ：Max
*   Date       ：2019/02/20
*   Description：
*
================================================================*/

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  int jia[3]={0};
  int yi[3]={0};
  int a1=0,a2=0,a3=0;
  int b1=0,b2=0,b3=0;
  char a,b;
  while(n--) {
    cin>>a>>b;
    if(a=='C'&&b=='J'){
      a1++;
      b3++;
      jia[1]++;
    }
    else if(a==b)
    {a2++;b2++;
    }
    else if(a=='C'&&b=='B') {
     a3++;
     b1++;
     yi[0]++;
    }
    else if(a=='J'&&b=='C'){
      a3++;
      b1++;
      yi[1]++;
    }
    else if(a=='J'&&b=='B'){
      a1++;
      b3++;
      jia[2]++;
    
    }else if(a=='B'&&b=='C'){
      a1++;
      b3++;
      jia[0]++;

    }else if(a=='B'&&b=='J'){
      a3++;
      b1++;
      yi[2]++;
    }
    
  }
  cout<<a1<<' '<<a2<<' '<<a3<<'\n';
  cout<<b1<<' '<<b2<<' '<<b3<<'\n';
  vector<char>aux = {'B','C','J'};
int id1 = 0, id2 = 0;

    for(int i = 0;i<3;i++){

        if(jia[i]>jia[id1]) id1 = i;

        if(yi[i]>yi[id2]) id2 = i;

    }

    cout<<aux[id1]<<" "<<aux[id2]<<endl;
}

