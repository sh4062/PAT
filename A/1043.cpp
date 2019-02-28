#include<iostream>
#include<vector>
using namespace std;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int num[10000], n;
node* Newnode(int x)
{
	node* newnode = new node;
	newnode->data = x;
	newnode->lchild = newnode->rchild = NULL;
	return newnode;
}
void insert(node* &root, int x)
{
	if (root == NULL)
	{
		root = Newnode(x);
		return;
	}
	if (x >= root->data)insert(root->rchild, x);
	else insert(root->lchild, x);
}
node* create(int num[], int n)
{
	node* root = NULL;
	for (int i = 0; i < n; i++)insert(root, num[i]);
	return root;
}
vector<int>pre, mirror_pre, post;
void preorder(node* root)
{
	if (root == NULL)return;
	pre.push_back(root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void mirrororder(node* root)
{
	if (root == NULL)return;
	mirror_pre.push_back(root->data);
	mirrororder(root->rchild);
	mirrororder(root->lchild);
}
bool issame(vector<int>pre)
{
	for (int i = 0; i < n; i++)
	{
		if (pre[i] != num[i])return false;
	}
	return true;
}
void postorder(node* root)
{
	if (root == NULL)return;
	postorder(root->lchild);
	postorder(root->rchild);
	post.push_back(root->data);
}
void postorder_mirror(node* root)
{
	if (root == NULL)return;
	postorder_mirror(root->rchild);
	postorder_mirror(root->lchild);
	post.push_back(root->data);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &num[i]);
	node* root = create(num, n);
	preorder(root);
	mirrororder(root);
	if(issame(pre)||issame(mirror_pre))
	{
		printf("YES\n");
		if (issame(pre))
			postorder(root);
		else if (issame(mirror_pre))
			postorder_mirror(root);
		for (int i = 0; i < post.size(); i++)
		{
			printf("%d", post[i]);
			if (i != post.size() - 1)printf(" ");
		}
	}
	else printf("NO");
	return 0;
}
 