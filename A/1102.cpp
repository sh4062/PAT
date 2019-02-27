
#include<bits/stdc++.h>
using namespace std;
vector<int>vec,level;
struct node
{
	int data;
	int left,right;
}root[15];
struct Node 
{
	int data;
	Node *left,*right;
}*tree;
int digit[15];
Node* BuildTree(int x) 
{
	Node *tmp = new Node();
	tmp->data = x;
	tmp->left = tmp->right = NULL;
	if(root[x].left != -1)
		tmp->left = BuildTree(root[x].left);
	if(root[x].right != -1)
	tmp->right = BuildTree(root[x].right);
	return tmp;
}
void InvertInorter(Node* root)
{
	if(root)
	{
		InvertInorter(root->right);
		vec.push_back(root->data);
		InvertInorter(root->left);
	}
}
void LevelOrder(Node* tree)
{
	queue<Node*>qu;
	qu.push(tree);
	while(qu.empty()==0)
	{
		Node* tmp = qu.front();
		qu.pop();
		level.push_back(tmp->data);
		if(tmp->right!=NULL)
			qu.push(tmp->right);
		if(tmp->left!=NULL)
			qu.push(tmp->left);
		
	} 
	return ;
}
int main()
{
	int n;
    cin>>n;
    string a , b;;
 	for(int i = 0 ; i < n; i++)
	{
		cin>>a>>b;
		root[i].data = i;
		if(a!="-")
		{
			root[i].left = stoi(a);
			digit[stoi(a)]++;
		}	
		else 
			root[i].left = -1;
			
		if(b!="-")
		{
			root[i].right = stoi(b);
			digit[ stoi(b)]++;
		}	
		else 
			root[i].right = -1;
	}
	//找根
	int top = -1;
	for(int i = 0 ; i < n;i ++)
	{
		if(digit[i] == 0)
		{
			top = i;
			break;
		}	
	}
	//找到根之后就可以开始建树
	tree = BuildTree(top);
	//层序
	LevelOrder(tree);
	for(int i = 0 ; i < n; i ++)
		printf("%d%c",level[i]," \n"[i==n-1]);
	//翻转 
	InvertInorter(tree);
	for(int i = 0 ; i < n; i ++)
		printf("%d%c",vec[i]," \n"[i==n-1]);
	return 0;
}
