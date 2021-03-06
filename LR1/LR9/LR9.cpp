// LR9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

//Перегрузка - объявление функций (а также методов классов и операторов, которые тоже являются функциями)
//с одинаковыми именами, но разным набором аргументов

//бинарные и унарные операторы

using namespace std;

double fnc1(double p1, char p2)
{
	cout << "fnc1 (double, char)" << endl;
	return p1 + p2;
}

int fnc1(int p1, char p2)
{
	cout << "fnc1 (int, char)" << endl;
	return p1 + p2;
}


/* различие функций по одному выходному параметру не является перегрузкой
для компилятора критерием является сигнатура функции имя + последовательность аргументов + их типы
даже если аргументы имеют разные названия, но типы к последоательности одинаковые 
компилятор считает такой случай не перегрузкой, а повторным объявлением, что является ошибкой:
int fnc1 (double a, char b)
{
	cout << "fnc1 (double, char)" << endl;
	return a -b;
}*/

/*
для компилятора критерием является сигнатура функции имя + последовательность + их типы
даже если аргументы имеют разные названия, но типы их последовательность одинаковые
*/

int fnc1(int p1, short p2)
{
	cout << "fnc1 (int, short)" << endl;
	return p1 + p2;
}

int fnc1(long long p1, long long p2)
{
	cout << "fnc1 (long long, long long)" << endl;
	return p1 + p2;
}

//методы класса перегружаются точно так же, как и обычные функции
class sample_class
{
public:
	sample_class()
	{


	}

	int property1; // property - свойство
	double property2;

	int fnc1(double p1, char p2)
	{
		cout << "sample_class::fnc1 (double, char)" << endl;
		return p1 + p2;
	}


	int fnc1(int p1, short p2)
	{
		cout << "sample_class::fnc1 (int, short)" << endl;
		return p1 + p2;
	}

	//компилятор ищет точные совпадения типов аргументов, если не нашел,
	// oH пытается использовать приведение типов (char -> int, ...) и снова ищет совпадения.
	// Если не нашел, использует стандартные преобразования типов (все указатели в void, float -> double, double -> int, ...)
	//При перегрузке модет возникнуть неоднозначность
	// fnc1 (0, 'b');



	/*
	int main()
	{
	...
	matr A, B, C;
	...
	A.sum(B);
	// C = A + B; - overload operator +
	...
	return 0;
	}
	*/


	//унарные и бинарные операторы перегружаются по-разному
		// унарные - в самом классе (полчается новый метод класса)
		//бинарные - как отдельную функцию


		// бинарные операторы прописываются вне класса, так как результат не обязательно
		//записывается в один из операндов, а может записываться  в некий третий объект

		//в унарных операторах результат записываетс в тот же самый объект
		// для которого вызван оператор, поэтому стоит отнести к методам класса 
	sample_class & operator += (const sample_class & operand)
		//здесь const - "защита от забывчивости" - не дает изменить внутри метода операнд,
		//который по логике и не должен менться
	{
		property1 = property1 + operand.property1;
		this->property2 = this->property2 + operand.property2; // c this эффект не меняется

		return (*this);


		//бинарные и унарные операторы
		// оператор = пишется внутри класса
		// ввод вывод пишется как дружественный оператор
		//унрный в самом классе, бинарный вне класса

		//результат записывается в один из операнов или некий третий объект 




		/*
		matrix & operator += (matrix & second_matr)
		{
			for (int )
			this -> setElem(i, j, first_matr[i][j] + second_matr.getElem(i, j))
			return *this;
		}
		*/


		//запомнить, может пригодиться:
		sample_class & operator += (std::string p1) //приходит строка формата 10.5 100500
		{
			double x[2] = { 0 };
			stringstream sstream(p1); //создается поток ввода/вывода в строки и заполняется пришедшей строкой 
			//(вызывется копирующий конструктор)
			sstream >> x[0] >> x[1];
			//бинарный оператор >> переводит строку в тип, который имеет правосторонний операнд 
			property1 = property 1 + operand.property1;
			this->property2 = this->property2 + operand.property2; // c this эффект не меняется
			return (*this);
		}
	}


	/*
	общий синтаксис перегрузки операторов:
	тип operator символ_оператора (тип имя_параметра, тип имя_параметра, ...)
	{

	}*/

	sample_class & operator -= (const sample_class & operand);
};


//операторы перегружвются для нестандартных, пользовательских типов, классов
//для некоторых сам компиллятор "не знает" какие действия применять
//в этом случае пользователь сам приписывает требуемые от оператора действия

// возврат.тип | имя функции | список параметров

sample_class operator + (const sample_class & lhs, // left hand side
	const sample_class & rhs) // right hand side

{
	sample_class result; // создать новый объект для записи результатов
// собственно сложение 
	result.property1 = lhs.property1 + rhs.property1;
	result.property2 = lhs.property2 + rhs.property2;

	return result;
}


ostream & operator << (ostream & os, //лeвосторонний операнд, cout
	sample_class & rhs) // правосторонний операнд, собственно то, что выводится 
{
	os << "sample_class:" << endl;
	os << "\tproperty1 = " << rhs.property1 << ";" << endl;
	os << "\tproperty2 = " << rhs.property2 << ";" < , endl;
	return os;
}
//sample_class aaa;
//cout << aaa;













class matrix
		{
		private:
			double matr[10][10];
			int rows;
			int columns;
		public:

			matrix();
			~matrix();

			bool input();
			bool print();
			bool summMatrix(matrix matr2);

			int getRows()
			{
				return rows;
			}
			int getColumns()
			{
				return columns;
			}
			double getElem(int row, int col)
			{
				if (row < rows && col<columns && row>-1 && col>-1)
				{
					return matr[row][col];
				}
				std::cout << "Index Error\n";
				return -1111111111;
			}
		};


int main()
{
	/*matrix matrA, matrB, matrC;

	matrA += matrB; // matrA.add(matrB)
	matrA.input();
	matrA.print();

	return 0;
	*/
}


bool matrix::input()
{
	std::cin >> rows;
	if (rows <= 0 || rows >= 11)
	{
		return false;
	}

	std::cin >> columns;
	if (columns <= 0 || columns >= 11)
	{
		return false;
	}



	for (int i = 0; i < rows; i++) {
		{
			for (int j = 0; j < columns; j++)
			{
				std::cin >> matr[i][j];
			}
		}
	}
	return true;
}

bool matrix::print()
{
	for (int n = 0; n < rows; n++)
	{
		for (int m = 0; m < columns; m++)
		{
			std::cout << matr[n][m] << "\t";
		}
		std::cout << std::endl;
	}
	return false;
}

bool matrix::summMatrix(matrix matr2)
{
	int resultSummMatrix[10][10];
	//проверить, columns==matr2.getRows()

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < matr2.getColumns; j++)
		{
			resultSummMatrix[i][j] += matr[i][j] + matr2.getElem(i, j);
		}
	}
	return true;
}



/*matrix & operator += (matrix & matr2)
{
	for (int)
		this->setElem(rows, columns, matr1[rows][columns] + matr2.getElem(rows, columns));
		return *this;
}*/
//перегрузка операторов,перегрузка функций
//перегрузка-объявление нескольких функций, методов или операторов,которые с одинаковыми именами но разными наборами аргументов
//различие функции по одному параметру-не перегрузка
//Неважно, какой тип аргумента возвращает, важно, какие принимает - тогда перегруженная
//Если есть необяхзательные арги, то это перегруженная
//Важны и последовательность, и типы переменных.
//Компилятор: проверяет Совпадение- затем простейшее приведение типов - 
//затем, если нет того, то * в void, float в double
// Унарные операторы перегружаются внутри класса, 
//бинаные - как дружественные глобально. Потоковые как бин, равно как унарный
//Унарарные записывают в объект, который вызвал. Поэтому внутри класса писать. 
//+= унарный
//Sample_class & operator +=(const Sample_class & operand)
//{
//property1=property1+operand.property1;
//this->property2=this->property2+property1;

#include "stdafx.h"
#include <iostream>
double getElem(int a, char b);
double getElem(int a_l, char b_l, int c_k);
double getElem(int a, char b)
{
	return a * b;
}
double getElem(int a_l, char b_l, int c_k)
{
	return a_l + b_l + c_k;
}
int main()
{
	std::cout << "a*b=" << getElem(5, 6) << std::endl;
	std::cout << "a_l+b_l+c_k=" << getElem(3, 6.5, 8) << std::endl;
	return 0;
}

