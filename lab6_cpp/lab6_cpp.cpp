#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <windows.h>  
#include "Lesson.h"
#include "Engine.h"
using namespace std;

int Client::clientCounter = 0;
int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	//Пример присваивания базового класса к производному(перегрузка = и <<)
	Auto car = Auto("Kia", "Rio", 1, "T345EC");
	Engine eng;
	eng = car;
	cout << eng; //Вывод объекта черех <<
	CarDetail* detail;
	detail = &eng;
	cout << detail->getDetailName() << endl;
	detail = new Engine();
	//Пример работы с шаблонным классом
	string t = "Больше тренировок на дроме";
	Lesson<string> lesson = Lesson<string>(Client(), Instructor(),"20.02.2024","13.00",1, t); //Комментария об уроке
	lesson.Print();
	cout << "Доп. Информация: " << lesson.getDopInfo()<<endl;
	Lesson<int> lesson2 = Lesson<int>(Client(), Instructor(), "10.03.2024", "17.30", 2, 15); //Кол-во часов практики
	lesson2.Print();
	cout <<"Доп. Информация: " << lesson2.getDopInfo() << endl;
}