#pragma once
#include <iostream>

enum ErrorsCode
{
	SUCCESS,
	INSUFFICIENT_SPACE,
	OUT_OF_BOUNDS,
	INVALID_INDEX,
	INVALID_SIZE,
};

void printError(ErrorsCode error);