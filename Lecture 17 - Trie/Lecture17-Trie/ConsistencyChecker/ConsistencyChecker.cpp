#include <string>
#include <iostream>
using namespace std;

#define MAX 10

struct node {
	node *child[MAX];
	int countLeaf;
};

node *newNode()
{
	node *Node = new node;
	Node->countLeaf = 0;
	for (int i = 0; i < MAX; i++)
	{
		Node->child[i] = NULL;
	}
	return Node;
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

bool addWord(node *root, string s)
{
	int ch;
	node *temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - '0';
		if (temp->child[ch] == NULL)
		{
			//Add
			if (temp->countLeaf > 0)
				return false;
			temp->child[ch] = newNode();
		}
		temp = temp->child[ch];
	}
	if (temp->countLeaf > 0)
		return false;

	temp->countLeaf++;
	
	//Add
	return isEmpty(temp);
}

bool findWord(node *root, string s)
{
	int ch;
	node *temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - '0';
		if (temp->child[ch] == NULL)
		{
			return false;
		}
		temp = temp->child[ch];
	}
	return temp->countLeaf > 0;
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

void deletenode(node *pNode)
{
	for (int i = 0; i<MAX; i++)
	{
		if (pNode->child[i])
		{
			deletenode(pNode->child[i]);
			delete pNode->child[i];
		}
	}
}



int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int T, n, count = 1;
	string str;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cout << "Case " << count++ << ": ";

		cin >> n;
		node *root = newNode();

		bool res = true;
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			if (res && !addWord(root, str))
				res = false;
		}

		if (res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		deletenode(root);

	}

	return 0;
}
