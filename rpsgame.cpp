#include "rpsgame.hpp"
#include <chrono>

RPSGame::RPSGame(int maxGames)
	: player1Score_{ 0 }, 
	  player2Score_{ 0 }, 
	  numGames_{ maxGames },
	  distribution_(0, 2) {	
	using clock = std::chrono::high_resolution_clock;
	generator_.seed(clock::now().time_since_epoch().count());	
}


// Returns: rpsChoice representing a random computer choice
rpsChoice RPSGame::getRandomChoice() {
	return static_cast<rpsChoice>(distribution_(generator_));	
}

// Returns: 1 if first wins, 2 if second wins, 0 if tie.
int RPSGame::evaluateWinner(rpsChoice first, rpsChoice second) {
	switch(first) {
		case rpsChoice::ROCK:
			if (second == rpsChoice::PAPER) return 2;
			else if (second == rpsChoice::SCISSORS) return 1;
			break;
		case rpsChoice::PAPER:
			if (second == rpsChoice::SCISSORS) return 2;
			else if (second == rpsChoice::ROCK) return 1;
			break;
		case rpsChoice::SCISSORS:
			if (second == rpsChoice::ROCK) return 2;
			else if (second == rpsChoice::PAPER) return 1;
			break;
	}
	return 0;
}

bool RPSGame::isSetOver() {
	// Minimum number of games to say the game is over.
	int threshold{ numGames_ / 2 + 1 };
	return (player1Score_ >= threshold || player2Score_ >= threshold);
}

// returns -1 if can't take in choices, otherwise returns an int representing winner. 
int RPSGame::runMatch(rpsChoice player1Choice, rpsChoice player2Choice) {
	if (isSetOver()) return -1;	
	int matchResult = evaluateWinner(player1Choice, player2Choice);
	
	if (matchResult == 1) player1Score_ += 1;
	else if (matchResult == 2) player2Score_ += 1;
	
	return matchResult;
}

// resets the game
void RPSGame::reset(int numGames=3) {
	player2Score_ = 0;
	player1Score_ = 0;
	numGames_ = numGames;	
}

// Getters
int RPSGame::player2Score() {
	return player2Score_;
}

int RPSGame::player1Score() {
	return player1Score_;
}

int RPSGame::numGames() {
	return numGames_;
}