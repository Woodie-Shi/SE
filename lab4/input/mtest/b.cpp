#include<iostream>
constexpr auto M = 9999999;
using namespace std;
struct biint
{
	int id;
	int grade;
};
void m_swap(biint& b1, biint& b2)
{
	int Temp = 0;
	Temp = b1.id;
	b1.id = b2.id;
	b2.id = Temp;
	Temp = b1.grade;
	b1.grade = b2.grade;
	b2.grade = Temp;
}
int main()
{
	int n = 0;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	biint* data = new biint[M];
	int size = 0;
	char fz{};
	int index = 0;
	while (n != 0)
	{
		for (int i=index;i < index+n - 1;i++)
		{
			biint temp{};
			cin >> temp.id >> fz >> temp.grade >> fz >> fz >> fz;
			data[i].id = temp.id;
			data[i].grade = temp.grade;
		}
		biint temp{};
		cin >> temp.id >> fz >> temp.grade;
		data[index + n - 1].id = temp.id;
		data[index + n - 1].grade = temp.grade;
		size += n;
		index = size;
		cin >> n;
	}
	for (int i = 0;i < size - 1;i++)
	{
		for (int j = 0;j < size - i - 1;j++)
		{
			if (data[j].id > data[j + 1].id)
			{
				m_swap(data[j], data[j + 1]);
			}
		}
	}
	cout << size << " ";
	for (int i = 0;i < size - 1;i++)
	{
		cout << data[i].id << ":" << data[i].grade << "-->";
	}
	cout << data[size - 1].id << ":" << data[size - 1].grade;
	delete[]data;
	return 0;
}