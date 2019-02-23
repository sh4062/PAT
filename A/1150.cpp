/*
 * File: 1150.cpp
 * Project: A
 * File Created: Friday, 22nd February 2019 10:08:55 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 22nd February 2019 11:47:26 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
int G[201][201] = {0};
int main(){
    int a, b;
    cin>>a>>b;
    while(b--){
        int v1,v2;
        cin>>v1>>v2;
        cin>>G[v1][v2];
        G[v2][v1] = G[v1][v2];
    }
    int q = 0;
    cin>>q;
    int shortest = INT_MAX;
    int shortest_index = 0;
    vector <int> pathes(201,0);
    vector <int> visited(201,0);
    //cout<<G[155][155]<<"!";
    for(size_t i = 1; i <=q; i++)
    {
        for(size_t k = 1; k <= 200; k++)
        {
            visited[k]=0;      
            pathes[k] = 0;
        }
        int qq;
        cin>>qq;
        int dist = 0;
        
        int flag = 1;
        for(size_t g = 1; g <= qq; g++)
        {
            cin>>pathes[g];
        }
        int j = 1;
        
        for(j;j<qq;j++) {
            if(G[pathes[j]][pathes[j+1]]!=0){
                dist+=G[pathes[j]][pathes[j+1]];
                visited[pathes[j]]++;
                visited[pathes[j+1]]++;
                //cout<<G[pathes[j]][pathes[j+1]];
            }else{
                
                break;
            }
        }
        
        if(pathes[1]!=pathes[qq])flag = 0;

        
        for(size_t k = 1; k <= a; k++)
        {
            //cout<<visited[k];
            if(visited[k]==0)
            {
                flag = 0;
                break;
            }
        }
        
        
        if(flag){
            if(qq==a+1&&j==qq){
            cout<<"Path "<<i<<": "<<dist<<" (TS simple cycle)\n";
            if(shortest>dist){
            shortest=min(shortest,dist);
            shortest_index = i;
            }
            
        }else{
            
            cout<<"Path "<<i<<": "<<dist<<" (TS cycle)\n";
            if(shortest>dist){
            shortest=min(shortest,dist);
            shortest_index = i;
            }
        }
            
        }else{
            if(j==qq)
             cout<<"Path "<<i<<": "<<dist<<" (Not a TS cycle)\n";
             else{
             cout<<"Path "<<i<<": "<<"NA"<<" (Not a TS cycle)\n";

             }

        }
        

       

    }
    cout<<"Shortest Dist"<<'('<<shortest_index<<") = "<<shortest;
}