#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit ){
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";created" << std::endl;
}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

int	Account::getNbAccounts( void ){
	return _nbAccounts;
}

int	Account::getTotalAmount( void ){
	return _totalAmount;
}

int	Account::getNbDeposits( void ){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";withdrawal:";
	if (_amount - withdrawal < 0){
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << withdrawal
	<< ";amount:" << _amount
	<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const{
	return _amount;
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ){
	time_t		currentTime;
	struct tm	*localTime;
	char	formattedTime[16];

	time(&currentTime);
	localTime = localtime(&currentTime);
	strftime(formattedTime, sizeof(formattedTime), "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" <<formattedTime << "] ";
}
