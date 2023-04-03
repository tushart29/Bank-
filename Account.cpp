using namespace std;
#include <iostream> 
#include <queue>
#include <fstream>
#include <sstream>
#include "Account.h"

Account::Account()
{

}
Account::Account(string firstname, string lastname, int id)
{
    firstname_ = firstname;
    lastname_ = lastname;
    account_id_ = id;
    types[0] = new Fund("Money Market");
    types[1] = new Fund("Prime Money Market");
    types[2] = new Fund("Long-Term Bond");
    types[3] = new Fund("Short-Term Bond");
    types[4] = new Fund("500 Index Fund");
    types[5] = new Fund("Capital Value Fund");
    types[6] = new Fund("Growth Equity Fund");
    types[7] = new Fund("Growth Index Fund");
}
void Account::Record(Transaction obj, int fund_type)
{
    types[fund_type]->PushFunds(obj);
}
void Account::RecordInClass(Transaction obj, int fund_type)
{
    types[fund_type]->PushFunds(obj);
}
bool Account::Deposit(int fund_id, int amount)
{
    if(amount < 0)
    {
        cerr << "ERROR: " << amount << " is less than 0 " << endl;
    }
    else
    {
        types[fund_id]->AddFunds(amount); 
    }
    
    return true;
}
bool Account::Withdraw(int fund_id, int amount)
{ 

    if(amount > 0 && obj_.GetAction() != 'T')
    {
        if(fund_id == 0)
        {
            if(types[0]->GetBalance() + types[1]->GetBalance() < amount)
            {
                check = false;
                cerr << "ERROR: Not enough funds to withdraw " <<  amount << " from " <<  lastname_ << " " << firstname_ <<  " " << types[0]->GetFundName() << endl;
                Record(obj_,0);
            }
            else if(types[0]->GetBalance() < amount)
            {
                check = true;
                int current_fund = types[0]->GetBalance();
                types[0]->RemoveFunds(current_fund);
                int remaning_fund = amount - current_fund;
                types[1]->RemoveFunds(remaning_fund);
                obj_.SetAmount(current_fund);
                obj_another.SetAmount(remaning_fund);
                obj_another.SetType(1);
                Record(obj_,0);
                Record(obj_another,1);
            }
            else
            {
                check = true;
                types[0]->RemoveFunds(amount); 
                Record(obj_,0);
            }
        }
        if(fund_id == 1)
        {
            if(types[1]->GetBalance() + types[0]->GetBalance() < amount)
            {
                check =false;
                cerr << "ERROR: Not enough funds to withdraw " <<  amount << " from " <<  lastname_ << " " << firstname_ <<  " " << types[1]->GetFundName() << endl;
                
                Record(obj_,1);
            }
            else if(types[1]->GetBalance() < amount)
            {
                check = true;
                int current_fund = types[1]->GetBalance();
                types[1]->RemoveFunds(current_fund);
                int remaning_fund = amount - current_fund;
                types[0]->RemoveFunds(remaning_fund);
                obj_.SetAmount(current_fund);
                obj_another.SetAmount(remaning_fund);
                obj_another.SetType(0);
                Record(obj_,1);
                Record(obj_another,0);
            }
            else
            {
                check = true;
                types[1]->RemoveFunds(amount); 
                Record(obj_,1);
            }
        }
        if(fund_id == 2)
        {
            if(types[2]->GetBalance() + types[3]->GetBalance() < amount)
            {
                check = false;
                cerr << "ERROR: Not enough funds to withdraw " <<  amount << " from " <<  lastname_ << " " << firstname_ <<  " " << types[2]->GetFundName() << endl;
                Record(obj_,2);
            }
            else if(types[2]->GetBalance() < amount)
            {
                check = true;
                int current_fund = types[2]->GetBalance();
                types[2]->RemoveFunds(current_fund);
                int remaning_fund = amount - current_fund;
                types[3]->RemoveFunds(remaning_fund);
                obj_.SetAmount(current_fund);
                obj_another.SetAmount(remaning_fund);
                obj_another.SetType(3);
                Record(obj_,2);
                Record(obj_another,3);
            }
            else
            {
                check = true;
                types[2]->RemoveFunds(amount); 
                Record(obj_,2);
            }
        }
        if(fund_id == 3)
        {
            if(types[3]->GetBalance() + types[2]->GetBalance() < amount)
            {
                check = false;
                cerr << "ERROR: Not enough funds to withdraw " <<  amount << " from " <<  lastname_ << " " << firstname_ <<  " " << types[3]->GetFundName() << endl;
                Record(obj_,3);
            }
            else if(types[3]->GetBalance() < amount)
            {
                check = true;
                int current_fund = types[3]->GetBalance();
                types[3]->RemoveFunds(current_fund);
                int remaning_fund = amount - current_fund;
                types[2]->RemoveFunds(remaning_fund);
                obj_.SetAmount(current_fund);
                obj_another.SetAmount(remaning_fund);
                obj_another.SetType(2);
                Record(obj_,3);
                Record(obj_another,2);
            }
            else
            {
                check = true;
                types[3]->RemoveFunds(amount); 
                Record(obj_,3);
            }
        }
        else
        {
            
            if(fund_id == 4)
            {
                if(types[4]->GetBalance() < amount)
                {
                    check = false;
                    cerr << "ERROR: Not enough funds to withdraw " <<  amount << " from " <<  lastname_ << " " << firstname_ <<  " " << types[4]->GetFundName() << endl;
                    Record(obj_,4);
                }
                else
                {
                    check = true;
                    types[fund_id]->RemoveFunds(amount);
                    Record(obj_,4); 
                }
            }
            if(fund_id == 5)
            {
                if(types[5]->GetBalance() < amount)
                {
                    check = false;
                    cerr << "ERROR: Not enough funds to withdraw " <<  amount << " from " <<  lastname_ << " " << firstname_ <<  " " << types[5]->GetFundName() << endl;
                    Record(obj_,5);
                }
                else
                {
                    check = true;
                    types[fund_id]->RemoveFunds(amount); 
                    Record(obj_,5); 
                }
            }
            if(fund_id == 6)
            {
                if(types[6]->GetBalance() < amount)
                {
                    check = false;
                    cerr << "ERROR: Not enough funds to withdraw " <<  amount << " from " <<  lastname_ << " " << firstname_ <<  " " << types[6]->GetFundName() << endl;
                    Record(obj_,6);
                }
                else
                {
                    check = true;
                    types[fund_id]->RemoveFunds(amount); 
                    Record(obj_,6); 
                }
            }
            if(fund_id == 7)
            {
                if(types[7]->GetBalance() < amount)
                {
                    check = false;
                    cerr << "ERROR: Not enough funds to withdraw " <<  amount << " from " <<  lastname_ << " " << firstname_ <<  " " << types[7]->GetFundName() << endl;
                    Record(obj_,7);
                }
                else
                {
                    check = true;
                    types[fund_id]->RemoveFunds(amount); 
                    Record(obj_,7); 
                }
            }
        }
    }
    
    return true;
}

bool Account::Transfer(Account* other,int id, int fund_id,int other_fund_id ,int amount)
{
    
    Withdraw(fund_id,amount);
    if(check  == true)
    {
        other->types[other_fund_id]->AddFunds(amount);
    }
    return true;   
}
string Account::GetFirstName() const
{
    return firstname_;
}
string Account::GetLastName() const
{
    return lastname_;
}
int Account::GetAmount() const
{
    return amount_;
}
int Account::GetId() const
{
    return account_id_;
}
int Account::GetFundType() const
{
    return fundtype_;
}

bool Account::DisplayFundsinBank()
{
    cout << lastname_ << " " << firstname_ << " " << "Account ID: " << account_id_ << endl;

    for(int i = 0; i < 8; i++)
    {
        cout <<  " " << types[i]->GetFundName() << ": $" << types[i]->GetBalance() << endl;
    }
    cout << endl;
    return true;
}
bool Account::DisplayFunds(int fund_type)
{
    cout << "\nTransaction history for " << lastname_ << " " << firstname_ << " " << types[fund_type]->GetFundName() << ": $" << types[fund_type]->GetBalance() << endl;
    types[fund_type]->DisplayHistoryFund(fund_type);
    return true;
}
bool Account::DisplayFundsinAccount()
{
    cout << "\nTransaction History for " <<  lastname_ << " " <<  firstname_ <<   " by fund. " << endl;

    for(int i = 0; i < 8; i++)
    {
        types[i]->DisplayHistory();
    }
    return true;
}

ostream& operator<<(ostream &output, const Account& obj){

    output << "FirstName: " << obj.GetFirstName() << " LastName: " << obj.GetLastName() << " Account: " << obj.GetId() << endl;
    return output;
}

 