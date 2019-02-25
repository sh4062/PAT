/*
 * File: 1054.cpp
 * Project: A
 * File Created: Sunday, 24th February 2019 10:04:39 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Sunday, 24th February 2019 10:04:40 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
    int maxCnt = -1;
    int maxColor = -1;
    map<int, int> colorMap;
    int M, N;
    cin >> M >> N;
    int color;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &color);
            if (colorMap.find(color) == colorMap.end())
            {
                colorMap[color] = 1;
            }
            else
            {
                colorMap[color]++;
            }
            if (maxCnt < colorMap[color])
            {
                maxCnt = colorMap[color];
                maxColor = color;
            }
        }
    }
    cout << maxColor << endl;
    return 0;
}