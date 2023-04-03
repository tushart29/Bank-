
#include "Transaction.h"
using namespace std;
#include <iostream> 
#include <queue>

Transaction::Transaction()
{
    lastname_ = "lastname";
    firstname_ = "firstname";
    amount_ = 0;
    id_ = 0;
    action_ = 'action'; // type of transactions
    fund_type_ = 0;
    other_fund_id_ = 0;
    other_account_id_ = 0;
    check_withdraw = false;
}
Transaction::Transaction(char typetransaction, int account_id, int fundtype, int amount)
{
    action_ = typetransaction;
    id_ = account_id;
    fund_type_ = fundtype;
    amount_ = amount;
    check_withdraw = false;
}
Transaction::Transaction(char typetransaction, int account_id, int fromfundtype,int other_id, int tofundtype ,int amount)
{
    action_ = typetransaction;
    id_ = account_id;
    fund_type_ = fromfundtype;
    other_account_id_ = other_id;
    other_fund_id_ = tofundtype;
    amount_ = amount;
    check_withdraw = false;
}
Transaction::Transaction(char typetransaction, int id)
{
    action_ = typetransaction;
    id_ = id;
    check_withdraw = false;
}
Transaction::Transaction(char typetransaction, int id, int fund_type)
{
    action_ = typetransaction;
    id_ = id;   
    fund_type_ = fund_type;
    check_withdraw = false;
}
Transaction::Transaction(char typetransaction, int id, string firstname, string lastname)
{
    
    action_ = typetransaction;
    id_ = id;
    firstname_ = firstname;
    lastname_ = lastname;
    check_withdraw = false;
}
string Transaction::GetFirstName() const
{
    return firstname_;
}
string Transaction::GetLastName() const
{
    return lastname_;
}
int Transaction::GetAmount() const
{
    return amount_;
}
int Transaction::GetId() const
{
    return id_;
}
int Transaction::GetType() const
{
    return fund_type_;
}
char Transaction::GetAction() const
{
    return action_;
}
int Transaction::GetOtherAccountId() const
{
    return other_account_id_;
}
int Transaction::GetOtherFundId() const
{
    return other_fund_id_;
}
void Transaction::SetWithdraw(bool check)
{
    check_withdraw = check;
}
void Transaction::SetType(int type)
{
    fund_type_ = type;
}
void Transaction::SetAmount(int amount)
{
    amount_ = amount;
}
ostream& operator<<(ostream &output,const Transaction& tran) 
{
    //output << "FirstName: " << tran.firstname_ << " LastName: " << tran.lastname_ << " Amount:" << tran.amount_ << " ID:" << tran.id_ 
    //<< " OtherAccountID: " << tran.other_account_id_ << " TransactionType: " << tran.action_ << " FundType: " << tran.fund_type_ << " OtherFundType: " << tran.other_fund_id_ << endl;
    if(tran.GetAction() == 'D' || tran.GetAction() == 'W')
    {
        output << tran.GetAction() << " " << tran.GetId()  << " " << tran.GetType() << " " << tran.GetAmount() << endl;
    }
    else
    {
        output << tran.GetAction() << " " << tran.GetId()  << " " << tran.GetType() << " " << tran.GetOtherAccountId() << " " << tran.GetOtherFundId() << " " << tran.GetAmount() << endl;
    }
    return output;  
} 