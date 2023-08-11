#pragma once

struct GameTable {
	bool fish = false;
	bool boot = false;
};

void field—ompletion(GameTable* table);
void processGame(GameTable* table);
void showTable(GameTable* table);

