/*
 * File: 1155.cpp
 * Project: A
 * File Created: Thursday, 21st February 2019 3:39:02 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Thursday, 21st February 2019 3:39:51 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Outer Heaven
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int maxflag = 0, minflag = 0;
    int maxflag1 = 0, minflag1 = 0;
    int a;
    cin >> a;
    vector<int> heap(a + 1);
    for (int i = 1; i <= a; i++)
    {
        cin >> heap[i];
    }
    if (heap[1] < heap[2])
    {
        minflag = 1;
        minflag1 = 1;
    }
    else if (heap[1] > heap[2])
    {
        maxflag = 1;
        maxflag1 = 1;
    }
    int l = 1;
    int ll = 1;
    for (ll;; ll++)
    {
        l += pow(2, ll);
        if (l > a)
        {
            l -= pow(2, ll);
            break;
        }
    }
    
    int tmp = pow(2, ll );
    //cout<<l<<ll<<tmp<<"!";
    for (int i = 0; i < (tmp-(a-l))/2; i++)
    {
        deque<int> q;
        int index = l - i;

        while (index != 1)
        {
            if (maxflag)
            {
                if (heap[index] < q.front()&&(!q.empty()))
                {
                    maxflag1 = 0;
                    //cout<<q.front()<<"!"<<heap[index];
                }
            }
            else if(minflag)
            {
                if (heap[index] > q.front()&&(!q.empty()))
                {
                    minflag1 = 0;
                }
            }
            q.push_front(heap[index]);
            index /= 2;
        }
        q.push_front(heap[1]);
        while (!q.empty())
        {
            if (q.size() != 1)
            {
                cout << q.front() << ' ';
                q.pop_front();
            }
            else
            {
                cout << q.front() << '\n';
                q.pop_front();
            }
        }
    }
    for (int i = a; i > l; i--)
    {
        deque<int> q;
        int index = i;

        while (index != 1)
        {
            if (maxflag)
            {
                if (heap[index] < q.front()&&(!q.empty()))
                {
                    maxflag1 = 0;
                    //cout<<q.front()<<"!"<<heap[index];
                }
            }
            else if(minflag)
            {
                if (heap[index] > q.front()&&(!q.empty()))
                {
                    minflag1 = 0;
                    //cout<<q.front()<<"!"<<heap[index];
                }
            }
            q.push_front(heap[index]);
            index /= 2;
        }
        q.push_front(heap[1]);
        while (!q.empty())
        {
            if (q.size() != 1)
            {
                cout << q.front() << ' ';
                q.pop_front();
            }
            else
            {
                cout << q.front() << '\n';
                q.pop_front();
            }
        }
    }
    if (maxflag && maxflag1)
    {
        cout << "Max Heap";
    }
    else if (minflag && minflag1)
    {
        cout << "Min Heap";
    }
    else
    {   //cout << minflag<<minflag1;
        cout << "Not Heap";
    }
}