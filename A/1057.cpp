// #include <bits/stdc++.h>
// using namespace std;
// int N;
// vector<int> st;
// int partition(vector<int>& L,int low,int high)
// {
// 	int i,num=low;
// 	for(i=low+1;i<=high;i++)
// 	{
// 		if(L[i]<L[low])
// 		{
// 			swap(L[i],L[num+1]);
// 			num++;
// 		}
// 	}
// 	swap(L[low],L[num]);
// 	return num;
// }
// void getmid(vector<int> L,int low,int high)
// {
// 	int mid=(low+high)/2;
// 	while(1)
// 	{
// 		int pos=partition(L,low,high);
// 		if(pos==mid)
// 			break;
// 		else if(pos>mid)
// 			high=pos-1;
// 		else low=pos+1;
// 	}
// 	printf("%d\n",L[mid]);
// }
// int main()
// {
//     cin >> N;
//     getchar();
//     string o;
//     while (N--)
//     {
//         getline(cin, o);
//         if (o.length() == 3)
//         {
//             if (st.size() > 0)
//             {
//                 cout << st[st.size()-1] << endl;
//                 st.pop_back();
                
//             }
//             else
//             {
//                cout << "Invalid\n";
//             }
//         }
//         else if (o[1] == 'e')
//         {
//             if (st.size() > 0)
//             {
//                 getmid(st,0,st.size()-1);
//             }
//             else
//             {
//                 cout << "Invalid\n";
//             }
//         }
//         else
//         {
//             int t = 0;
//             char tt[5];
//             sscanf(o.c_str(), "%s %d", tt, &t);
//             st.push_back(t);
//             //cout << t << endl;
//         }
//     }
// }
#include<bits/stdc++.h>
using namespace std;
//char p[15];
string p;
vector<int>v,v1;
multiset<int>s1,s2;
int mid;
void adjust()
{
	multiset<int>::iterator it;
	if(s1.size()<s2.size())
	{
		it=s2.begin();
		s1.insert(*it);
		s2.erase(it);
	}
	if(s1.size()>s2.size()+1)
	{
	    it=s1.end();
	    it--;
		s2.insert(*it);
		s1.erase(it);
	}
	if(!s1.empty())
	{
	    it=s1.end();
	    it--;
		mid=*it;
		
	}
	
}
int main(void)
{
	int n,va;
	scanf("%d",&n);getchar();
    while(n--)
	{
		//scanf("%s",p);
		cin>>p;
		if(p=="Pop")
		{
			int len=v.size();
			if(len==0) printf("Invalid\n");
			else 
			{
				int a=v[len-1];
				printf("%d\n",a);
				v.pop_back();
				if(a<=mid)
				{
					s1.erase(s1.find(a));
				}
				else s2.erase(s2.find(a));
				adjust();
			}
		}
		else if(p=="PeekMedian")	
		{
			int len=v.size();
			if(len==0) printf("Invalid\n");
			else 
			{
				printf("%d\n",mid);
			}
		}
		else 
		{
			getchar();
			scanf("%d",&va);
			v.push_back(va);
			if(s1.empty()) s1.insert(va);
			else if(va<=mid) s1.insert(va);
			else s2.insert(va);
			adjust();
		 }
		 
	}	
	return 0;
} 