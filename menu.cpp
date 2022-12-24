#pragma once
#include "menu.h"
namespace Menu {
	keeper k;
	bool isRead = false;

	void set_color(WORD color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
	enum colors {
		CHOSEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		WHITE = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED
	};
	void menu_output(short menu) {
		set_color(WHITE);
		system("cls");

		cout << endl << "~ Навигация по меню через стрелочки ~\n\n";
		if (menu == 1)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "1) Добавить или удалить писателя\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "2) Добавить книгу в список произведений или удалить её\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "3) Вывести писателя\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "4) Изменить данные\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "5) Сохранить данные\n";
		if (menu == 6)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "6) Прочитать данные\n";
		if (menu == 7)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\tВыход\n" << endl;
	}

	void menu() {
		menu_output(1);
		char key_tmp; //временный символ
		char key; //опция
		short func = 1; //запуск функции
		bool ENTER_;
		bool exit = false;

		while (!exit) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			//управление меню
			switch (key) {
			case 80: //вниз
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			int del_id;

			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //добавить или удалить писателя
					add_or_delete_a_Writer();
					break;
				case 2: //добавить книгу в список произведений
					add_or_delete_book();
					break;
				case 3: //вывод писателя(писателей)
					print_Writer();
					break;
				case 4: //изменение данных
					change_data();
					break;
				case 5: //сохранить данные
					k.Save();
					cout << "Данные сохранены" << endl;
					_getch();
					break;
				case 6: // прочитать данные
					if (!isRead)
						k.Read();
					cout << "Данные загруженны" << endl;
					_getch();
					break;
				case 7:
					set_color(WHITE);
					exit = true;
					break;
				}
			}

			menu_output(func);
		}
	}

	void add_or_delete_a_Writer()
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;

		menu_add_or_delete_a_Writer(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;


			switch (key) {
			case 80: //вниз
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Добавить поэта
					cout << "Введите ФИО поэта, его год рождения, год смерти и одно его произведение (позднее сможете добавить ещё произведения)" << endl;
					add_a_poet();
					return;
				case 2: //Добавить романиста
					cout << "Введите ФИО романиста, его год рождения, год смерти и одно его произведение (позднее сможете добавить ещё произведения), краткую биографию" << endl;
					add_a_novelist();
					break;
				case 3: //Добавить фантаста
					cout << "Введите ФИО фантаста и одно его произведение (позднее сможете добавить ещё произведения), 1 - если снят фильм, 0 если не снят" << endl;
					add_a_fantast();
					break;
				case 4: //Удалить поэта
					cout << "Введите id поэта для удаления" << endl;
					delete_a_poet();
					return;
				case 5: //Удалить романиста
					cout << "Введите id поэта для удаления" << endl;
					delete_a_novelist();
					break;
				case 6: //Удалить фантаста
					cout << "Введите id поэта для удаления" << endl;
					delete_a_fantast();
					break;
				case 7: //Назад
					return;

				}
			}
			menu_add_or_delete_a_Writer(func);
		}
	}
	void menu_add_or_delete_a_Writer(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "\n";
		if (menu == 1)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Добавить поэта\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Добавить романиста\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Добавить фантаста\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Удалить фантаста\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Удалить поэта\n";
		if (menu == 6)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Удалить романиста\n";
		if (menu == 7)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\tНазад\n";
	}
	void add_a_poet()
	{
		string fullname;
		int year_of_birth, year_of_death; string yob, yod;
		string* books = new string[1];
		getline(cin, fullname);
		getline(cin, yob);
		getline(cin, yod);
		try {
			for (int i = 0; i < yob.length(); i++) { // идем по символам
				if (yob[i] >= 'A' && yob[i] <= 'Z' || yob[i] >= 'a' && yob[i] <= 'z'
					|| yod[i] >= 'A' && yod[i] <= 'Z' || yod[i] >= 'a' && yod[i] <= 'z')
					throw "Ошибка - в дате рождения есть буквы";
				break;
			}
		}
		catch (string s) {
			cout << s << endl;
		}
		year_of_birth = stoi(yob);
		year_of_death = stoi(yod);
		getline(cin, books[0]);
		k.add_poet(fullname, year_of_birth, year_of_death, books, 1);
	}
	void delete_a_poet()
	{
		int id;
		cin >> id;
		k.delete_poet(id);
	}
	void add_a_novelist()
	{
		string fullname;
		int year_of_birth, year_of_death; string yob, yod;
		string* books = new string[1];
		string biography;
		getline(cin, fullname);
		getline(cin, yob);
		getline(cin, yod);
		try {
			for (int i = 0; i < yob.length(); i++) { // идем по символам
				if (yob[i] >= 'A' && yob[i] <= 'Z' || yob[i] >= 'a' && yob[i] <= 'z'
					|| yod[i] >= 'A' && yod[i] <= 'Z' || yod[i] >= 'a' && yod[i] <= 'z')
					throw "Ошибка - в дате рождения есть буквы";
				break;
			}
		}
		catch (string s) {
			cout << s << endl;
		}
		year_of_birth = stoi(yob);
		year_of_death = stoi(yod);
		getline(cin, books[0]);
		getline(cin, biography);
		k.add_novelist(fullname, year_of_birth, year_of_death, books, 1, biography);
	}
	void delete_a_novelist()
	{
		int id;
		cin >> id;
		k.delete_novelist(id);
	}
	void add_a_fantast()
	{
		string fullname;
		string* books = new string[1];
		string isFilmed;
		getline(cin, fullname);
		getline(cin, books[0]);
		getline(cin, isFilmed);
		int IF = 0;
		try {
			if (isFilmed != "0" && isFilmed != "1") {
				throw "Ошибка - в isFilmed введено не 0 или 1";
			}
		}
		catch (string s) {
			cout << s << endl;
		}
		IF = stoi(isFilmed);
		k.add_fantast(fullname, books, 1, IF);
	}
	void delete_a_fantast()
	{
		int id;
		cin >> id;
		k.delete_fantast(id);
	}

	void add_or_delete_book()
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;

		menu_add_book(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;


			switch (key) {
			case 80: //вниз
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Добавить книгу поэта
					add_book_poet();
					return;
				case 2: //Добавить книгу романиста
					add_book_novelist();
					break;
				case 3: //Добавить книгу фантаста
					add_book_fantast();
					break;
				case 4: //Удалить книгу поэта
					delete_book_poet();
					return;
				case 5: //Удалить книгу романиста
					delete_book_novelist();
					break;
				case 6: //Удалить книгу фантаста
					delete_book_fantast();
					break;
				case 7: //Назад
					return;

				}
			}
			menu_add_book(func);
		}
	}
	void menu_add_book(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "\n";
		if (menu == 1)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Добавить книгу поэту\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Добавить книгу романисту\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Добавить книгу фантасту\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Удалить книгу поэту\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Удалить книгу романисту\n";
		if (menu == 6)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Удалить книгу фантасту\n";
		if (menu == 7)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\tНазад\n";
	}
	void add_book_poet()
	{
		string new_book; string idStr; int id;
		cout << "Введите название книги и id поэта через ENTER" << endl;
		getline(cin, new_book);
		getline(cin, idStr);
		id = stoi(idStr);
		k.add_book_poet(new_book, id);
	}
	void delete_book_poet()
	{
		int id;
		cout << "Введите id" << endl;
		cin >> id;
		k.delete_book_poet(id);
	}
	void add_book_novelist()
	{
		string new_book; string idStr; int id;
		cout << "Введите название книги и id романиста через ENTER" << endl;
		getline(cin, new_book);
		getline(cin, idStr);
		id = stoi(idStr);
		k.add_book_novelist(new_book, id);
	}
	void delete_book_novelist()
	{
		int id;
		cout << "Введите id" << endl;
		cin >> id;
		k.delete_book_novelist(id);
	}
	void add_book_fantast()
	{
		string new_book; string idStr; int id;
		cout << "Введите название книги и id фантаста через ENTER" << endl;
		getline(cin, new_book);
		getline(cin, idStr);
		id = stoi(idStr);
		k.add_book_fantast(new_book, id);
	}
	void delete_book_fantast()
	{
		int id;
		cout << "Введите id" << endl;
		cin >> id;
		k.delete_book_fantast(id);
	}

	void print_Writer()
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;
		int id;

		menu_print_Writer(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			switch (key) {
			case 80: //вниз
				func++;
				if (func > 8)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 8;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			
			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Вывести поэта по id
					cout << "Введите id" << endl;
					cin >> id;
					k.print_poet(id);
					cout << "\nНажмите ENTER чтобы продолжить продолжить!" << endl;
					_getch();
					return;
				case 2: //Вывести романиста по id
					cout << "Введите id" << endl;
					cin >> id;
					k.print_novelist(id);
					cout << "\nНажмите ENTER чтобы продолжить продолжить!" << endl;
					_getch();
					break;
				case 3: //Вывести фантаста по id
					cout << "Введите id" << endl;
					cin >> id;
					k.print_fantast(id);
					cout << "\nНажмите ENTER чтобы продолжить продолжить!" << endl;
					_getch();
					break;
				case 4: //Вывести всех поэтов
					k.print_poet();
					cout << "\nНажмите ENTER чтобы продолжить продолжить!" << endl;
					_getch();
					return;
				case 5: //Вывести всех романистов
					k.print_novelist();
					cout << "\nНажмите ENTER чтобы продолжить продолжить!" << endl;
					_getch();
					break;
				case 6: //Вывести всех фантастов
					k.print_fantast();
					cout << "\nНажмите ENTER чтобы продолжить продолжить!" << endl;
					_getch();
					break;
				case 7: //Вывести всех писателей
					k.print_all();
					cout << "\nНажмите ENTER чтобы продолжить продолжить!" << endl;
					_getch();
					break;
				case 8:
					return;
				}
			}
			menu_print_Writer(func);
		}
	}
	void menu_print_Writer(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "\n";
		if (menu == 1)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Вывод поэта по id\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Вывод романиста по id\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Вывод фантаста по id\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Вывод всех поэтов\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Вывод всех романистов\n";
		if (menu == 6)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Вывод всех фантастов\n";
		if (menu == 7)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Вывод всех писателей\n";
		if (menu == 8)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\tНазад\n";
	}

	void change_data()
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;
		int id;

		menu_change_data(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			switch (key) {
			case 80: //вниз
				func++;
				if (func > 4)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 4;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			
			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Изменить данные поэта по id
					cout << "Введите id поэта" << endl;
					cin >> id;
					change_p(id);
					break;
				case 2: //Изменить данные романиста по id
					cout << "Введите id" << endl;
					cin >> id;
					change_n(id);
					break;
				case 3: //Изменить данные фантаста по id
					cout << "Введите id" << endl;
					cin >> id;
					change_f(id);
					break;
				case 4: //Вывести всех поэтов
					return;
				}
			}
			menu_change_data(func);
		}
	}
	void menu_change_data(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "\n";
		if (menu == 1)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить данные поэта по id\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить данные романиста по id\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить данные фантаста по id\n";

		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\tНазад\n";
	}
	void change_p(int id)
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;
		string fullname;
		int year_of_birth;
		int year_of_death;
		string book;
		menu_change_p(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			switch (key) {
			case 80: //вниз
				func++;
				if (func > 5)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 5;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			
			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Изменить данные поэта по id
					cout << "Введите новое ФИО" << endl;
					getline(cin, fullname);
					getline(cin, fullname);
					k.get_poet(id).set_fullname(fullname);
					cout << "Данные изменены" << endl;
					_getch();
					break;
				case 2: //Изменить данные романиста по id
					cout << "Введите новую дату рождения" << endl;
					cin >> year_of_birth;
					k.get_poet(id).set_years_of_birth(year_of_birth);
					cout << "Данные изменены" << endl;
					_getch();
					break;
				case 3: //Изменить данные фантаста по id
					cout << "Введите новую дату смерти" << endl;
					cin >> year_of_death;
					k.get_poet(id).set_years_of_death(year_of_death);
					cout << "Данные изменены" << endl;
					_getch();
					break;
				case 4:
					cout << "Введите id книги, которую хотите изменить" << endl;
					cin >> id;
					cout << "Введите название нового произведения" << endl;
					getline(cin, book);
					k.get_poet(id).set_book(book, id);
					cout << "Данные изменены" << endl;
					_getch();
					return;
				case 5: //Вывести всех поэтов
					return;
				}
			}
			menu_change_p(func);
		}
	}
	void menu_change_p(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "\n";
		if (menu == 1)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить ФИО\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить год рождения\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить год смерти\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить произведение\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\tНазад\n";

	}
	void change_n(int id)
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;
		string fullname;
		int year_of_birth;
		int year_of_death;
		string book;
		int id_book;
		string bio;
		menu_change_n(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			switch (key) {
			case 80: //вниз
				func++;
				if (func > 5)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 5;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			
			if (ENTER_) { //запуск функций
				switch (func) {
				case 1: //Изменить данные поэта по id
					cout << "Введите новое ФИО" << endl;
					getline(cin, fullname);
					k.get_novelist(id).set_fullname(fullname);
					break;
				case 2: //Изменить данные романиста по id
					cout << "Введите новую дату рождения" << endl;
					cin >> year_of_birth;
					k.get_novelist(id).set_years_of_birth(year_of_birth);
					break;
				case 3: //Изменить данные фантаста по id
					cout << "Введите новую дату смерти" << endl;
					cin >> year_of_death;
					k.get_novelist(id).set_years_of_death(year_of_death);
					break;
				case 4:
					cout << "Введите id книги, которую хотите изменить" << endl;
					cin >> id_book;
					cout << "Введите название нового произведения" << endl;
					getline(cin, book);
					k.get_novelist(id).set_book(book, id_book);
					break;
				case 5:
					cout << "Введите новую биографию для романиста" << endl;
					getline(cin, bio);
					k.get_novelist(id).set_biography(bio);
					break;
				case 6:
					return;
				}
			}
			menu_change_n(func);
		}
	}
	void menu_change_n(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "\n";
		if (menu == 1)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить ФИО\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить год рождения\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить год смерти\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить произведение\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить биографию\n";
		if (menu == 6)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\tНазад\n";
	}
	void change_f(int id)
	{
		char key_tmp; //временный символ
		char key; //опция
		bool ENTER_;
		short func = 1;
		bool exit = false;
		string fullname;
		int year_of_birth;
		int year_of_death;
		string book;
		int id_book;
		int isFilmed;
		menu_change_f(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			switch (key) {
			case 80: //вниз
				func++;
				if (func > 4)
					func = 1;
				break;
			case 72: //вверх
				func--;
				if (func < 1)
					func = 4;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			
			if (ENTER_) { //запуск функций
				switch (func) {
				case 1:
					cout << "Введите новое ФИО" << endl;
					getline(cin, fullname);
					k.get_fantast(id).set_fullname(fullname);
					break;
				case 2:
					cout << "Введите id книги, которую хотите изменить" << endl;
					cin >> id_book;
					cout << "Введите название нового произведения" << endl;
					getline(cin, book);
					k.get_fantast(id).set_book(book, id_book);
					break;
				case 3:
					cout << "Введите 1 если фильм снят, если не снят - введите 0";
					cin >> isFilmed;
					k.get_fantast(id).set_isFilmed(isFilmed);
					break;
				case 4:
					return;
				}
			}
			menu_change_f(func);
		}
	}
	void menu_change_f(short menu)
	{
		set_color(WHITE);
		system("cls");

		cout << endl << "\n";
		if (menu == 1)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить ФИО\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить произведение\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "Изменить пункт 'Снят ли фильм'? \n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\tНазад\n";
	}
}