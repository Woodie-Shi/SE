#include<iostream>
#include<cctype>
using namespace std;
int main(void){
	char a;
	cin>>a;
	if(islower(a))
		a=toupper(a);
	else
		a=tolower(a);
	cout<<a;
}