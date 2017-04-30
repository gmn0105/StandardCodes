#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int min = 100;
struct node
{
	int key;
	struct node * left;
	struct node * right;
};
struct node * newNode(int key)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * insert(struct node * root, int key)
{
	if(root==NULL)
	{
		return newNode(key);
	}
	if(key<=root->key)
	{
		root->left = insert(root->left, key);
	}
	else
	{
		root->right = insert(root->right, key);
	}
	return root;
}
void closest(struct node * root, int n)
{
	if(root==NULL)
		return;
	if(root->key==n)
	{
		min = 0;
	}
	else if(n<root->key)
	{
		if(abs(n-root->key)<min)
		{
			min = abs(n-root->key);
		}
		closest(root->left, n);
	}
	else
	{
		if(abs(n-root->key)<min)
		{
			min = abs(n-root->key);
		}
		closest(root->right, n);
	}
}
int main()
{
	int a[9]={8, 3, 10, 1, 6, 4, 7, 14, 13};
	struct node * root = NULL;
	root = insert(root, a[0]);
	for(int i=1;i<=8;i++)
		root = insert(root, a[i]);
	closest(root, n);
	cout<<min<<endl;
}
