#include "Fund.h"


Fund::Fund()
{
    balance = 0;

}
Fund::Fund(string fund_name)
{
    name_of_fund = fund_name;
    balance = 0;
}
bool Fund::AddFunds(int amount)
{
    balance += amount;
    return true;
}
bool Fund::RemoveFunds(int amount)
{
    balance -= amount;
    return true;
}
void Fund::DisplayTotalFunds()
{
    cout << name_of_fund << ": $" << balance << endl;
}
void Fund::DisplayHistory()
{
    cout << name_of_fund << ": $ " << balance << endl;
    for(int i =0; i < funds_history.size();i++)
    {
        cout << " " << funds_history[i];
    }
}
void Fund::DisplayHistoryFund(int fund_type)
{
    int i = 0;
    for(i = 0; i < funds_history.size(); i++)
    {
        cout << " " << funds_history[i];
    }
    
}
string Fund::GetFundName()
{
    return name_of_fund;
}
int Fund::GetBalance()
{
    return balance;
}
bool Fund::PushFunds(Transaction obj)
{
    funds_history.push_back(obj);
    return true;
}
