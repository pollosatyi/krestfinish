#include "game.h"
#include "aiPlayer.h"
#include "humanPlayer.h"
#include "GameMode.h"


Game::Game(DrawEngine drawEngine)
{
	_drawEngine = drawEngine;
}


void Game::GameStart()
{
	Field* field = new Field;
	_drawEngine.ShowField(field);
	AiPlayer aiplayer('x', field);
	HumanPlayer humanPlayer('o', field, _inputEngine);
}


void Game::GameStart(GameMode gameMode)
{
	Field* field = new Field;

	switch (gameMode) {

	case GameMode::EVE: {
		AiPlayer* player1 = new AiPlayer('x', field);
		AiPlayer* player2 = new AiPlayer('o', field);
		GameStart(player1, player2);
		break; }

	case GameMode::EVP: {
		AiPlayer* player1 = new AiPlayer('x', field);
		HumanPlayer* player2 = new HumanPlayer('o', field, _inputEngine);
		GameStart(player1, player2);
		break; }

	case GameMode::PVE: {
		HumanPlayer* player1 = new HumanPlayer('x', field, _inputEngine);
		AiPlayer* player2 = new AiPlayer('o', field);
		GameStart(player1, player2);
		break; }

	case GameMode::PVP: {
		HumanPlayer* player1 = new HumanPlayer('x', field, _inputEngine);
		HumanPlayer* player2 = new HumanPlayer('o', field, _inputEngine);
		GameStart(player1, player2);
		break; }
	}
}


void Game::GameStart(Player* player1, Player* player2)
{
	Field* field = player1->GetField();
	Player* currentPlayer = player2;
	bool isCurrentPlayerWinner = true;

	do {
		currentPlayer = currentPlayer == player1 ? player2 : player1;
		PlayerTurn(currentPlayer);
		isCurrentPlayerWinner = currentPlayer->CheckWinner();

	} while (!isCurrentPlayerWinner && !field->IsFieldFull());

	if (isCurrentPlayerWinner) {
		std::cout << (currentPlayer == player1 ? "Победил игрок 1" : "Победил игрок 2");
		currentPlayer->ShowPlayer();
	}
	else {
		std::cout << "Ничья";
	}

}


void Game::PlayerTurn(Player* player)
{
	Field* field = player->GetField();
	player->Turn();
	_drawEngine.ShowField(field);
}
