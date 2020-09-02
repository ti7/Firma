/*Список сотрудников фирмы, функцией фильтрации и поиска по имени*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <vector>


using namespace std;

struct employers /*новая структурв employers(employers - новый тип данных)*/
{
	string first_name; /*пременная типа string*/
	string last_name;  /*пременная типа string*/
	string payments;  /*пременная типа string*/
	string b_day;  /*пременная типа string*/

	void change_employers(string f_name, string l_name, string new_p_payments, string new_b_day) /*добавление в программу новых сотрудникоыв*/
	{
		first_name = f_name;
		last_name = l_name;
		payments = new_p_payments;
		b_day = new_b_day;
	}

	void save_to_file(string name_of_file) /*запись каждого сотруждника в фаил, каждый раз с новой строки благодаря ios_base::app) */
	{
		ofstream file_for_writing;
		file_for_writing.open(name_of_file, ios_base::app);
		file_for_writing << first_name << " " << last_name << " " << payments << " " << b_day << endl;;
	}

	void print_employers() /*печать сотрудников, значения берется из print_all_employers*/
	{
		cout << endl;
		cout << "Име: " << first_name << endl;
		cout << "Фамилия: " << last_name << endl;
		cout << "Зарплата: " << payments << endl;
		cout << "День рождения: " << b_day << endl;
	}


};



void exchange(employers* arr_employers, int first_index, int second_index) /*Замена в массиве arr_employers значений  в результате сравнения*/
{
	employers temp_employer;
	temp_employer = arr_employers[first_index];
	arr_employers[first_index] = arr_employers[second_index];
	arr_employers[second_index] = temp_employer;
} 
void sort_by_name_employers(employers* arr_employers) /*сравнение по имени сотрудников в массиве arr_employers и пердача результата в exchange*/
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr_employers[i].first_name < arr_employers[j].first_name)
				exchange(arr_employers, i, j);
		}
	}
}

void search_by_name_employers(employers* arr_employers, string name_for_searching) /*поиск сотрудиника по имени и вызов сразу на печать*/
{
	for (int i = 0; i < 3; i++)
	{
		if (arr_employers[i].first_name == name_for_searching)
			arr_employers[i].print_employers();
	}
}

void init_all_employers(employers* arr_employers, string name_file_for_reading, const int size) /*Перенос сотрудников из фаила в массив*/
{

	string info_employers;
	ifstream file_for_reading;
	file_for_reading.open(name_file_for_reading);

	for (int i = 0; i < 3; i++)
	{
		getline(file_for_reading, info_employers);
		stringstream ss(info_employers);
		ss >> arr_employers[i].first_name;
		ss >> arr_employers[i].last_name;
		ss >> arr_employers[i].payments;
		ss >> arr_employers[i].b_day;
	}
}

void print_all_employers(employers* arr_employers) /*Передача в функцию печати сотрудников значения каждоко элемента массива*/
{
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		arr_employers[i].print_employers();
	}
}

int main()
{
		setlocale(LC_ALL, "Ru");

		employers* arr_employers;
		arr_employers = new employers[3];
		init_all_employers(arr_employers, "employers.txt", 3); /*вызов функции*/

		

		employers employers_new_1; /*новый объект структры - employers_new_1 типа employers*/
		employers_new_1.change_employers("Andrey ", "Andrevich ", "2000,50 ", "12.07.1999 ");
		employers_new_1.save_to_file("employers.txt");
		
		employers employers_new_2;  /*новый объект структры - employers_new_2  типа employers*/
		employers_new_2.change_employers("Vladimr ", "Vladimirovich", "16000,50 ", "12.07.1998 ");
		employers_new_2.save_to_file("employers.txt");
		
		employers employers_new_3;  /*новый объект структры - employers_new_3 типа employers*/
		employers_new_3.change_employers("Boris ", "Borisovich ", "19000,50 ", "12.07.1998 ");
		employers_new_3.save_to_file("employers.txt");
		

		sort_by_name_employers(arr_employers); /*вызов функции*/
		print_all_employers(arr_employers); /*вызов функции*/

		cout << endl;

		search_by_name_employers(arr_employers, "Andrey"); /*вызов функции*/
}	