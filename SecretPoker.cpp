#include <iostream>
#include <ctime>
using namespace std;
int main(int argc, char *argv[]) 
{
	int MassOfCards[10], AliceMassOfKeys[10], BobMassOfKeys[10], ChooseDestini[2], ChooseDestini2[2], AliceMassOfCards[2], BobMassOfCards[2];
	int keyAlice, keyBob;
	cout<<"Bob and Alice, enter the cards:\n";
	for(int i=0; i<10; i++)
	{
		cin>>MassOfCards[i];
	}
	cout<<"Alice, please enter your Key:\n";
	cin>>keyAlice;
	for(int i=0; i<10; i++)
	{
		MassOfCards[i]=MassOfCards[i]*keyAlice;
		cout<<".";
	}
	random_shuffle(MassOfCards, MassOfCards + sizeof(MassOfCards)/sizeof(*MassOfCards));
	cout<<"\nBob, please enter your Key:\n";
	cin>>keyBob;
	for(int i=0; i<10; i++)
		{
			MassOfCards[i]=MassOfCards[i]*keyBob;
			cout<<".";
		}
	random_shuffle(MassOfCards, MassOfCards + sizeof(MassOfCards)/sizeof(*MassOfCards));
	for(int i=0; i<10; i++)
	{
		
		AliceMassOfKeys[i]=rand()%10+1;
		BobMassOfKeys[i]=rand()%10+1;
		cout<<".";

	}
	for(int i=0; i<10; i++)
			{
				MassOfCards[i]=MassOfCards[i]/keyAlice;
				MassOfCards[i]=MassOfCards[i]*AliceMassOfKeys[i];
				cout<<".";
			}
	for(int i=0; i<10; i++)
			{
				MassOfCards[i]=MassOfCards[i]/keyBob;
				MassOfCards[i]=MassOfCards[i]*BobMassOfKeys[i];
				cout<<".";
			}
	cout<<"\n\nTracing is complieted!\n\nHere are your cards:\n";
	for(int i=0; i<10; i++)
	{
		cout<<MassOfCards[i]<<", ";
	}
	cout<<"\nAlice, please choose two cards(Enter their serial numbers from 1 to 10): \n";
	cin>>ChooseDestini[0];
	cin>>ChooseDestini[1];
	for(int i=0; i<2; i++)
	{
		AliceMassOfCards[i]=MassOfCards[ChooseDestini[i]-1];
		swap(MassOfCards[ChooseDestini[i]-1],MassOfCards[9-i]);
		swap(BobMassOfKeys[ChooseDestini[i]-1],BobMassOfKeys[9-i]);
		swap(AliceMassOfKeys[ChooseDestini[i]-1],AliceMassOfKeys[9-i]);
		
	}
	cout<<"\nCard deck:\n";
		for(int i=0; i<8; i++)
			{
				cout<<MassOfCards[i]<<", ";
			}
	cout<<"\nBob, please choose two cards(Enter their serial numbers from 1 to 8): \n";
	cin>>ChooseDestini2[0];
	cin>>ChooseDestini2[1];
		for(int i=0; i<2; i++)
		{
			BobMassOfCards[i]=MassOfCards[ChooseDestini2[i]-1];
			swap(MassOfCards[ChooseDestini2[i]-1],MassOfCards[7-i]);
			swap(BobMassOfKeys[ChooseDestini2[i]-1],BobMassOfKeys[7-i]);
			swap(AliceMassOfKeys[ChooseDestini2[i]-1],AliceMassOfKeys[7-i]);
			
		}
	cout<<"\n";
	cout<<"\nBob cards(encrypted):"<<BobMassOfCards[0]<<" , "<<BobMassOfCards[1]<<"\n";
	cout<<"\nAlice cards(encrypted):"<<AliceMassOfCards[0]<<" , "<<AliceMassOfCards[1]<<"\n";
	cout<<"\nBob cards(decrypted by Bob):"<<BobMassOfCards[0]/BobMassOfKeys[9]<<" , "<<BobMassOfCards[1]/BobMassOfKeys[8]<<"\n";
	cout<<"\nAlice cards(decrypted by Alice):"<<AliceMassOfCards[0]/AliceMassOfKeys[9]<<" , "<<AliceMassOfCards[1]/AliceMassOfKeys[8]<<"\n";
	cout<<"\nBob cards(fully decrypted):"<<BobMassOfCards[0]/BobMassOfKeys[7]/AliceMassOfKeys[7]<<" , "<<BobMassOfCards[1]/BobMassOfKeys[6]/AliceMassOfKeys[6]<<"\n";
	cout<<"\nAlice cards(fully decrypted):"<<AliceMassOfCards[0]/AliceMassOfKeys[9]/BobMassOfKeys[9]<<" , "<<AliceMassOfCards[1]/AliceMassOfKeys[8]/BobMassOfKeys[8]<<"\n";

}