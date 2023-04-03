#ifndef BANK_H_
#define BANK_H_
using namespace std;
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include "Transaction.h"
#include "Account.h"
#include "BSTree.h"
class Bank
{
    public:
        Bank();
        bool ReadFile(const string &filename);
        bool ExecuteTransactions();
        void Display_Transactions();

    private:
        string lastname_;
        string firstname_;
        int amount_;
        int id_;
        BSTree accounts_;
        queue<Transaction> storage_transaction; // use it in execute method
        


};
#endif