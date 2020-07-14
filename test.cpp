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

TEST_CASE("Testing RPSGame class") {
    RPSGame game = RPSGame();
    
    REQUIRE(game.numGames() == 3);
    REQUIRE(game.player1Score() == 0);
    REQUIRE(game.player2Score() == 0);

    CHECK(!game.isSetOver());

    SUBCASE("getRandomChoice() outputs one of ROCK, PAPER, or SCISSORS.") {
        rpsChoice randChoice = game.getRandomChoice();

        bool inChoices = (
            randChoice == rpsChoice::ROCK || 
            randChoice == rpsChoice::PAPER || 
            randChoice == rpsChoice::SCISSORS
        );

        CHECK(inChoices);
    }

    SUBCASE("Scores are properly modified after games.") {
        bool scoreUpdated;
        game.runMatch(rpsChoice::ROCK, rpsChoice::PAPER);
        scoreUpdated = game.player1Score() == 0 && game.player2Score() == 1;
        CHECK(scoreUpdated);
        game.runMatch(rpsChoice::SCISSORS, rpsChoice::PAPER);
        scoreUpdated = game.player1Score() == 1 && game.player2Score() == 1;
        CHECK(scoreUpdated);
        game.runMatch(rpsChoice::SCISSORS, rpsChoice::SCISSORS);
        scoreUpdated = game.player1Score() == 1 && game.player2Score() == 1;
        CHECK(scoreUpdated);
    }

    SUBCASE("Game is over after it's clear who won.") {
        game.runMatch(rpsChoice::ROCK, rpsChoice::PAPER);
        game.runMatch(rpsChoice::ROCK, rpsChoice::PAPER);
        CHECK(game.runMatch(rpsChoice::ROCK, rpsChoice::PAPER) == -1);
        CHECK(game.isSetOver());
    }
}