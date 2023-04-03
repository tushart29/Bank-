#ifndef TRANSACTION_H_
#define TRANSACTION_H_
using namespace std;
#include <iostream>
#include <vector>
#include <string>
class Transaction
{
    public:
        Transaction();
        Transaction(char typetransaction, int account_id, int fundtype, int amount); // deposit or withdraw 
        Transaction(char typetransaction, int account_id, int fromfundtype,int other_id, int tofundtype ,int amount); // transfer
        Transaction(char typetransaction, int id);  //  Display the history for all transactions of a given fund 
        Transaction(char typetransaction, int id, int fund_type);  // Display the history of all transactions for a client account  
        Transaction(char typetransaction, int id, string firstname, string lastname); // open account

        string GetFirstName() const;
        string GetLastName() const;
        int GetAmount() const;
        int GetId() const;
        int GetType() const;
        void SetType(int type);
        void SetWithdraw(bool check);
        void SetAmount(int amount);
        int GetOtherAccountId() const;
        int GetOtherFundId() const;
        char GetAction() const;
        void Display();
        friend ostream& operator<<(ostream &output,const Transaction& obj);



    private:
        string lastname_; 
        string firstname_; 
        int amount_; 
        int id_; 
        char action_; // type of transactions // 
        int fund_type_; 
        int other_fund_id_;
        int other_account_id_;
        bool check_withdraw;

};
#endif




