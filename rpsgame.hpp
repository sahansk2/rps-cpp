#pragma once

#include <random>
enum class rpsChoice {
	ROCK,
	PAPER,
	SCISSORS
};

class RPSGame {
private:
	int player1Score_; // player score
	int player2Score_; // computer score
	int numGames_; // number of total games
	// For random computer choice generation.	
	std::default_random_engine generator_;
	std::uniform_int_distribution<int> distribution_;
public:	
	RPSGame(int maxGames=3);

	int runMatch(rpsChoice player1Choice, rpsChoice player2Choice);
	void reset(int numGames);
	rpsChoice getRandomChoice();

	int player2Score();	
	int player1Score();
	int numGames();
	bool isSetOver();

	static int evaluateWinner(rpsChoice first, rpsChoice second);
};
