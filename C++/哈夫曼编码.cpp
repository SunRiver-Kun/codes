#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//哈夫曼编码，压缩算法的一种

typedef vector<bool> HuffCode;	//01010101..
typedef map<char, HuffCode> HuffCodeMap;

struct INode
{
public:
	const int f;	//频率
	virtual ~INode() noexcept {}
protected:
	INode(int f) :f(f) {}
};

//分支结点
class InternalNode : public INode
{
public:
	INode* left, * right;
	InternalNode(INode* left, INode* right) : INode(left->f + right->f), left(left), right(right) {}
	~InternalNode()
	{
		delete left;
		delete right;
	}
};

//叶子结点
class LeftNode : public INode
{
public:
	const char c;
	LeftNode(int f, char c) : INode(f), c(c) {}
};

//大的在后
struct NodeCmp
{
	bool operator()(const INode* a, const INode* b) { return a->f > b->f; }
};

INode* BuildTree(const map<char, int>& frequence)
{
	priority_queue<INode*, vector<INode*>, NodeCmp> trees;
	for(auto& v : frequence)
	{
		trees.push(new LeftNode(v.second, v.first));
	}
	while(trees.size() > 1)
	{
		INode* left = trees.top();
		trees.pop();
		INode* right = trees.top();
		trees.pop();

		trees.push(new InternalNode(left, right));
	}
	return trees.top();
}

void GenerateCodes(const INode* node, HuffCode& code, HuffCodeMap& out_codes)
{
	if(const LeftNode* leftnode = dynamic_cast<const LeftNode*>(node))
	{
		out_codes[leftnode->c] = code;
	}
	else if(const InternalNode* inode = dynamic_cast<const InternalNode*>(node))
	{
		code.push_back(0);
		GenerateCodes(inode->left, code, out_codes);
		code.pop_back();

		code.push_back(1);
		GenerateCodes(inode->right, code, out_codes);
		code.pop_back();
	}
}

void PrintRoot(INode* root)
{
	queue<INode*> nodes;
	nodes.push(root);

	int num = 0;
	while(nodes.size())
	{
		if(num == 0) { num = nodes.size(); }
		INode* node = nodes.front();
		nodes.pop();
		--num;

		if(const InternalNode* inode = dynamic_cast<const InternalNode*>(node))
		{
			cout << inode->f << "\t";
			if(inode->left) { nodes.push(inode->left); }
			if(inode->right) { nodes.push(inode->right); }
		}
		else if(const LeftNode* leftnode = dynamic_cast<const LeftNode*>(node))
		{
			cout << leftnode->c<< "_" << leftnode->f << "\t";
		}
		
		if(num == 0) { cout << endl; }
	}
}


int main()
{
	map<char, int> frequence;
	cout << "请输入文本数据：";
	string str;
	cin >> str;
	for(auto& v : str)
	{
		auto it = frequence.find(v);
		if(it != frequence.end())
			it->second = it->second + 1;
		else
			frequence[v] = 1;
	}

	INode* root = BuildTree(frequence);
	PrintRoot(root);
	HuffCode code;
	HuffCodeMap codes;
	GenerateCodes(root, code, codes);
	delete root;

	for(auto& v : codes)
	{
		cout << v.first << " ";
		for(int i = 0; i < v.second.size(); ++i)
		{
			cout << v.second[i];
		}
		cout << endl;
	}

	return system("pause");
}#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//哈夫曼编码，压缩算法的一种

typedef vector<bool> HuffCode;	//01010101..
typedef map<char, HuffCode> HuffCodeMap;

struct INode
{
public:
	const int f;	//频率
	virtual ~INode() noexcept {}
protected:
	INode(int f) :f(f) {}
};

//分支结点
class InternalNode : public INode
{
public:
	INode* left, * right;
	InternalNode(INode* left, INode* right) : INode(left->f + right->f), left(left), right(right) {}
	~InternalNode()
	{
		delete left;
		delete right;
	}
};

//叶子结点
class LeftNode : public INode
{
public:
	const char c;
	LeftNode(int f, char c) : INode(f), c(c) {}
};

//大的在后
struct NodeCmp
{
	bool operator()(const INode* a, const INode* b) { return a->f > b->f; }
};

INode* BuildTree(const map<char, int>& frequence)
{
	priority_queue<INode*, vector<INode*>, NodeCmp> trees;
	for(auto& v : frequence)
	{
		trees.push(new LeftNode(v.second, v.first));
	}
	while(trees.size() > 1)
	{
		INode* left = trees.top();
		trees.pop();
		INode* right = trees.top();
		trees.pop();

		trees.push(new InternalNode(left, right));
	}
	return trees.top();
}

void GenerateCodes(const INode* node, HuffCode& code, HuffCodeMap& out_codes)
{
	if(const LeftNode* leftnode = dynamic_cast<const LeftNode*>(node))
	{
		out_codes[leftnode->c] = code;
	}
	else if(const InternalNode* inode = dynamic_cast<const InternalNode*>(node))
	{
		code.push_back(0);
		GenerateCodes(inode->left, code, out_codes);
		code.pop_back();

		code.push_back(1);
		GenerateCodes(inode->right, code, out_codes);
		code.pop_back();
	}
}

void PrintRoot(INode* root)
{
	queue<INode*> nodes;
	nodes.push(root);

	int num = 0;
	while(nodes.size())
	{
		if(num == 0) { num = nodes.size(); }
		INode* node = nodes.front();
		nodes.pop();
		--num;

		if(const InternalNode* inode = dynamic_cast<const InternalNode*>(node))
		{
			cout << inode->f << "\t";
			if(inode->left) { nodes.push(inode->left); }
			if(inode->right) { nodes.push(inode->right); }
		}
		else if(const LeftNode* leftnode = dynamic_cast<const LeftNode*>(node))
		{
			cout << leftnode->c<< "_" << leftnode->f << "\t";
		}
		
		if(num == 0) { cout << endl; }
	}
}


int main()
{
	map<char, int> frequence;
	cout << "请输入文本数据：";
	string str;
	cin >> str;
	for(auto& v : str)
	{
		auto it = frequence.find(v);
		if(it != frequence.end())
			it->second = it->second + 1;
		else
			frequence[v] = 1;
	}

	INode* root = BuildTree(frequence);
	PrintRoot(root);
	HuffCode code;
	HuffCodeMap codes;
	GenerateCodes(root, code, codes);
	delete root;

	for(auto& v : codes)
	{
		cout << v.first << " ";
		for(int i = 0; i < v.second.size(); ++i)
		{
			cout << v.second[i];
		}
		cout << endl;
	}

	return system("pause");
}