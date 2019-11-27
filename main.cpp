// main.cpp

#include <stdio.h>
#include <iostream>
#include<clocale>
#include <conio.h>
#include <windows.h>
#include "command.h"
using namespace std;

double switch_0(double A);
double switch_1(double A);
int switch_2(int A);
int switch_3(int A);

int main(){
	setlocale(0,"Russian");
	system("mode con cols=200 lines=50");
	double  pType1, pReg ;
	int memTime, calcTime, num;
	cout << "Выбирете вероятность того, что векторы операнд находятся в регистре" << endl;
	cout << " 1)0.9\n 2)0.8\n 3)0.6 " << endl;
		cin >> pReg;
		pReg = switch_0(pReg);
	cout << "Вы выбрали: "<< pReg << endl;
	cout << "Выбирете вероятность того, что команда первого типа" << endl;
	cout << " 1)0.9\n 2)0.7\n 3)0.5 " << endl;
	cin >> pType1;
	pType1=switch_1(pType1);
	cout << "Вы выбрали: " << pType1 << endl;
	cout << "Выбирете количество тактов для обращения в память'" << endl;
	cout << "1)2\n 2)5\n 3)10 " << endl;
	cin >> memTime;
	memTime = switch_2(memTime);
	cout << "Вы выбрали: " << memTime << endl;
	cout << "Выбирете количество тактов для вычисления результата для команд вторго типа" << endl;
	cout << " 1)4\n 2)8\n 3)16 " << endl;
	cin >> calcTime;
	calcTime = switch_3(calcTime);
	cout << "Вы выбрали: " << calcTime << endl;
	cout << "Введите кол-во команд" << endl;
	cin >> num;
	cout << "Вы ввели: " << num << endl;
	cout << "Примечание: " << num << endl;
	cout << " K - чтение кода операции"<< endl;
	cout << " D - дешифрация"<< endl;
	cout << " R - обращаемся к регистру"<< endl;
	cout << " M - обращаемся к памяти"<< endl;
	cout << " _ - такт с нет операции"<< endl;

	
	Command *list;
	list = new Command[num];
	for(int i = 0; i < num; i++){
	
		Command bufcom;
		bufcom = bufcom.generate(pReg, pType1, memTime, calcTime);
		bufcom.getTimeMas();
		bufcom.appendShift(i);
		list[i] = bufcom;
	}
	 
	int maxsize = 0;
	for(int i = 0; i < num; i++){
		if (list[i].size > maxsize)
			maxsize = list[i].size;
	}

	
	for(int i = 0; i < num; i++){
		int val = maxsize - list[i].size;
		list[i].appendBack(val);
	}

	int isOneHere; 
	for(int i =0; i < maxsize; i++){
		isOneHere = 0;
		for(int j = 0; j < num; j++){
			if (list[j].time[i] == 1){ 
				if (isOneHere == 0){
					isOneHere = 1;
					continue;
				}
				if (isOneHere == 1){ 
					isOneHere = 2;
					continue;
				}
				if (isOneHere == 2){ 
					vector <int>::iterator start1;
					for (int k =0; k<list[j].time.size(); k++){
						if(list[j].time[k] == 1){
							start1 = list[j].time.begin() + k;
							break;
						}
					}
					list[j].size++;
					maxsize++;
					list[j].time.insert(start1, 3); 
					for(int r = 0; r < num; r++){ 
						if(r != j)
							list[r].size++;
							list[r].time.push_back(2);
					}
					
					for (int k =0; k<list[j].time.size(); k++){
						if(list[j].time[k] == 1){
							start1 = list[j].time.begin() + k;
							break;
						}
					}
					int bufi = i ;
				
					while(list[j].time[bufi] == 1){
						list[j].size++;
						list[j].time.insert(start1, 3); 
						for (int k =0; k<list[j].time.size(); k++){
							if(list[j].time[k] == 1){
								start1 = list[j].time.begin() + k;
								break;
							}
						}
					}
				}
			}
		}
	}

	
	int sum = 0, buftime;
	for(int i = 0; i < num; i++){
		buftime = list[i].getTime();
		sum += buftime;
	}
	int avtime = 0;
	avtime = sum / num; 

	for(int i = 0; i < num; i++){
		list[i].printNice();
	}
	cout << endl << "Среднее время: " << avtime << endl;

	delete []list;
	system("pause");
	return 0;
}
double switch_1(double A) {
	int a;
	a = A;
	switch (a)
	{
	case 1: 
		{
		return(0.9);
			break;
	}
 case 2:
 {
	 return(0.7);
	 break;
 }
 case 3:
 {
	 return(0.5);
	 break;
 } 
 default:
 {
	 cout << "Error:ошибка ввода" << endl;
	 _getch();
	 exit(0);
 }
}
}
double switch_0(double A) {
	int a;
	a = A;
	switch (a)
	{
	case 1:
	{
		return(0.9);
		break;
	}
	case 2:
	{
		return(0.8);
		break;
	}
	case 3:
	{
		return(0.6);
		break;
	}
	default:
	{
		cout << "Error:ошибка ввода" << endl;
		_getch();
		exit(0);
	}
	}
}
int switch_2(int A) {
	int a;
	a = A;
	switch (a)
	{
	case 1:
	{
		return(2);
		break;
	}
	case 2:
	{
		return(5);
		break;
	}
	case 3:
	{
		return(10);
		break;
	}
	default:
	{
		cout << "Error:ошибка ввода" << endl;
		_getch();
		exit(0);
	}
	}
}
int switch_3(int A) {
	int a;
	a = A;
	switch (a)
	{
	case 1:
	{
		return(4);
		break;
	}
	case 2:
	{
		return(8);
		break;
	}
	case 3:
	{
		return(16);
		break;
	}
	default:
	{
		cout << "Error:ошибка ввода" << endl;
		_getch();
		exit(0);
	}
	}
}