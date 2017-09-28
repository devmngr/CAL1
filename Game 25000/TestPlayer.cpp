#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness_c.h>


extern "C" {
#include "player.h"
};

static player_p player;
TEST_GROUP(TEST_GAME)
{
	void setup()
	{
		player = createPlayer();
	}

	void teardown()
	{
		destroyPlayer(player);
	}
};
TEST(TEST_GAME, firstThowTriple2SecondThrow222) {
	throwDice(player, "2,2,2", GO_4);
	CHECK_EQUAL_C_INT(200, getTurnPoints(player));
	throwDice(player, "2,2,2", OK);
	CHECK_EQUAL_C_INT(2000, getTurnPoints(player));
}
TEST(TEST_GAME, firstThowTriple2SecondThrow22) {
	throwDice(player, "2,2,2", GO_4);
	CHECK_EQUAL_C_INT(200, getTurnPoints(player));
	throwDice(player, "2,2", OK);
	CHECK_EQUAL_C_INT(2000, getTurnPoints(player));
}
TEST(TEST_GAME, firstThowTriple1SecondThrow111) {
	throwDice(player, "1,1,1", GO_4);
	CHECK_EQUAL_C_INT(1000, getTurnPoints(player));
	throwDice(player, "1,1,1", OK);
	CHECK_EQUAL_C_INT(10200, getTurnPoints(player));
}
TEST(TEST_GAME, firstThowTriple1SecondThrow11) {
	throwDice(player, "1,1,1", GO_4);
	CHECK_EQUAL_C_INT(1000, getTurnPoints(player));
	throwDice(player, "1,1", OK);
	CHECK_EQUAL_C_INT(10100, getTurnPoints(player));
}
TEST(TEST_GAME, Throw2324262) {
	throwDice(player, "2,3,2,4,2,6,2", OK);
	CHECK_EQUAL_C_INT(2000, getTurnPoints(player));
}
TEST(TEST_GAME, Throw234622) {
	throwDice(player, "2,3,4,6,2,2", OK);
	CHECK_EQUAL_C_INT(200, getTurnPoints(player));
}
TEST(TEST_GAME, Throw234623) {
	throwDice(player, "2,3,4,6,2,3", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, Throw5555111) {
	throwDice(player, "5,5,5,1,1,1,1", OK);
	CHECK_EQUAL_C_INT(10500, getTurnPoints(player));
}
TEST(TEST_GAME, Throw5511315) {
	throwDice(player, "5,5,1,1,3,1,5", OK);
	CHECK_EQUAL_C_INT(1500, getTurnPoints(player));
}
TEST(TEST_GAME, Throw111525) {
	throwDice(player, "1,1,1,5,2,5", OK);
	CHECK_EQUAL_C_INT(1100, getTurnPoints(player));
}
TEST(TEST_GAME, Throw111555) {
	throwDice(player, "1,1,1,5,5,5", OK);
	CHECK_EQUAL_C_INT(1500, getTurnPoints(player));
}
TEST(TEST_GAME, Throw11125) {
	throwDice(player, "1,1,1,2,5", OK);
	CHECK_EQUAL_C_INT(1050, getTurnPoints(player));
	CHECK_EQUAL_C_INT(1050, stopTurn(player));
	CHECK_EQUAL_C_INT(1050, getTotalScore(player));
}
TEST(TEST_GAME, turnScoreSameAsTotalScore) {
	throwDice(player, "1,1,1", OK);
	CHECK_EQUAL_C_INT(1000, getTurnPoints(player));
	CHECK_EQUAL_C_INT(1000, stopTurn(player));
	CHECK_EQUAL_C_INT(1000, getTotalScore(player));
}
TEST(TEST_GAME, firstThowTriple1SecondThrow2TotalScore) {
	throwDice(player, "1,1,1", GO_4);
	CHECK_EQUAL_C_INT(1000, getTurnPoints(player));
	throwDice(player, "2", OK);
	CHECK_EQUAL_C_INT(-500, getTurnPoints(player));
	CHECK_EQUAL_C_INT(-500, getTotalScore(player));
}
TEST(TEST_GAME, firstThowTriple1SecondThrow2) {
	throwDice(player, "1,1,1", GO_4);
	CHECK_EQUAL_C_INT(1000, getTurnPoints(player));
	throwDice(player, "2", OK);
	CHECK_EQUAL_C_INT(-500, getTurnPoints(player));
}
TEST(TEST_GAME, firstThowTriple5SecondThrow5) {
	throwDice(player, "5,5,5", GO_4);
	CHECK_EQUAL_C_INT(500, getTurnPoints(player));
	throwDice(player, "5",OK);
	CHECK_EQUAL_C_INT(5000, getTurnPoints(player));
}
TEST(TEST_GAME, firstThowTriple3SecondThrow3) {
	throwDice(player, "3,3,3", GO_4);
	CHECK_EQUAL_C_INT(300, getTurnPoints(player));
	throwDice(player, "3",OK);
	CHECK_EQUAL_C_INT(3000, getTurnPoints(player));
}
TEST(TEST_GAME, firstThowTriple1SecondThrow1) {
	throwDice(player, "1,1,1",GO_4);
	CHECK_EQUAL_C_INT(1000, getTurnPoints(player));
	throwDice(player, "1",OK);
	CHECK_EQUAL_C_INT(10000, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesFourOf5) {
	throwDice(player, "5,5,5,5", OK);
	CHECK_EQUAL_C_INT(5000, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesFourOf2) {
	throwDice(player, "2,2,2,2", OK);
	CHECK_EQUAL_C_INT(2000, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesFourOf1) {
	throwDice(player, "1,1,1,1", OK);
	CHECK_EQUAL_C_INT(10000, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesTriple7) {
	throwDice(player, "7,7,7", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesTriple6) {
	throwDice(player, "6,6,6", OK);
	CHECK_EQUAL_C_INT(600, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesTriple5) {
	throwDice(player, "5,5,5", OK);
	CHECK_EQUAL_C_INT(500, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesTriple4) {
	throwDice(player, "4,4,4", OK);
	CHECK_EQUAL_C_INT(400, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesTriple3) {
	throwDice(player, "3,3,3", OK);
	CHECK_EQUAL_C_INT(300, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesTriple2) {
	throwDice(player, "2,2,2", OK);
	CHECK_EQUAL_C_INT(200, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesTripple1) {
	throwDice(player, "1,1,1", OK);
	CHECK_EQUAL_C_INT(1000, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesDouble6) {
	throwDice(player, "6,6", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesDouble5) {
	throwDice(player, "5,5", OK);
	CHECK_EQUAL_C_INT(100, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesDouble4) {
	throwDice(player, "4,4", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesDouble3) {
	throwDice(player, "3,3", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesDouble2) {
	throwDice(player, "2,2", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, throwDicesDouble1) {
	throwDice(player, "1,1", OK);
	CHECK_EQUAL_C_INT(200, getTurnPoints(player));
}
TEST(TEST_GAME, throwDices1And2) {
	throwDice(player, "1,2", OK);
	CHECK_EQUAL_C_INT(100, getTurnPoints(player));
}
TEST(TEST_GAME, throwDices2And5) {
	throwDice(player, "2,5", OK);
	CHECK_EQUAL_C_INT(50, getTurnPoints(player));
}
TEST(TEST_GAME, throwDices2And3) {
	throwDice(player,"2,3", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, throwDices1And5) {
	throwDice(player,"1,5", OK);
	CHECK_EQUAL_C_INT(150, getTurnPoints(player));
}
TEST(TEST_GAME, throwDices6) {
	throwDice(player,"6", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, throwDices5) {
	throwDice(player,"5", OK);
	CHECK_EQUAL_C_INT(50, getTurnPoints(player));
}
TEST(TEST_GAME, throwDices4) {
	throwDice(player,"4", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, throwDices3) {
	throwDice(player,"3", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, throwDices2) {
	throwDice(player,"2", OK);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, throwDices1) {
	throwDice(player,"1",OK);
	CHECK_EQUAL_C_INT(100, getTurnPoints(player));
}
TEST(TEST_GAME, stopTurnOver500Points) {
	sumTurnPoints(player, 400);
	sumTurnPoints(player, 101);
	CHECK_EQUAL_C_INT(501, stopTurn(player));
}
TEST(TEST_GAME, stopTurnAt500Points) {
	sumTurnPoints(player, 400);
	sumTurnPoints(player, 100);
	CHECK_EQUAL_C_INT(500, stopTurn(player));
}
TEST(TEST_GAME, stopTurnUnder500Points2) {
	sumTurnPoints(player, 499);
	CHECK_EQUAL_C_INT(0, stopTurn(player));
}
TEST(TEST_GAME, stopTurnUnder500Points) {
	sumTurnPoints(player, 100);
	sumTurnPoints(player, 100);
	CHECK_EQUAL_C_INT(0, stopTurn(player));
}
TEST(TEST_GAME, turnPoints) {
	sumTurnPoints(player,100);
	sumTurnPoints(player,100);
	CHECK_EQUAL_C_INT(200, getTurnPoints(player));
}
TEST(TEST_GAME, sumOfTurnPoints1) {
	sumTurnPoints(player,200);
	CHECK_EQUAL_C_INT(200, getTurnPoints(player));
}
TEST(TEST_GAME,sumOfTurnPoints) {
	sumTurnPoints(player,100);
	CHECK_EQUAL_C_INT(100, getTurnPoints(player));
}
TEST(TEST_GAME, stopTurn) {
	CHECK_EQUAL_C_INT(0, stopTurn(player));
}
TEST(TEST_GAME, starTurnScore) {
	startTurn(player);
	CHECK_EQUAL_C_INT(0, getTurnPoints(player));
}
TEST(TEST_GAME, totalScoreIsZero) {
	CHECK_EQUAL_C_INT(0, getTotalScore(player));
}