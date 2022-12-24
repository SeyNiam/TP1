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

		cout << endl << "~ ��������� �� ���� ����� ��������� ~\n\n";
		if (menu == 1)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "1) �������� ��� ������� ��������\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "2) �������� ����� � ������ ������������ ��� ������� �\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "3) ������� ��������\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "4) �������� ������\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "5) ��������� ������\n";
		if (menu == 6)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "6) ��������� ������\n";
		if (menu == 7)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\t�����\n" << endl;
	}

	void menu() {
		menu_output(1);
		char key_tmp; //��������� ������
		char key; //�����
		short func = 1; //������ �������
		bool ENTER_;
		bool exit = false;

		while (!exit) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;

			//���������� ����
			switch (key) {
			case 80: //����
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			int del_id;

			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� ��� ������� ��������
					add_or_delete_a_Writer();
					break;
				case 2: //�������� ����� � ������ ������������
					add_or_delete_book();
					break;
				case 3: //����� ��������(���������)
					print_Writer();
					break;
				case 4: //��������� ������
					change_data();
					break;
				case 5: //��������� ������
					k.Save();
					cout << "������ ���������" << endl;
					_getch();
					break;
				case 6: // ��������� ������
					if (!isRead)
						k.Read();
					cout << "������ ����������" << endl;
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
		char key_tmp; //��������� ������
		char key; //�����
		bool ENTER_;
		short func = 1;
		bool exit = false;

		menu_add_or_delete_a_Writer(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;


			switch (key) {
			case 80: //����
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� �����
					cout << "������� ��� �����, ��� ��� ��������, ��� ������ � ���� ��� ������������ (������� ������� �������� ��� ������������)" << endl;
					add_a_poet();
					return;
				case 2: //�������� ���������
					cout << "������� ��� ���������, ��� ��� ��������, ��� ������ � ���� ��� ������������ (������� ������� �������� ��� ������������), ������� ���������" << endl;
					add_a_novelist();
					break;
				case 3: //�������� ��������
					cout << "������� ��� �������� � ���� ��� ������������ (������� ������� �������� ��� ������������), 1 - ���� ���� �����, 0 ���� �� ����" << endl;
					add_a_fantast();
					break;
				case 4: //������� �����
					cout << "������� id ����� ��� ��������" << endl;
					delete_a_poet();
					return;
				case 5: //������� ���������
					cout << "������� id ����� ��� ��������" << endl;
					delete_a_novelist();
					break;
				case 6: //������� ��������
					cout << "������� id ����� ��� ��������" << endl;
					delete_a_fantast();
					break;
				case 7: //�����
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
		cout << "�������� �����\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ���������\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ��������\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "������� ��������\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "������� �����\n";
		if (menu == 6)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "������� ���������\n";
		if (menu == 7)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\t�����\n";
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
			for (int i = 0; i < yob.length(); i++) { // ���� �� ��������
				if (yob[i] >= 'A' && yob[i] <= 'Z' || yob[i] >= 'a' && yob[i] <= 'z'
					|| yod[i] >= 'A' && yod[i] <= 'Z' || yod[i] >= 'a' && yod[i] <= 'z')
					throw "������ - � ���� �������� ���� �����";
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
			for (int i = 0; i < yob.length(); i++) { // ���� �� ��������
				if (yob[i] >= 'A' && yob[i] <= 'Z' || yob[i] >= 'a' && yob[i] <= 'z'
					|| yod[i] >= 'A' && yod[i] <= 'Z' || yod[i] >= 'a' && yod[i] <= 'z')
					throw "������ - � ���� �������� ���� �����";
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
				throw "������ - � isFilmed ������� �� 0 ��� 1";
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
		char key_tmp; //��������� ������
		char key; //�����
		bool ENTER_;
		short func = 1;
		bool exit = false;

		menu_add_book(func);

		while (1) {
			ENTER_ = false;
			key_tmp = _getch();
			key_tmp == 224 ? key = _getch() : key = key_tmp;


			switch (key) {
			case 80: //����
				func++;
				if (func > 7)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 7;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}

			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� ����� �����
					add_book_poet();
					return;
				case 2: //�������� ����� ���������
					add_book_novelist();
					break;
				case 3: //�������� ����� ��������
					add_book_fantast();
					break;
				case 4: //������� ����� �����
					delete_book_poet();
					return;
				case 5: //������� ����� ���������
					delete_book_novelist();
					break;
				case 6: //������� ����� ��������
					delete_book_fantast();
					break;
				case 7: //�����
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
		cout << "�������� ����� �����\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ����� ���������\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ����� ��������\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "������� ����� �����\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "������� ����� ���������\n";
		if (menu == 6)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "������� ����� ��������\n";
		if (menu == 7)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\t�����\n";
	}
	void add_book_poet()
	{
		string new_book; string idStr; int id;
		cout << "������� �������� ����� � id ����� ����� ENTER" << endl;
		getline(cin, new_book);
		getline(cin, idStr);
		id = stoi(idStr);
		k.add_book_poet(new_book, id);
	}
	void delete_book_poet()
	{
		int id;
		cout << "������� id" << endl;
		cin >> id;
		k.delete_book_poet(id);
	}
	void add_book_novelist()
	{
		string new_book; string idStr; int id;
		cout << "������� �������� ����� � id ��������� ����� ENTER" << endl;
		getline(cin, new_book);
		getline(cin, idStr);
		id = stoi(idStr);
		k.add_book_novelist(new_book, id);
	}
	void delete_book_novelist()
	{
		int id;
		cout << "������� id" << endl;
		cin >> id;
		k.delete_book_novelist(id);
	}
	void add_book_fantast()
	{
		string new_book; string idStr; int id;
		cout << "������� �������� ����� � id �������� ����� ENTER" << endl;
		getline(cin, new_book);
		getline(cin, idStr);
		id = stoi(idStr);
		k.add_book_fantast(new_book, id);
	}
	void delete_book_fantast()
	{
		int id;
		cout << "������� id" << endl;
		cin >> id;
		k.delete_book_fantast(id);
	}

	void print_Writer()
	{
		char key_tmp; //��������� ������
		char key; //�����
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
			case 80: //����
				func++;
				if (func > 8)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 8;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //������� ����� �� id
					cout << "������� id" << endl;
					cin >> id;
					k.print_poet(id);
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					return;
				case 2: //������� ��������� �� id
					cout << "������� id" << endl;
					cin >> id;
					k.print_novelist(id);
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 3: //������� �������� �� id
					cout << "������� id" << endl;
					cin >> id;
					k.print_fantast(id);
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 4: //������� ���� ������
					k.print_poet();
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					return;
				case 5: //������� ���� ����������
					k.print_novelist();
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 6: //������� ���� ���������
					k.print_fantast();
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
					_getch();
					break;
				case 7: //������� ���� ���������
					k.print_all();
					cout << "\n������� ENTER ����� ���������� ����������!" << endl;
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
		cout << "����� ����� �� id\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "����� ��������� �� id\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "����� �������� �� id\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "����� ���� ������\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "����� ���� ����������\n";
		if (menu == 6)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "����� ���� ���������\n";
		if (menu == 7)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "����� ���� ���������\n";
		if (menu == 8)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\t�����\n";
	}

	void change_data()
	{
		char key_tmp; //��������� ������
		char key; //�����
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
			case 80: //����
				func++;
				if (func > 4)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 4;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� ������ ����� �� id
					cout << "������� id �����" << endl;
					cin >> id;
					change_p(id);
					break;
				case 2: //�������� ������ ��������� �� id
					cout << "������� id" << endl;
					cin >> id;
					change_n(id);
					break;
				case 3: //�������� ������ �������� �� id
					cout << "������� id" << endl;
					cin >> id;
					change_f(id);
					break;
				case 4: //������� ���� ������
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
		cout << "�������� ������ ����� �� id\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ������ ��������� �� id\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ������ �������� �� id\n";

		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\t�����\n";
	}
	void change_p(int id)
	{
		char key_tmp; //��������� ������
		char key; //�����
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
			case 80: //����
				func++;
				if (func > 5)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 5;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� ������ ����� �� id
					cout << "������� ����� ���" << endl;
					getline(cin, fullname);
					getline(cin, fullname);
					k.get_poet(id).set_fullname(fullname);
					cout << "������ ��������" << endl;
					_getch();
					break;
				case 2: //�������� ������ ��������� �� id
					cout << "������� ����� ���� ��������" << endl;
					cin >> year_of_birth;
					k.get_poet(id).set_years_of_birth(year_of_birth);
					cout << "������ ��������" << endl;
					_getch();
					break;
				case 3: //�������� ������ �������� �� id
					cout << "������� ����� ���� ������" << endl;
					cin >> year_of_death;
					k.get_poet(id).set_years_of_death(year_of_death);
					cout << "������ ��������" << endl;
					_getch();
					break;
				case 4:
					cout << "������� id �����, ������� ������ ��������" << endl;
					cin >> id;
					cout << "������� �������� ������ ������������" << endl;
					getline(cin, book);
					k.get_poet(id).set_book(book, id);
					cout << "������ ��������" << endl;
					_getch();
					return;
				case 5: //������� ���� ������
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
		cout << "�������� ���\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ��� ��������\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ��� ������\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ������������\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\t�����\n";

	}
	void change_n(int id)
	{
		char key_tmp; //��������� ������
		char key; //�����
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
			case 80: //����
				func++;
				if (func > 5)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 5;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			
			if (ENTER_) { //������ �������
				switch (func) {
				case 1: //�������� ������ ����� �� id
					cout << "������� ����� ���" << endl;
					getline(cin, fullname);
					k.get_novelist(id).set_fullname(fullname);
					break;
				case 2: //�������� ������ ��������� �� id
					cout << "������� ����� ���� ��������" << endl;
					cin >> year_of_birth;
					k.get_novelist(id).set_years_of_birth(year_of_birth);
					break;
				case 3: //�������� ������ �������� �� id
					cout << "������� ����� ���� ������" << endl;
					cin >> year_of_death;
					k.get_novelist(id).set_years_of_death(year_of_death);
					break;
				case 4:
					cout << "������� id �����, ������� ������ ��������" << endl;
					cin >> id_book;
					cout << "������� �������� ������ ������������" << endl;
					getline(cin, book);
					k.get_novelist(id).set_book(book, id_book);
					break;
				case 5:
					cout << "������� ����� ��������� ��� ���������" << endl;
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
		cout << "�������� ���\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ��� ��������\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ��� ������\n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ������������\n";
		if (menu == 5)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ���������\n";
		if (menu == 6)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\t�����\n";
	}
	void change_f(int id)
	{
		char key_tmp; //��������� ������
		char key; //�����
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
			case 80: //����
				func++;
				if (func > 4)
					func = 1;
				break;
			case 72: //�����
				func--;
				if (func < 1)
					func = 4;
				break;
			case 13: //enter
				ENTER_ = true;
				break;
			}
			
			if (ENTER_) { //������ �������
				switch (func) {
				case 1:
					cout << "������� ����� ���" << endl;
					getline(cin, fullname);
					k.get_fantast(id).set_fullname(fullname);
					break;
				case 2:
					cout << "������� id �����, ������� ������ ��������" << endl;
					cin >> id_book;
					cout << "������� �������� ������ ������������" << endl;
					getline(cin, book);
					k.get_fantast(id).set_book(book, id_book);
					break;
				case 3:
					cout << "������� 1 ���� ����� ����, ���� �� ���� - ������� 0";
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
		cout << "�������� ���\n";
		if (menu == 2)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ������������\n";
		if (menu == 3)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "�������� ����� '���� �� �����'? \n";
		if (menu == 4)
			set_color(CHOSEN);
		else set_color(WHITE);
		cout << "\t�����\n";
	}
}