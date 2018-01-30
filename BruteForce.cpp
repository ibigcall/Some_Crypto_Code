#include <iostream>
#include "math.h"
using namespace std;

int MASSFOEALL[1000];
int maincount=0;
int counteristic=0;

void Calculating(int MassOf1Coef[], int MassOf2Coef[], int key )
{
		
		for(int i=0; i<1000; i++)
		{
			for(int j=0; j<1000; j++)
			{
				for(int k=0; k<1000; k++)
				{
					if((((MassOf1Coef[counteristic]*MassOf1Coef[counteristic]*i)+(MassOf1Coef[counteristic]*j)+k)%key)==MassOf2Coef[counteristic])
					{
						if((((MassOf1Coef[counteristic+1]*MassOf1Coef[counteristic+1]*i)+(MassOf1Coef[counteristic+1]*j)+k)%key)==MassOf2Coef[counteristic+1])
						{
							if((((MassOf1Coef[counteristic+2]*MassOf1Coef[counteristic+2]*i)+(MassOf1Coef[counteristic+2]*j)+k)%key)==MassOf2Coef[counteristic+2])
							{
								
								MASSFOEALL[maincount]=k;
								maincount++;
							}
						}
					}
				}
			}
		}
		counteristic++;
		};
int main(int argc, char *argv[]) 
{
	int amount; // Количество коэффицентов/степень многочлена
	int key;
	cout<<"Enter amount of the coefficents:\n";
	cin>>amount;
	cout<<"Enter the key:\n";
	cin>>key; //ключ сообщения(общий для всех пользователей)
	if(amount<3)
	{
		cout<<"IMPOSSIBLE!!!!";
		return 0;
	}
	int MassOf1Coef[amount]; //первый коэффицент/имя пользователя
	int MassOf2Coef[amount]; //второй коэффицент/ключ пользователя
	
	for(int i=0; i<amount; i++)
	{
		cout<<"Enter the "<<i+1<<" pair of coefficents\n"; 
		cin>>MassOf1Coef[i];
		cin>>MassOf2Coef[i];
	}
	cout<<"Calculating...\n";
	int newkoef=amount-2;
	for(int i=0; i<newkoef; i++)
	{
		Calculating(MassOf1Coef, MassOf2Coef, key);
	}
	for(int i=0; i<maincount; i++)
	{
		for(int j=0; j<maincount; j++)
		{
			if(newkoef==1)
			{
				cout<<MASSFOEALL[0];
				return 0;
			}
			else
			{
				if(MASSFOEALL[i]==MASSFOEALL[j])
				{
					cout<<MASSFOEALL[i];
					return 0;
				}
			}
		}
	}
}