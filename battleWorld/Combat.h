#ifndef COMBAT
#define COMBAT
#pragma once
#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdlib.h>
#include "main.h"
#include "MovesDB.h"
#endif

bool winCondition = false;
bool combatEnded = false;

void stats();

void reroll();

void assignMove(char keyAssign, int moveIndex);
bool getWinCondition();
void parseCombat(std::string sInput);