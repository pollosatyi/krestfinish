#pragma once
#include "player.h"
#include "InputEngine.h"

class HumanPlayer :public Player
{
	InputEngine _inputEngine;

public:
	HumanPlayer(char symbol, Field* field, InputEngine inputEngine);

	void Turn() override;
	bool CheckWinner() override;
	void ShowPlayer() override;


};

