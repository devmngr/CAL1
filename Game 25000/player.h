#pragma once
typedef struct player_str * player_p;
typedef enum STATUS {GO_4,OK} STATUS;

player_p createPlayer();
void destroyPlayer(player_p player);
void startTurn(player_p player);
int getTurnPoints(player_p player);
int getTotalScore(player_p player);
void sumTurnPoints(player_p player, int points);
void throwDice(player_p player, char * dices, STATUS status);
int stopTurn(player_p player);