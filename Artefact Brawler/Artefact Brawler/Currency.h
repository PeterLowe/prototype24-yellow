#pragma once
class Currency
{
public:
	Currency() { coins = 0; }

	static int getCoins() { return coins; }
	static void changeCoinsAmount(int t_change) { coins += t_change; }

private:

	static int coins;
};