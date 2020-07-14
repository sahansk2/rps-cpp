#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "rpsgame.hpp"

TEST_CASE("Testing winning combinations of rock-paper-scissors ") {
    CHECK(RPSGame::evaluateWinner(rpsChoice::ROCK, rpsChoice::SCISSORS) == 1);
    CHECK(RPSGame::evaluateWinner(rpsChoice::ROCK, rpsChoice::PAPER) == 2);
    CHECK(RPSGame::evaluateWinner(rpsChoice::PAPER, rpsChoice::ROCK) == 1);
    CHECK(RPSGame::evaluateWinner(rpsChoice::PAPER, rpsChoice::SCISSORS) == 2);
    CHECK(RPSGame::evaluateWinner(rpsChoice::SCISSORS, rpsChoice::PAPER) == 1);
    CHECK(RPSGame::evaluateWinner(rpsChoice::SCISSORS, rpsChoice::ROCK) == 2);
}

TEST_CASE("Testing rock-paper-scissors core") {
    RPSGame game(3);
}