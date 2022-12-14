#include<iostream>
using namespace std;
int main(void){
	char a;
	cin>>a;
	if(a>=65&&a<=90)
		a=a+32;
	else
		a=a-32;
	cout<<a;
}