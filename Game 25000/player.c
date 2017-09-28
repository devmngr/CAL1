#include "player.h"
#include <string.h>
#include <stdio.h>

static int firstTripple;
static int status;

struct player_str {
	int totalScore;
	int turnPoints;
	int throwNo;
};
player_p createPlayer() {
	player_p this = (player_p)malloc(sizeof(struct player_str));
	this->totalScore = 0;
	this->turnPoints = 0;
	this->throwNo = 0;
	return this;
}
void destroyPlayer(player_p player) {
	free(player);	
}
void startTurn(player_p player){
	player->turnPoints = 0;
}
int getTotalScore(player_p player) {
	return player->totalScore;
}
void sumTurnPoints(player_p player,int points) {
	player->turnPoints += points;
}
int stopTurn(player_p player) {
	if (player->turnPoints != -500 && player->turnPoints<500) {
		player->turnPoints = 0;
	}
	player->totalScore += player->turnPoints;
	return player->turnPoints;
}
int getTurnPoints(player_p player) {
	return player->turnPoints;
}
void throwDice(player_p player, char * dices,STATUS sts) {
	int number = 1;
	int occurences;
	while (number <= 6) {
		occurences = nrOfOccurences(number, dices);
		if (number == firstTripple
			&& player->throwNo == 1 
			&& status == GO_4) 
		{
			if (nrOfOccurences(firstTripple, dices) >= 1)
			{
				if (number == 1)
					player->turnPoints += number * 1000 * 9;
				else
					player->turnPoints += number * 100 * 9;
				occurences--;
			}
			else
			{
				player->turnPoints = -500;
				stopTurn(player, status);
			}
		}
		if (occurences == 0)
			player->turnPoints += 0;
	
		else if (occurences < 3){
				if (number == 1)
					player->turnPoints += 100 * occurences;
				else if (number == 5)
					player->turnPoints += 50 * occurences;
			
		}

		else if (occurences == 3) {
			if (player->throwNo == 0){
				firstTripple = number;	
			}
			if (number == 1)
				player->turnPoints += number * 1000;
			else
			player->turnPoints += number * 100;
			status = sts;
		}
		else if (occurences == 4) {

			if (number == 1)
				player->turnPoints += number * 1000 * 10;
			else
				player->turnPoints += number * 100 * 10;
		}	
		number++;
	}
	player->throwNo++;
}
static int nrOfOccurences(int dice, char * throw) {
	char temp[14];
	strcpy(temp, throw);
	const char s[2] = ",";
	char * token= strtok(temp, s);
	int count = 0;
	int value;
	while (token != NULL)
	{
		value = atoi(token);
		if (value == dice)
			count++;
		token = strtok(NULL, s);
	}
	return count;
}
