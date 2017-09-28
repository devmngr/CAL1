#pragma once
// Abstract Data Type (ADT)
typedef struct account_str *account_p;

/**
 * \brief 
 */
typedef enum STATUS {OK, NOT_ENOUGH_MONEY, NEGATIVE_AMOUNT_NOT_ALLOWED} STATUS;

/**
 * \brief 
 * \return 
 */
account_p createAccount();

/**
 * \brief 
 * \param acc 
 */
void destroyAccount(account_p acc);

/**
 * \brief 
 * \param acc 
 * \return 
 */
float getAmount(account_p acc);

/**
 * \brief 
 * \param acc 
 * \param amount 
 * \return 
 */
STATUS deposit(account_p acc, float amount);

/**
 * \brief 
 * \param acc 
 * \param amount 
 * \return 
 */
STATUS redraw(account_p acc, float amount);
