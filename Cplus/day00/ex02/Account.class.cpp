// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Account.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 14:02:09 by akasamar          #+#    #+#             //
//   Updated: 2018/10/02 14:02:09 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Account.class.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" <<Account::_totalNbDeposits <<
    ";withdrawals:" << _totalNbWithdrawals << std::endl;
}


Account::Account(int inti_depos)
{
    _displayTimestamp();
    _amount = inti_depos;
    _accountIndex = _nbAccounts;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"<< std::endl;
    _nbAccounts++;
    _totalAmount += _amount;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"<< _nbDeposits <<
    ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:"<< deposit <<
              ";amount:";
    _amount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    std::cout << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
    _totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:"<< _amount << ";withdrawal:";
    if (_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

void	Account::_displayTimestamp( void )
{
    std::cout << "[20201212_111213] ";
}