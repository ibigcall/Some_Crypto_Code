#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;
class key
{
	public:
	int modul;
	int exp;
};
class money
{
	public:
	int Amount;
	bool Grant;
	long int M1;
	int S;
};
int main(int argc, char *argv[]) 
{
	int BankTotalMoney, UserTotalMoney;
	cout<<"Honorable Bank, please, enter your amount of money:\n"; //Ввод всех денег банка
	cin>>BankTotalMoney;
	cout<<"Honorable User, please, enter your amount of money:\n"; //Ввод денег, нужных юзеру
	key Alice;
	key Bob;
	cin>>UserTotalMoney;
	int PublicExp=rand()%10+1; //генерация части открытого ключа
	cout<<"____ "<< PublicExp<<" _____\n";
	int Masked, CounterOfAmountMoney;
	
	Alice.exp=PublicExp;  //ключ юзера
	PublicExp=rand()%10+1;
	cout<<"____ "<< PublicExp<<" _____\n";
	Bob.exp=PublicExp; //ключ банка
	Alice.modul=UserTotalMoney; //закрытый ключ юзера
	Bob.modul=3; // Закрытый ключ банка
	
	Masked=UserTotalMoney;
	money UserRequest;    											
	money GetRequest;
	UserRequest.Amount=UserTotalMoney;							
	GetRequest.Amount=BankTotalMoney;
	CounterOfAmountMoney=0;
	/*for(int i=UserRequest.Amount; i>1; i--)		//проверка на взаимную простоту/генерация взаимно простых чисел
	{
		int a=BankTotalMoney;
		int b=i;
		while( b^=a^=b^=a%=b );
		if(a==1)
		{
			Masked=i;
			break;
			cout<<"BLA BLA BLA: "<<i<<"\n";
		}
		CounterOfAmountMoney++;
	}*/
	Masked=11;
	UserRequest.Amount=UserTotalMoney; 		
	UserRequest.M1=pow(Masked,Bob.exp);
	cout<<"\n"<<UserRequest.M1<<"    ___   "<<Alice.exp<<"   ____   "<<Bob.exp<<" ___\n";
	UserRequest.M1=UserRequest.M1 % Alice.exp;
	cout<<"User's part of the key: "<<UserRequest.M1<<"\n";
	GetRequest.M1=UserRequest.M1;											//весь алгоритм подписи
	GetRequest.S=pow(GetRequest.M1, Bob.modul);
	GetRequest.S=GetRequest.S%Bob.exp;
	cout<<"Bank makes a key's layer: "<<GetRequest.S<<"\n";								//банк подписывает транзикацию
	UserRequest.S=GetRequest.S;
	UserRequest.S=GetRequest.S * pow(Masked, -1);  						//пользователь расшифровывает подпись
	UserRequest.S=UserRequest.S % Alice.exp;	
	cout<<"User decodes a key: "<<UserRequest.S<<"\n";	
	if(UserRequest.S==0)						
	{
		UserTotalMoney=UserRequest.Amount;
		UserRequest.Grant=true;									//если подпись есть, то транзикацию успешна(сторона юзера) и юзер получил деньги
	}
	if(UserRequest.Grant==true)
	{
		BankTotalMoney=GetRequest.Amount-UserRequest.Amount;			//пользователь получил деньги, у банка они отнимаются
		cout<<"Now Bank has "<<BankTotalMoney<<"\nUser now has "<<UserTotalMoney;	
	}
	}
