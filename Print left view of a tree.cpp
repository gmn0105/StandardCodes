#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
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
void printLeftView(struct node * root, int level, int * maxLevel)
{
	if(root==NULL)
		return;
	if(* maxLevel < level)
	{
		cout<<root->key<<" ";
		* maxLevel = level;
	}
	printLeftView(root->left, level+1, maxLevel);
	printLeftView(root->right, level+1, maxLevel);
}
void leftView(struct node * root)
{
	int maxLevel = 0;
	printLeftView(root, 1, &maxLevel);
}
int main()
{
	int a[9]={8, 3, 10, 1, 6, 4, 7, 14, 13};
	struct node * root = NULL;
	root = insert(root, a[0]);
	for(int i=1;i<=8;i++)
		root = insert(root, a[i]);
	leftView(root);
}
