#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <ctime>
#include <unistd.h>

using namespace std;
int main(int argc, char *argv[]) 
{
	//init();
	
	
	int howmuchdocs;
	int MassOfNum[100];
	
	string line;
	string text;
	ifstream myfile ("Cypher.txt");
 
	if (myfile.is_open())
	{
		while (! myfile.eof() )
		{
			getline (myfile,line);
			text += line;
			text+="\n";
			
		}
		myfile.close();
	}
	    else cout << "Unable to open file"; 
		cout<<text;
		ofstream fout1("Key.txt");
		cout<<"How much documents you wanna see?\n";
		cin>>howmuchdocs;
		fout1<<howmuchdocs<<"\n";
		cout<<"Which numbers do you want to get?\n";
		for(int i=0; i<howmuchdocs; i++)
		{
			cin>>MassOfNum[i];
			fout1<<MassOfNum[i]<<"\n";
		}
		fout1.close();
		string text2;
		string line2;
		here:
		
			ifstream myfile2 ("Cypher2.txt");
				if (myfile2.is_open())
				{
					while (! myfile2.eof() )
					{
						getline (myfile2,line2);
						text2 += line2;
						text2+="\n";
						
						
					}
					myfile2.close();
				}
				else 
				{
					sleep(20);
					goto here;
					myfile2.close();
				}
				ofstream fout2("Key2.txt");
			cout<<text2<<"\n";
				char ifer;
					Breakpoint:
					cout<<"Do you want to sign this message?(Y/N)\n";
					cin>>ifer;
					if(ifer=='y' || ifer=='Y')
					{
						fout2<<"1";
						fout2.close();
						cout<<"Thank you. Good bye!\n";
						remove("Cypher2.txt");
						return 0;
					}
					else if(ifer=='n' || ifer=='N') 
					{
						cout<<"Thank you. Good bye!\n";
						fout2<<"0";
						fout2.close();
						remove("Cypher2.txt");
						return 0;
					}
					else {
						cout<<"Incorrect!!!\n";
						goto Breakpoint;
					}
}