#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness_c.h>


extern "C" {
	#include "Account.h"
};

static account_p acc;

TEST_GROUP(TEST_ACCOUNT)
{
	void setup()
	{
		acc = createAccount();
	}

	void teardown()
	{
		destroyAccount(acc);
	}
};

TEST(TEST_ACCOUNT, NewAccountIsZero)
{
	CHECK_EQUAL_C_REAL(0.0, getAmount(acc),0.00001);
}

TEST(TEST_ACCOUNT, DepositMoney)
{
	STATUS stat = deposit(acc, 100.0);
	CHECK_EQUAL_C_INT(OK, stat);
	CHECK_EQUAL_C_REAL(100.0, getAmount(acc), 0.00001);
}

TEST(TEST_ACCOUNT, RedrawMoney)
{
	STATUS stat;
	stat = deposit(acc, 1000.0);
	CHECK_EQUAL_C_INT(OK, stat);
	stat = redraw(acc, 100.0);
	CHECK_EQUAL_C_INT(OK, stat);
	CHECK_EQUAL_C_REAL(900.0, getAmount(acc), 0.00001);
}

TEST(TEST_ACCOUNT, AccountNotNegative)
{
	STATUS stat = redraw(acc, 100.0);
	CHECK_EQUAL_C_INT(NOT_ENOUGH_MONEY, stat);
	CHECK_EQUAL_C_REAL(0.0, getAmount(acc), 0.00001);
}

TEST(TEST_ACCOUNT, RedrawNegative)
{
	STATUS stat = deposit(acc, -100.0);
	CHECK_EQUAL_C_INT(NEGATIVE_AMOUNT_NOT_ALLOWED, stat);
	CHECK_EQUAL_C_REAL(0.0, getAmount(acc), 0.00001);
}