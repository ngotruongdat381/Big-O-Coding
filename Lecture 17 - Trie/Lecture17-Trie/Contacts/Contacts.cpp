#include <string>
#include <iostream>
using namespace std;

#define MAX 26

struct node {
	node *child[MAX];
	int countLeaf;
	int cnt;
};

node *newNode()
{
	node *Node = new node;
	Node->countLeaf = 0;
	Node->cnt = 0;

	for (int i = 0; i < MAX; i++)
	{
		Node->child[i] = NULL;
	}
	return Node;
}

void addWord(node *root, string s)
{
	int ch;
	node *temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL)
		{
			temp->child[ch] = newNode();
		}
		temp = temp->child[ch];
		temp->cnt++;
	}
	temp->countLeaf++;
}

int findWord(node *root, string s)
{
	int ch;
	node *temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL)
		{
			return 0;
		}
		temp = temp->child[ch];
	}
	return temp->cnt;

}

bool isWord(node *pNode)
{
	return (pNode->countLeaf != 0);
}

bool isEmpty(node *pNode)
{
	for (int i = 0; i < MAX; i++)
	{
		if (pNode->child[i] != NULL)
		{
			return false;
		}
	}
	return true;
}

bool removeWord(node *root, string s, int level, int len)
{
	if (!root)
		return false;

	int ch = s[level] - 'a';
	if (level == len)
	{
		if (root->countLeaf > 0)
		{
			root->countLeaf--;
			return true;
		}
		return false;
	}

	int flag = removeWord(root->child[ch], s, level + 1, len);
	if (flag && !isWord(root->child[ch]) && isEmpty(root->child[ch]))
	{
		delete root->child[ch];
		root->child[ch] = NULL;
	}
	return flag;
}


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	string operation, str;

	node *root = newNode();

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> operation >> str;

		if (operation == "add")
		{
			addWord(root, str);
		}
		else if (operation == "find")
		{
			cout << findWord(root, str) << endl;
		}
	}

	return 0;
}
