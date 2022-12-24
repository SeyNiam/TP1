/*Класс Печатное издание хранит книги поэтов, романистов и фантастов. Для
поэтов определено: ФИО, годы жизни, несколько основных произведений. Для
романистов определено: ФИО, годы жизни, несколько произведений, краткая
биография. Для фантастов определено: ФИО, несколько произведений, сняты
ли фильмы по книгам.
Разработать класс Keeper, который реализует контейнер для хранения и обработки
объектов. Класс Keeper должен обеспечивать следующие функции:
▪ добавление и удаление производных объектов абстрактного класса Writer
▪ полное сохранение себя в файле;
▪ полное восстановление себя из файла.
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "menu.h"

using namespace Menu;

// Для вывода текста белого цвета после завершения программы
void set_colour(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	menu();
	
	enum colors_;
	enum colors { WHITE = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED};
	set_colour(WHITE);

    return 0;
}
