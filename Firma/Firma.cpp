#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <vector>

using namespace std;

struct solary_employers /*новая структурв solary_employers(solary_employers - новый тип данных)*/
{
	double base_salary = 30000;
	double tax_ndfl = 13;
	double tax_pension = 22;
	double tax_medicine = 8;
	int amount_children = 1;
	double region_coefficient = 1.15;
	double premium = 15000;
	int amount_work_hours = 160;
	double amount_all_work_hours = 1.0/160.0;
	int amount_overtime_hours = 12;
	double overtime_coefficient = 1.5;
	double outcome = 0.000;

	void outcome_counting()
	{
		outcome = base_salary * (amount_all_work_hours + amount_all_work_hours * overtime_coefficient * 1.5);
		outcome = (outcome + premium) * (100 - tax_ndfl - tax_pension - tax_medicine)*0.08;
		outcome = outcome * region_coefficient;
	}
	
};


struct employers /*новая структурв employers(employers - новый тип данных)*/
{
	string first_name; /*пременная типа string*/
	string last_name;  /*пременная типа string*/
	string oklad;  /*пременная типа string*/
	string b_day;  /*пременная типа string*/
	solary_employers temp_emp; /*пременная типа solary_employers*/

	

	
	void change_employers(string f_name, string l_name, string new_p_payments, string new_b_day) /*добавление в программу новых сотрудникоыв*/
	{
		first_name = f_name;
		last_name = l_name;
		oklad = new_p_payments;
		b_day = new_b_day;
	}

	void save_to_file(string name_of_file) /*запись каждого сотруждника в фаил, каждый раз с новой строки благодаря ios_base::app) */
	{
		ofstream file_for_writing;
		file_for_writing.open(name_of_file, ios_base::app);
		file_for_writing << first_name << " " << last_name << " " << oklad << " " << b_day << " " << temp_emp.outcome << endl;
		file_for_writing.close();
	}

	void print_employers() /*печать сотрудников, значения берется из print_all_employers*/
	{
		
		cout << endl;
		cout << "Име: " << first_name << endl;
		cout << "Фамилия: " << last_name << endl;
		cout << "Оклад: " << oklad << endl;
		cout << "День рождения: " << b_day << endl;
		cout << "Зарплата: " << temp_emp.outcome << endl;
		
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
	string  vibor_sortirovri;
	cout << "Отсортировать сотрудников по имени? (yes/no)";
	cin >> vibor_sortirovri;
	if (vibor_sortirovri == "Yes" || vibor_sortirovri == "yes" || vibor_sortirovri == "YES")
	{

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr_employers[i].first_name < arr_employers[j].first_name)
					exchange(arr_employers, i, j);
			}
		}
		cout << "Сортировка завершена: ";
	}
	else cout << "Сортировка не применена";
}

void search_by_name_employers(employers* arr_employers) /*поиск сотрудиника по имени и вызов сразу на печать*/
{
	string name_for_searching;
	cout << "Поиск сотрудника по имени: " << endl;
	cout << "Введите имя сотрудника с большой буквы: ";
	cin >> name_for_searching;
	
	for (int i = 0; i < 3; i++)
	{
		if (arr_employers[i].first_name == name_for_searching)
			arr_employers[i].print_employers();
	}
}

void init_all_employers(employers* arr_employers, string name_file_for_reading) /*Перенос сотрудников из фаила в массив*/
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
		ss >> arr_employers[i].oklad;
		ss >> arr_employers[i].b_day;
		ss >> arr_employers[i].temp_emp.outcome;
	}
	file_for_reading.close();
}

void print_all_employers(employers* arr_employers) /*Передача в функцию печати сотрудников значения каждоко элемента массива*/
{	
	cout << "Список всех сотрудников: " << endl;
	for (int i = 0; i < 3; i++)
	{
		arr_employers[i].print_employers();
	}
}

void init_print_vector(int size_vector)
{
	vector <solary_employers> temp_vector;   /*создаем вектр с зарплатой с переменными типа solary_employers*/
	solary_employers temp_solary; /*создаем пременную типа solary_employers*/
	
	for (int i = 0; i <= size_vector; i++)
	{
		temp_vector.push_back(temp_solary);

	}
	
	for (int i = 0; i < size_vector; i++)
	{
		cout << temp_vector[i].outcome << endl;
	}
		
} 

int main()
{
		setlocale(LC_ALL, "Ru");
								
		employers* arr_employers;
		arr_employers = new employers[3];

		employers employers_new_1; /*новый объект структры - employers_new_1 типа employers*/
		employers_new_1.change_employers("Andrey ", "Andrevich ", "2000,50 ", "12.07.1999 ");
		employers_new_1.save_to_file("employers.txt");
		
		employers employers_new_2;  /*новый объект структры - employers_new_2  типа employers*/
		employers_new_2.change_employers("Vladimr ", "Vladimirovich", "16000,50 ", "12.07.1998 ");
		employers_new_2.save_to_file("employers.txt");
		
		employers employers_new_3;  /*новый объект структры - employers_new_3 типа employers*/
		employers_new_3.change_employers("Boris ", "Borisovich ", "19000,50 ", "12.07.1998 ");
		employers_new_3.save_to_file("employers.txt");

		init_all_employers(arr_employers, "employers.txt"); /*вызов функции*/

		print_all_employers(arr_employers); /*вызов функции печати всех*/
		cout << endl;
		
		init_print_vector(3); /*автоввод заплат сотрудников в вектор и затем печать элементов вектора*/
		cout << endl;

		search_by_name_employers(arr_employers); /*возможность поиска сотрудников по имени*/
		cout << endl;

		sort_by_name_employers(arr_employers); /*возможность сортировки сотрудников по имени*/
		cout << endl;

		print_all_employers(arr_employers); /*вызов функции печати всех*/
		cout << endl;
}