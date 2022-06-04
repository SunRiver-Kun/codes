#pragma once
#include <memory>
#include <xstring>
#include <queue>
#include <stack>

namespace sr
{
	template <typename _Ty>
	struct Node
	{
		using value_type = _Ty;
		using point_type = Node<_Ty>*;

		_Ty value;
		point_type leftchild;
		point_type rightchild;

		Node(const value_type& value, point_type leftchild = nullptr, point_type rightchild = nullptr) :
			value(value), leftchild(leftchild), rightchild(rightchild) {}

		virtual ~Node() noexcept = default;

		virtual void visit()
		{
			std::cout << value << std::endl;
		}
	};

	template <typename _Ty, class _Node = Node<_Ty>>
	class Tree
	{
	public:
		using value_type = _Ty;
		using node_type = _Node;
		using node_point = node_type*;

		Tree() = default;

		virtual ~Tree() noexcept
		{
			if (!m_top) { return; }
			std::queue<node_point> nodes;
			nodes.push(m_top);
			while (nodes.size())
			{
				node_point node = nodes.front();
				nodes.pop();

				if (node->leftchild) { nodes.push(node->leftchild); }
				if (node->rightchild) { nodes.push(node->rightchild); }
				delete node;
			}
		}

		//ǰ�����
		void TraversePreorder()
		{
			if (empty()) { return; }
			std::stack<node_point> nodes;
			nodes.push(m_top);
			while (nodes.size())
			{
				node_point node = nodes.top();
				nodes.pop();

				node->visit();
				if (node->rightchild) { nodes.push(node->rightchild); }
				if (node->leftchild) { nodes.push(node->leftchild); }
			}
		}

		//�������
		void TraverseInorder()
		{
			if (empty()) { return; }
			std::stack<node_point> nodes;
			// nodes.push(m_top);
			node_point root = m_top;

			while(nodes.size() || root)
			{
				if(root)
				{
					nodes.push(root);
					root = root->leftchild;
				}
				else
				{
					root = nodes.top();
					nodes.pop();
					root->visit();
					root = root->rightchild;
				}
			}

			// bool leftcheck = m_top->leftchild != nullptr;
			// while (nodes.size())
			// {
			// 	node_point node = nodes.top();
			// 	if (leftcheck)
			// 	{
			// 		while (node->leftchild)
			// 		{
			// 			nodes.push(node->leftchild);
			// 			node = node->leftchild;
			// 		}
			// 		leftcheck = false;
			// 	}

			// 	node->visit();
			// 	nodes.pop();

			// 	if (node->rightchild)
			// 	{
			// 		node = node->rightchild;
			// 		nodes.push(node);
			// 		leftcheck = node->leftchild != nullptr;
			// 	}
			// }
		}

		//�������
		void TraversePostorder()
		{
			if (empty()) { return; }
			std::stack<node_point> nodes;
			nodes.push(m_top);
			bool leftcheck = m_top->leftchild != nullptr;
			node_point lastnode = nullptr;

			while (nodes.size())
			{
				node_point node = nodes.top();
				if (leftcheck)
				{
					while (node->leftchild)
					{
						nodes.push(node->leftchild);
						node = node->leftchild;
					}
					leftcheck = false;
				}

				if (node->rightchild && node->rightchild != lastnode)
				{
					node = node->rightchild;
					nodes.push(node);
					leftcheck = node->leftchild != nullptr;
				}
				else
				{
					node->visit();
					nodes.pop();
					lastnode = node;
				}
			}
		}

		//������ȱ���
		//������һ���ٵ���һ��
		void TraverseBFS()
		{
			if (empty()) { return; }
			std::queue<node_point> nodes;
			nodes.push(m_top);
			while (nodes.size())
			{
				node_point node = nodes.front();
				nodes.pop();

				node->visit();
				if (node->leftchild) { nodes.push(node->leftchild); }
				if (node->rightchild) { nodes.push(node->rightchild); }
			}
		}

		node_point top() const noexcept { return m_top; }
		size_t size() const noexcept { return m_size; }
		bool empty() const noexcept { return size() == 0; }

		void insert(const value_type& value)
		{
			++m_size;
			if (!m_top) { m_top = new node_type(value); return; }
			node_point parent = m_top;
			while (true)
			{
				if (value < parent->value)
				{
					if (parent->leftchild)
					{
						parent = parent->leftchild;
					}
					else
					{
						parent->leftchild = new node_type(value);
						return;
					}
				}
				else
				{
					if (parent->rightchild)
					{
						parent = parent->rightchild;
					}
					else
					{
						parent->rightchild = new node_type(value);
						return;
					}
				}
			}
		}

	private:
		node_point m_top = nullptr;
		size_t m_size = 0;
	};
}