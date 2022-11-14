#include<iostream>
#include<string>
using namespace std;
struct field
{
	string type;
	int num;
};
struct node
{
	field fd;
	node* next;
};
int main()
{
	int n = 0;
	cin >> n;
	if (n == 0)
	{
		return 0;
	}
	else
	{
		node* first = new node;
		string s1;
		cin >> s1;
		first->fd.type = s1;
		first->fd.num = 1;
		first->next = nullptr;
		for (int i = 1;i < n;i++)
		{
			int flag = 1;
			node* now = first;
			cin >> s1;
			while (now->next != nullptr)
			{
				if (now->fd.type == s1)
				{
					now->fd.num++;
					flag = 0;
					now = now->next;
					break;
				}
				now = now->next;
			}
			if (now->fd.type == s1)
			{
				now->fd.num++;
			}
			if((now->fd.type != s1)&&(flag))
			{
				node* newnode = new node;
				newnode->fd.type = s1;
				newnode->fd.num = 1;
				now->next = newnode;
				newnode->next = nullptr;
			}
		}
		cin >> n;
		while (n != 0)
		{
			string s2;
			for (int i = 0;i < n;i++)
			{
				int flag = 1;
				node* now = first;
				cin >> s2;
				while (now->next != nullptr)
				{
					if (now->fd.type == s2)
					{
						now->fd.num++;
						flag = 0;
						now = now->next;
						break;
					}
					now = now->next;
				}
				if (now->fd.type == s2)
				{
					now->fd.num++;
				}
				if ((now->fd.type != s2) && (flag))
				{
					node* newnode = new node;
					newnode->fd.type = s2;
					newnode->fd.num = 1;
					now->next = newnode;
					newnode->next = nullptr;
				}
			}
			cin >> n;
		}
		node* p = first;
		int max = 0;
		while (p != nullptr)
		{
			if (p->fd.num > max)
			{
				max = p->fd.num;
			}
			p = p->next;
		}
		p = first;
		while (p != nullptr)
		{
			if (p->fd.num == max)
			{
				cout << p->fd.type << endl;
			}
			p = p->next;
		}
		delete first;
	}
	return 0;
}