#include <iostream>
#include <math.h>
#include "time.h"
using namespace std;
class User //Класс пользователя
{
	public:
		int Name;
		int ControlSumm;
		int SecretPart;
		
};
int EasySearch(int min) //Вычисление простого числа для разделения секрета
{
	   int x,y;
		
		int max=min + 100;
		for(x=min+1;x<max;x++){
							for (y=2;y<=(x/y);y++)
							if (!(x%y)) break;
							if (y>(x/y)) return x;
							}
						   getchar ();
						   return 0;
}
void KeyGen(int Stepen, int UserCount, int ControlNumber, User UserMass[]) //Раздача ключей секрета
{
	int Koefficients[UserCount][Stepen];
	int kf[Stepen];
	for(int i=0; i<Stepen; i++)
	{
		kf[i]=rand()%100+1;
	}
	for(int i=0; i<UserCount; i++)
	{
		
		int StepenTime=Stepen;
		int TimeShift=0; //сохраняет временный результат
		while (StepenTime>0)
		{
			Koefficients[i][StepenTime]=kf[StepenTime-1];
			TimeShift+=(pow(UserMass[i].Name,StepenTime)*Koefficients[i][StepenTime]);
			StepenTime=StepenTime-1;
		}
		TimeShift+=ControlNumber;
		UserMass[i].ControlSumm = TimeShift % EasySearch(ControlNumber);
		
		
		
	}
}
void UserCreate(int UserCount, User UserMass[]) //Генарация пользователей
{
	for(int i=0; i<UserCount; i++) 
	{
		cin>>UserMass[i].Name;
	}

}
int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	int ControlNumber; // Секрет, который надо разделить
	int UserCount; //Всего пользователей
	int UserNeedCount; //Надо пользователей чтобы узнать изначальный секрет
	cout<<"Введите Секрет:\n";
	cin>>ControlNumber;
	cout<<"\nВведите количество пользователей:\n";
	cin>>UserCount;
	User UserMass[UserCount];
	cout<<"\nВведите количество пользователей, необходимое для восстановления секрета:\n";
	cin>>UserNeedCount;
	cout<<"\nВведите имена пользователей:\n";
	UserCreate(UserCount, UserMass);
    KeyGen(UserNeedCount-1, UserCount, ControlNumber, UserMass);
	
	for(int i=0; i<UserCount; i++) 
	{
		cout<<"Пользователь с именем: "<<UserMass[i].Name<<" имеет часть секрета равную "<<UserMass[i].ControlSumm<<". Ключ равен "<<EasySearch(ControlNumber)<<"."<<" Степень многочлена "<<UserNeedCount-1<<".\n";
	}
}
