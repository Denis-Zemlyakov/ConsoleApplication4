#include "Errors.h"

void printError(ErrorsCode error) {
	setlocale(LC_ALL, "Russian");

	switch (error)
	{
	case SUCCESS:
		std::cout << "success" << std::endl;
		std::system("pause");
		break;
	case INSUFFICIENT_SPACE:
		std::cout << "insufficient_space" << std::endl;
		std::system("pause");
		break;
	case OUT_OF_BOUNDS:
		std::cout << "out of bounds" << std::endl;
		std::system("pause");
		break;
	case INVALID_INDEX:
		std::cout << "invalid index" << std::endl;
		std:system("pause");
		break;
	case INVALID_SIZE:
		std::cout << "invalid size" << std::endl;
		std::system("pause");
		break;
	default:
		std::cout << "unknown error" << std::endl;
		std::system("pause");
		break;
	}
}