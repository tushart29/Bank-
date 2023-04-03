

#include "Transaction.h"
class Fund
{
    public:

        Fund();
        Fund(string name_of_fund);
        bool AddFunds(int amount);
        bool RemoveFunds(int amount);
        bool PushFunds(Transaction obj);
        void DisplayTotalFunds();
        void DisplayHistory();
        void DisplayHistoryFund(int fund_type);
        string GetFundName();
        int GetBalance();
    private:
        string name_of_fund;
        int balance;
        vector<Transaction> funds_history;

};