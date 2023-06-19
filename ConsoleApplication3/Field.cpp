#include "Field.h"

void Field::InitField()
{
	for (int rowCounter = 0; rowCounter < 3; rowCounter++) {
		for (int columnCounter = 0; columnCounter < 3; columnCounter++) {
			_field[rowCounter][columnCounter] = ' ';
		}
	}
}


Field::Field()
{
	_field = new char* [3];

	for (int rowCounter = 0; rowCounter < 3; rowCounter++) {
		_field[rowCounter] = new char[3];
	}

	this->InitField();
}


char Field::GetCell(int row, int column)
{
	return _field[row][column];
}


void Field::CheckWin()
{
}


bool Field::IsCellEmpty(int row, int column)
{
	return _field[row][column] == ' ';
}


void Field::SetCell(int row, int column, char symbol)
{
	_field[row][column] = symbol;
}


bool Field::IsFieldFull()
{
	for (int rowCounter = 0; rowCounter < 3; rowCounter++) {
		for (int columnCounter = 0; columnCounter < 3; columnCounter++) {

			if (_field[rowCounter][columnCounter] == ' ') {
				return false;
			}
		}
	}

	return true;
}


bool Field::CheckFieldRowForWin(char symbol)
{
	for (int rowCounter = 0; rowCounter < 3; rowCounter++) {

		int countOfSymbol = 0;
		for (int columnCounter = 0; columnCounter < 3; columnCounter++) {

			if (_field[rowCounter][columnCounter] == symbol) {
				countOfSymbol++;
			}

		}

		if (countOfSymbol == 3) { return true; }

	}

	return false;
}


bool Field::CheckFieldColumnForWin(char symbol)
{
	for (int colCounter = 0; colCounter < 3; colCounter++) {

		int countOfSymbol = 0;
		for (int rowCounter = 0; rowCounter < 3; rowCounter++) {

			if (_field[colCounter][rowCounter] == symbol) {
				countOfSymbol++;
			}

		}

		if (countOfSymbol == 3) { return true; }

	}

	return false;
}

bool Field::CheckMainDiagonalForWin(char symbol)
{
	return _field[0][0] == symbol && _field[1][1] == symbol && _field[2][2] == symbol;
}


bool Field::CheckSecondaryDiagonal(char symbol)
{
	return _field[0][2] == symbol && _field[1][1] == symbol && _field[2][0] == symbol;
}


bool Field::CheckFieldForWin(char symbol)
{
	return (CheckFieldRowForWin(symbol) || CheckFieldColumnForWin(symbol)
		|| CheckMainDiagonalForWin(symbol) || CheckSecondaryDiagonal(symbol));
}
