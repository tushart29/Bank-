#ifndef ACCOUNT_H_
#define ACCOUNT_H_
using namespace std;
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include "Transaction.h"
#include "Fund.h"

class Account
{
    public:

        Account();
        Account(string firstname, string lastname, int id);
        bool OpenAccount(int id, string firstname, string lastname);
        bool Deposit(int fund_id, int amount); 
        bool Withdraw(int id, int amount);
        bool Transfer(Account* other, int id, int fund_type, int other_fund_type ,int amount);
        
        //bool DisplayTransaction();
        bool DisplayFunds(int fund_type);
        bool DisplayFundsinAccount();
        bool DisplayFundsinBank();

        friend ostream& operator<<(ostream &out, const Account& pAcct);

        void Record(Transaction obj, int fund_type);
        void RecordInClass(Transaction obj, int fund_type);
        string GetFirstName() const;
        string GetLastName() const;
        int GetAmount() const;
        int GetId() const;
        int GetFundType() const;
        Transaction obj_;
        Transaction obj_another;
        string action_;
        private:

            string firstname_;
            string lastname_;
            int amount_;
            bool check = false;
            int fundtype_;
            int account_id_;
            Fund* types[8];
};
#endif