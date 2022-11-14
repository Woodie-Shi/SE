#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<int>data(0);
	vector<string>st(0);
	string s;
	int len = 0;
	int count = 0;
	while (cin>>s&&s != "==")
	{
		st.push_back(s);
		len = s.length();
		data.push_back(len);
		count++;
	}
	int max = -1;
	int min = 1e7;
	for (int i = 0;i < count;i++)
	{
		if (data[i] > max)
		{
			max = data[i];
		}
		if (data[i] < min)
		{
			min = data[i];
		}
	}
	for (int i = 0;i < count;i++)
	{
		if (data[i] == min)
		{
			cout << st[i] << endl;
		}
	}
	for (int i = 0;i < count;i++)
	{
		if (data[i] == max)
		{
			cout << st[i] << endl;
		}
	}
}

