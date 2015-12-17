#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account;

class AccountState
{
public:
	virtual void Deposit(double amount, Account* acc) = 0;
	virtual void Withdraw(double amount, Account* acc) = 0;
};

class Account
{
private:
	double amount_;
	AccountState *state_ ;
public:
	bool danger_;
	vector<string> facilities_;

	void SetState(AccountState *state)
	{
		state_ = state;
	}

	int GetAmount() const { return amount_; }

	void Deposit(double amount) 
	{ 
		state_->Deposit(amount, this);
	}

	void Withdraw(double amount) 
	{ 
		amount_ -= amount; 
	}
};

class AccountLessThan100000 : public AccountState
{
public:
	void Deposit(double amount, Account *acc)
	{
		acc->Deposit(amount);
		acc->facilities_.push_back("Paid Credit Card");
		acc->facilities_.push_back("9% on FD");
		if (acc->GetAmount() > 100000)
			acc->SetState(new AccountMoreThan100000());
	}

	void Withdraw(double amount, Account *acc)
	{
	}
};

class AccountMoreThan100000 : public AccountState
{
public:
	void Deposit(double amount, Account *acc)
	{
		acc->Deposit(amount);
		acc->facilities_.push_back("Free Credit Card");
		acc->facilities_.push_back("11% on FD");
		if (acc->GetAmount() > 100000)
			acc->SetState(new AccountMoreThan100000());
	}
	void Withdraw(double amount, Account *acc)
	{
	}
};

class AccountMoreThan1000000 : public AccountState
{
public:
	void Deposit(double amount, Account *acc)
	{
	}
	void Withdraw(double amount, Account *acc)
	{
	}
};


void main()
{
	Account a1;
	a1.SetState(new AccountLessThan100000());
	a1.Deposit(10000);
	a1.Deposit(99000);

	a1.Deposit(400000);

	a1.Withdraw(50000);
}