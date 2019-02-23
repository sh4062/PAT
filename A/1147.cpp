/*
 * File: 1147.cpp
 * Project: A
 * File Created: Saturday, 23rd February 2019 11:24:01 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Saturday, 23rd February 2019 11:24:04 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> heap(1001, 0);
int a, b;
void postorder(int root)
{
    if (root * 2 <= b)
    {
        postorder(2 * root);
    }
    if (root * 2 + 1 <= b)
    {
        postorder(2 * root + 1);
    }
    if (root != 1)
        cout << heap[root] << " ";
    else if (root == 1)
        cout << heap[1]<<'\n';
}

int main()
{

    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        int flag_max1 = 0, flag_max2 = 0;
        int flag_min1 = 0, flag_min2 = 0;
        for (int j = 1; j <= b; j++)
        {
            cin >> heap[j];
        }
        if (heap[1] < heap[2])
        {
            flag_min1 = 1, flag_min2 = 1;
        }
        else
        {
            flag_max1 = 1, flag_max2 = 1;
        }
        for (int k = 1; k <= b; k++)
        {
            if (2 * k <= b)
            {
                if (flag_min1)
                {
                    if (heap[2 * k] < heap[k])
                    {
                        //cout<<heap[2 * k+1]<<heap[k];
                        flag_min2 = 0;
                    }
                }
                else
                {
                    if (heap[2 * k] > heap[k])
                        flag_max2 = 0;
                }
            }
            if (2 * k + 1 <= b)
            {
                if (flag_min1)
                {
                    if (heap[2 * k + 1] < heap[k])
                    {
                        //cout<<heap[2 * k+1]<<heap[k];
                        flag_min2 = 0;
                    }
                }
                else
                {
                    if (heap[2 * k + 1] > heap[k])
                        flag_max2 = 0;
                }
            }
        }
        if (flag_min1 && flag_min2)
        {
            cout << "Min Heap\n";
        }
        else if (flag_max1 && flag_max2)
        {
            cout << "Max Heap\n";
        }
        else
        {
            cout << "Not Heap\n";
        }
        postorder(1);
    }
}