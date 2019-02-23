/*
 * File: 1143.cpp
 * Project: A
 * File Created: Saturday, 23rd February 2019 1:29:44 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Saturday, 23rd February 2019 1:29:46 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2019 Your Company
 */
#include <bits/stdc++.h>
using namespace std;
// unordered_map<int, int> mp;
// vector<int>  in(10001),pre(10001);
// //p_root:先序的根位置
// void lca(int l, int r, int p_root, int a, int b)
// {
//     if (l > r)
//         return;
//     int root = mp[pre[p_root]], aa = mp[a], bb = mp[b];
//     //都在左边
//     if (aa < root && bb < root)
//     {
//         lca(l, root - 1, p_root + 1, a, b);
//     }
//     //一左一右
//     else if ((aa < root && bb > root) || (aa > root && bb < root))
//     {
//         //cout << "LCA of " << a << " and " << b << " is " << in[root]<<".\n";
//         printf("LCA of %d and %d is %d.\n",a,b,in[root]);
//     }
//     //都在右边
//     else if (aa > root && bb > root)
//     {
//         lca(root + 1, r, p_root + 1 + root - l,  a, b);
//     }
//     else if (aa == root)
//     {
//         //cout << a << " is an ancestor of " << b << ".\n";
//         printf("%d is an ancestor of %d.\n",a,b);
//     }
//     else if (bb == root)
//     {
//         //cout << b << " is an ancestor of " << a << ".\n";
//         printf("%d is an ancestor of %d.\n",b,a);
//     }
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
// std::cin.tie(0);

//     int m, n;
//     int a, b;
//     scanf("%d %d",&m,&n);
//     // in.resize(n + 1);
//     pre.resize(n + 1);
//     in.resize(n + 1);
//     // for (size_t i = 1; i <= n; i++)
//     // {
//     //     cin >> in[i];
//     //     mp[in[i]] = i;
//     // }
//     for (int i = 1; i <= n; i++)
//     {
//         //cin >> pre[i];
//         scanf("%d",&pre[i]);
//         in[i]=pre[i];
//     }
    
//     sort(in.begin()+1,in.begin()+1+n);
//     for (int i = 1; i <= n; i++)
//     {
//        mp[in[i]] = i;
//     }

//     for (int i = 0; i < m; i++)
//     {
//         //cin >> a >> b;
//         scanf("%d %d",&a,&b);
//         if (mp[a] == 0 && mp[b] == 0)
//         {
//             //cout << "ERROR: "<<a<<" and "<<b<<" are not found.\n";
//             printf("ERROR: %d and %d are not found.\n",a,b);
//         }
//         else if (mp[a] == 0 || mp[b] == 0)
//         {
//             if (mp[a] == 0)
//                 //cout << "ERROR: " << a << " is not found.\n";
//                 printf("ERROR: %d is not found.\n",a);

//             else
//                 //cout << "ERROR: " << b << " is not found.\n";
//                 printf("ERROR: %d is not found.\n",b);

//         }
//         else
//         {
//             lca(1, n, 1, a, b);
//         }
//     }
// }

vector<int> pre;
int m, n;
 
int main() {
	//read
	cin >> m >> n;
	pre.resize(n);
	//set<int> sset;
	unordered_map<int, int> un_map;
	for (int i = 0; i < n; ++i) {
		//cin >> pre[i];
		scanf("%d", &pre[i]);
		un_map[pre[i]] = 1;
	}
 
	//find lca
	while (m--) {
		int a, b;
		//cin >> a >> b;
		scanf("%d %d", &a, &b);
 
		//not found
		if (un_map.find(a) == un_map.end() && un_map.find(b) == un_map.end()) {
			printf("ERROR: %d and %d are not found.\n", a, b);
			continue;
		}
		else if (un_map.find(a) == un_map.end() && un_map.find(b) != un_map.end()) {
			printf("ERROR: %d is not found.\n", a);
			continue;
		}
		else if (un_map.find(a) != un_map.end() && un_map.find(b) == un_map.end()) {
			printf("ERROR: %d is not found.\n", b);
			continue;
		}
 
		//lca
		int lca;
		int index = 0;
		while (index != n) {
			if (pre[index] >= a && pre[index] <= b|| pre[index] <= a && pre[index] >= b) {
				lca = pre[index];
				break;
			}
			index++;
		}
 
		if (lca != a && lca != b)
			printf("LCA of %d and %d is %d.\n", a, b, lca);
		else if (lca == a)
			printf("%d is an ancestor of %d.\n", a, b);
		else if(lca==b)
			printf("%d is an ancestor of %d.\n", b, a);
	}
 
	system("pause");
	return 0;
}
//上面我自己写的递归会tle，下面是参考的，bst找lca看先序序列就行！！！
// --------------------- 
// 作者：李艳宾 :) 
// 来源：CSDN 
// 原文：https://blog.csdn.net/linghugoolge/article/details/84196186 
// 版权声明：本文为博主原创文章，转载请附上博文链接！