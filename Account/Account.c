#include "Account.h"

struct account_str
{
	float amount;
};

float getAmount(account_p acc)
{
	return acc->amount;
}

STATUS deposit(account_p acc, float amount)
{
	if (amount < 0.0)
		return NEGATIVE_AMOUNT_NOT_ALLOWED;

	acc->amount += amount;

	return OK;
}

STATUS redraw(account_p acc, float amount)
{
	if (acc->amount < amount)
		return NOT_ENOUGH_MONEY;

	acc->amount -= amount;
	return OK;
}

account_p createAccount()
{
	account_p this = (account_p)malloc(sizeof(struct account_str));
	this->amount = 0.0;
	return this;
}

void destroyAccount(account_p acc)
{
	free(acc);
}
