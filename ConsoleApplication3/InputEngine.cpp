#include <string>

#include "InputEngine.h"
#include "Game.h"


int InputEngine::GetIntFromConsole(int minValue, int maxValue, char* promt)
{
	int result = 10;
	std::string userInput;

	do {

		std::cout << promt << std::endl;
		std::cin >> userInput;

		if (std::isdigit(*userInput.begin())) {
			result = stoi(userInput);
		}

		if (result < minValue || result > maxValue) {
			std::cout << "�������� ���� ���������� �����" << std::endl;
		}

	} while (result < minValue || result > maxValue);

	return result;
}


GameMode InputEngine::GetGameTypeFromUserInput()
{
	std::cout << "����� ����: " << std::endl;
	std::cout << "������� 1 ��� ������ ���������(X) ������ ����������(O)" << std::endl;
	std::cout << "������� 2 ��� ������ ��������� ������ ������" << std::endl;
	std::cout << "������� 3 ��� ������ ����� ������ ����������" << std::endl;
	std::cout << "������� 4 ��� ������ ����� ������ ������" << std::endl;

	int getNumberGame = GetIntFromConsole(1, 4, (char*)("������� ����� ����: "));
	switch (getNumberGame)
	{

	case 1:
		return GameMode::EVE;

	case 2:
		return GameMode::EVP;

	case 3:
		return GameMode::PVE;

	case 4:
	default:
		return GameMode::PVP;
	}
}


int InputEngine::GetRowFromUserInput()
{
	int turnRow = GetIntFromConsole(0, 2, (char*)("������� ����� ������ ���� (0-2)"));
	return turnRow;
}



int InputEngine::GetColumnFromUserInput()
{
	int turnColumn = GetIntFromConsole(0, 2, (char*)("������� ����� ������� ���� (0-2)"));
	return turnColumn;
}

