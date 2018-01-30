#include <iostream>
#include <string>

using namespace std;


int main(int argc, char *argv[]) {
	string a;
	
	cin>>a;
	char b[a.length()];
	char A[a.length()];
	for(int i=0; i<a.length(); i++)
	{
		A[i]=a[i];
	}
	char key=char(255);
	for(int i=0; i<a.length(); i++)
	{
		b[i] = (char) (a[i] ^ key);
	}
	for(int i = 0;i < a.length(); i++)
		b[i] -= 5;

	cout<<b<<"\n";
	for(int i = 0;i < a.length(); i++)
			b[i] += 5;

	for(int i=0; i<a.length(); i++)
		{
			A[i] = (char) (b[i] ^ key);
		}
	cout<<A<<"\n";
}