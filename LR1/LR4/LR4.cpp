// LR4.cpp : Операторы цикла, перехода и указатели.
/*Указатель -  переменная, хранящая адрес (смещение) каких-либо данных, переменных в оперативной памяти.
Указатель *
1. Синтаксис
объявления указателей тип_данных * имя_указателя; */
// фактически указатель - это unsigned int или unsigned long long(64) c адресом, так как дробных или отрицательных адресов нет


#include "pch.h"
#include <iostream>

int main()
{
	//2. Размер указателя
//все указатели всегда одной и той же разрядности (размера)
	//каким бы ни был огромным тип данных (строка, объект, массив)
	//указатель на него всегда будет занимать 4/8 байт, что и является основным преимуществом указателей
	//std::cout << "int pointer size = " <<sizeof(ptr_int) << std::endl;
	std::cout << "int pointer size = " << sizeof(int*) << std::endl;
	std::cout << "double pointer size = " << sizeof(double*) << std::endl;
	std::cout << "char pointer size = " << sizeof(char*) << std::endl;
	std::cout << "long long pointer size = " << sizeof(long long*) << std::endl;
	std::cout << "bool pointer size = " << sizeof(bool*) << std::endl << std::endl << std::endl;


	int arr1D[10] = { 1, 50, 11, 12, 101 };
	int arr2D[3][3] =
	{ {11, 12, 13},
	  {21, 22, 23},
	  {31, 32, 33} };

	std::cout << "arr = " << arr1D << std::endl;
	std::cout << "*arr = arr[0] = " << *arr1D << std::endl;
	std::cout << "*(arr+4) = arr[4] = " << *(arr1D + 4) << std::endl;


}