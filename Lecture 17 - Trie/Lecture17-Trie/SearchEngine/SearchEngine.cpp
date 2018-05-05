#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 26

struct node {
	node *child[MAX];
	int countLeaf;
	int weight;
};

node *newNode()
{
	node *Node = new node;
	Node->countLeaf = 0;
	Node->weight = -1;

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

void addWord(node *root, string s, int w)
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
		temp->weight = max(w, temp->weight);
		temp = temp->child[ch];
	}
	temp->countLeaf++;
	//temp->weight = w;
}

bool findWord(node *root, string s)
{
	int ch;
	node *temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL)
		{
			return false;
		}
		temp = temp->child[ch];
	}
	return temp->countLeaf > 0;
}


int searchByTheMissingWord(node *pNode)
{
	int maxW = 0;

	if (isEmpty(pNode) && isWord(pNode))
	{
		return pNode->weight;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (pNode->child[i] != NULL)
		{
			maxW = max(searchByTheMissingWord(pNode->child[i]), maxW);
		}
	}
	return maxW;
}

int search(node *root, string s)
{
	int ch;
	node *temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL)
		{
			return -1;
		}
		temp = temp->child[ch];
	}
	
	return searchByTheMissingWord(temp);
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
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;

	int w;
	node *root = newNode();
	
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		cin >> w;
		addWord(root, str, w);

	}

	for (int i = 0; i < q; i++)
	{
		string str;
		cin >> str;
		int maxW = search(root, str);
		cout << maxW << endl;
	}

	return 0;
}
