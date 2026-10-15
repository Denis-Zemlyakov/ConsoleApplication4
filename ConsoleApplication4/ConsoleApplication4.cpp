#include <iostream>
#include <string>
#include <regex>
#include "Array.h"

void clearConsole() {
	std::cout << "\033[2J\033[1;1H";
}

bool isNumberOnly(const std::string& str) {
	const std::regex positiveInt(R"(^[0-9][0-9]*$)");

	if (std::regex_match(str, positiveInt)) {
		//std::cout << "Строка валидна (только цифры).\n";
		return 0;
	}
	else {
		//std::cout << "Ошибка: обнаружены недопустимые символы.\n";
		return 1;
	}
}

int read() {
	std::string str;
	std::getline(std::cin, str);

	while (isNumberOnly(str)) {
		std::cout << "Введите корректные данные" << std::endl;
		std::getline(std::cin, str);
	}

	return stoi(str);
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	unsigned int sizeArray = 0, index = 0;
	long int foundIndex;
	int value;
	unsigned short action = 0;
	ErrorsCode result;

	std::cout << "Введите размер массива: ";

	sizeArray = read();
	Array arr(sizeArray);

	do
	{
		clearConsole();
		std::cout << "Что вы хотите сделать?\n 0. Выйти\n 1. Добавить элемент\n 2. Удалить элемент\n 3. Найти элемент\n 4. Изменить размер массива\n 5. Вывести элементы\n";
		action = read();

		switch (action)
		{
		case 0:
			return 0;
			break;

		case 1:
			std::cout << "Введите индекс для добавления: ";
			index = read();
			std::cout << "Введите значение для добавления: ";
			value = read();
			result = arr.add(index, value);
			if (result != SUCCESS) printError(result);
			break;

		case 2:
			std::cout << "Введите индекс для удаления: ";
			index = read();
			result = arr.remove(index);
			if (result != SUCCESS) printError(result);
			break;

		case 3:
			std::cout << "Введите значение для поиска: ";
			value = read();
			foundIndex = arr.find(value);
			if (foundIndex != -1) {
				std::cout << "Элемент найден на индексе: " << foundIndex << "\n";
			}
			else {
				std::cout << "Элемент не найден.\n";
			}
			std::system("pause");
			break;

		case 4:
			std::cout << "Введите новый размер массива: ";
			sizeArray = read();
			result = arr.resize(sizeArray);
			if (result != SUCCESS) printError(result);
			break;

		case 5:
			arr.print();
			std::system("pause");
			break;

		default:

			break;
		}

	} while (true);

	return 0;
}