// ConsoleClient.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "MathLibrary.h"
#include"StudentSystem.h"
#include <iostream>

using namespace std;
using namespace Math;
using namespace StudentLibrary;

double accurancyDefine();

void Display(const Student&);
void DisplayMore(Student);
Student InitStudent();
Course InitCourse(int);

const int LENGTH = 256;

void ReplaceSubString(char*, char*, char*);

int* AllocateMemory(int);//array
int** AllocateMemory(int, int);//matrix
int** AllocateMemory(int, int*);//jagged array
void InitMatrix(int**, int, int);
void InitMatrix(int**, int, int*);
void DisplayMatrix(int**, int, int);
void DisplayMatrix(int**, int, int*);
void FreeMemory(int**, int);

int main()
{
	/*char string[LENGTH] = "", subString[LENGTH] = "", replaceString[LENGTH] = "";

	cout << "Enter the source string, please:";
	cin.getline(string, LENGTH, '\n');

	cout << "Enter the  substring , please:";
	cin.getline(subString, LENGTH, '\n');

	cout << "Enter the  substring for the replacement, please:";
	cin.getline(replaceString, LENGTH, '\n');
	system("cls");

	cout << "The source substring            - " << subString << endl;
	cout << "The substring for replacement   - " << replaceString << endl << endl;
	cout << "The source string    - " << string << endl << endl;

	ReplaceSubString(string, subString, replaceString);

	cout << "The obtained string  - " << string << endl;*/

	int n = 4, m = 10;
	int* a = AllocateMemory(n);

	for (size_t i = 0; i < n; i++)
	{
		a[i] = rand() % 10 + 2;
	}

	int** matrix = nullptr;
	try
	{
		matrix = AllocateMemory(n, a);
	}
	catch (const std::invalid_argument& ex)
	{
		cout << ex.what() << endl;
	}

	InitMatrix(matrix, n, a);
	cout << "Source matrix" << endl;
	DisplayMatrix(matrix, n, a);
	cout << endl;
	FreeMemory(matrix, n);
	system("pause");
	return 0;
}

void ReplaceSubString(char* string, char* subString, char* replaceString)
{
	int lenSubString = strlen(subString), lenReplaceString = strlen(replaceString);

	char* pString = strstr(string, subString);

	char * help = new char[strlen(string) + 1];

	while (pString)
	{
		strcpy(help, pString + lenSubString);
		strcpy(pString, replaceString);
		strcat(pString, help);
		pString = strstr(pString + lenReplaceString, subString);
	}

	delete[] help;
}

int ** AllocateMemory(int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	int** a = new int*[n];
	for (size_t i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}

	return a;
}

int ** AllocateMemory(int n, int* d)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	int** a = new int*[n];

	for (size_t i = 0; i < n; i++)
	{
		a[i] = new int[d[i]];
	}

	return a;
}

int* AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	return new int[n];
}

void InitMatrix(int** a, int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
}

void InitMatrix(int** a, int n, int* d)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr || d == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < d[i]; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
}

void DisplayMatrix(int** a, int n, int m)
{
	if (n <= 0 || m <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout.width(4);
			cout << a[i][j];
		}

		cout << endl;
	}
}

void DisplayMatrix(int** a, int n, int* d)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	if (d == nullptr)
	{
		throw std::invalid_argument("Pointer can not be null!");
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < d[i]; j++)
		{
			cout.width(4);
			cout << a[i][j];
		}

		cout << endl;
	}
}

void FreeMemory(int** a, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		delete [] a[i];
	}

	delete [] a;
}

//int main()
//{
//
//	/*char firstName[] = "Vasia";
//	char lastName[] = "Pupkin";
//	char faculty[] = "MMF";
//	Course course = Course::first;
//	Course course1 = course;
//	int n = 5;
//	int* marks = new int[n];
//	for (size_t i = 0; i < n; i++)
//	{
//		marks[i] = rand() % 10;
//	}
//	Student student(firstName,lastName, faculty, Course::first, marks, n);
//	*/
//
//	/*Student student = InitStudent();
//	Student student1;
//	student1 = student;*/
//	//char * temp = student.GetFirstName();
//	//temp[3] = '2';
//	//strcpy(temp, student.GetFirstName());
//	//cout << temp << endl;
//	/*Display(student);
//	DisplayMore(student);*/
//	//Student student1 = student;
//
//	/*double x, epsilon = accurancyDefine();
//
//	std::cout << "Enter x ";
//	std::cin >> x;
//	system("cls");
//
//	std::cout << "sum = " << Math::SinTaylor(x, epsilon) << std::endl;
//	std::cout << "sin = " << sin(x) << std::endl;
//
//	try
//	{
//		Math::SinTaylor(x, 1);
//	}
//	catch (const std::exception& ex)
//	{
//		std::cerr << ex.what() << std::endl;
//	}*/
//
//	system("pause");
//	return 0;
//}

void Display(const Student& student)
{
	cout << student.GetId() << ". ";
	cout << student.GetFirstName() << " " << student.GetLastName() << ".";
	cout << " Course: " << student.GetCourse() << ". ";
	cout << " Average mark: " << student.GetAverageMark() << ". ";
}

void DisplayMore(Student student)
{
	cout << student.GetId() << ". ";
	cout << student.GetFirstName() << " " << student.GetLastName() << ".";
	cout << " Course: " << student.GetCourse() << ". ";
	cout << " Average mark: " << student.GetAverageMark() << ". ";
}

Student InitStudent()
{
	int n = 256;
	char* fn = new char[n];
	cout << "Enter first name of student:";
	cin.getline(fn, n, '\n');

	char* ln = new char[n];
	cout << "Enter last name of student:";
	cin.getline(ln, n, '\n');

	char* fc = new char[n];
	cout << "Enter faculty:";
	cin.getline(fc, n, '\n');

	int k;
	cout << "Enter course:";
	cin >> k;

	int l;
	cout << "Enter count of marks:";
	cin >> l;

	int* mrks = new int[l];

	cout << "Enter marks:";

	for (size_t i = 0; i < l; i++)
	{
		cout << (i + 1) << " : ";
		cin >> mrks[i];
	}

	return Student(fn, ln, fc, InitCourse(k), mrks, l);
}

Course InitCourse(int k)
{
	Course course;
	switch (k)
	{
	case 1:
		course = Course::first;
		break;
	case 2:
		course = Course::second;
		break;
	case 3:
		course = Course::third;
		break;
	case 4:
		course = Course::fourth;
		break;
	default:
		throw std::invalid_argument("Invalid course!");
		break;
	}
}

double accurancyDefine()
{
	double accurancy;

	while (true)
	{
		std::cout << "Enter 0 < epsilon < 1 :";//<- Scope Resolution Operator
		std::cin >> accurancy;
		if (accurancy > 0 && accurancy < 1)
		{
			break;
		}
		std::cout << "Invalid data! Try again!";

		system("pause");
		system("cls");
	}

	return accurancy;
}

