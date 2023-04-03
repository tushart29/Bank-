
using namespace std;
#include <iostream> 
#include <queue>
#include <fstream>
#include <sstream>
#include "Bank.h"

Bank::Bank()
{
    lastname_ = "";
    firstname_ = "";
    amount_ = 0;
    id_ = 0;
}
bool Bank::ReadFile(const string &filename)
{
    ifstream in_file;
    in_file.open(filename);
    string line;

    string lastname;
    string firstname;
    int amount;
    int id; // account id
    int other_id; // what id to transfer to 
    string action; // type of transactions
    int fund_type; // what fund transferring from 
    int other_fund_type; // what fund transferring to 
    char transaction_type;

    while (getline(in_file, line)) // are we assuming that there are not empty lines after the last line
    {
        if(line == "")
        {
            continue;
        }
        istringstream parseline(line);
        parseline >> transaction_type;
        
        if(transaction_type == 'O')
        {
            parseline >> id >> firstname >> lastname;
            Transaction store_one(transaction_type, id, firstname, lastname);
            storage_transaction.push(store_one);
        }
        if(transaction_type == 'D')
        {
            parseline >> id >> fund_type >> amount;
            Transaction store_two(transaction_type, id,fund_type,amount);
            storage_transaction.push(store_two);
        }
        if(transaction_type == 'W')
        {
            parseline >> id >> fund_type >> amount;
            Transaction store_three(transaction_type, id,fund_type,amount);
            storage_transaction.push(store_three);
        }
        if(transaction_type == 'T')
        {
            parseline >> id >> fund_type >> other_id >> other_fund_type >> amount;
            Transaction store_four(transaction_type, id, fund_type,other_id, other_fund_type , amount);
            storage_transaction.push(store_four);
        }
        if(transaction_type == 'A')
        {
            parseline >> id;
            Transaction store_five(transaction_type, id);
            storage_transaction.push(store_five);
        }
        if(transaction_type == 'F')
        {
            parseline >> id >> fund_type;
            Transaction store_six(transaction_type, id, fund_type);
            storage_transaction.push(store_six);
        }
    }
    
    in_file.close();
    return true;
}

bool Bank::ExecuteTransactions()
{
    while (!storage_transaction.empty()) 
    {        
        Transaction obj = storage_transaction.front();
        if(obj.GetId() < 0)
        {
            cerr << "Accound ID: " << obj.GetId() << " less than zero" << endl;
        }
        else if(obj.GetAmount() < 0)
        {
            cerr << "ERROR: " << obj.GetAmount() << " is less than 0 " << endl;
        }
        
        else if(obj.GetAction() == 'O')
        {
            Account* one;
            if(accounts_.Retrieve(obj.GetId(),one))
            {
                cerr << "ERROR: " << "Account " << obj.GetId()  << " is already open. "  << " Transaction refused."<< endl;
            }
            else
            {
                one = new Account(obj.GetFirstName(),obj.GetLastName(), obj.GetId());
                accounts_.Insert(one);
            }
            
        }
        else if(obj.GetAction() == 'D')
        {
            Account* two;
            if(!(accounts_.Retrieve(obj.GetId(),two)))
            {
                cerr << "ERROR: " << "Account " <<  obj.GetId()  << " not found. Transferal refused." << endl;
            }
            if((obj.GetType() < 0 || obj.GetType() > 7))
            {
                cerr << "ERROR: " << obj.GetType() << " Incorrect Fund Type " << endl; 
            }
            
            else if(accounts_.Retrieve(obj.GetId(),two))
            {
                two->Record(obj,obj.GetType());
                two->Deposit(obj.GetType(),obj.GetAmount());
            }  

        }
        else if(obj.GetAction() == 'W')
        {
            Account* three;
            if(!(accounts_.Retrieve(obj.GetId(),three)))
            {
                cerr << "ERROR: " << "Account " <<  obj.GetId()  << " not found. Transferal refused." << endl;
            }
            if((obj.GetType() < 0 || obj.GetType() > 7))
            {
                cerr << "ERROR: " << obj.GetType() << " Incorrect Fund Type " << endl; 
            }
            if(obj.GetAmount() < 0)
            {
                cerr << "ERROR: " << obj.GetAmount() << " is less than 0 " << endl;
            }
            else if(accounts_.Retrieve(obj.GetId(),three))
            {
                three->obj_ = obj;
                three->obj_another = obj;
                //three->Record(obj,obj.GetType());
                three->Withdraw(obj.GetType(),obj.GetAmount());

            }  
        }
        else if(obj.GetAction() == 'T')
        {
            
            Account* four_one;
            Account* four_two;
            
            if(!(accounts_.Retrieve(obj.GetId(),four_one)))
            {
                cerr << "ERROR: " << "Account " <<  obj.GetId()  << " not found. Transferal refused." << endl;
            }
            if(!(accounts_.Retrieve(obj.GetOtherAccountId(),four_one)))
            {
                cerr << "ERROR: " << "Account " <<  obj.GetOtherAccountId()  << " not found. Transferal refused." << endl;
            }
            if(obj.GetAmount() < 0)
            {
                cerr << "ERROR: " << obj.GetAmount() << " is less than 0 " << endl;
            }
            if((obj.GetType() < 0)|| (obj.GetOtherFundId() < 0) || (obj.GetType() > 7) || (obj.GetOtherFundId() > 7))
            {
                cerr << "ERROR: Fund Type is incorrect" << endl;
            }
            else if(accounts_.Retrieve(obj.GetId(),four_one) && accounts_.Retrieve(obj.GetOtherAccountId(), four_two))
            {
                four_one->Transfer(four_two,obj.GetId(),obj.GetType(),obj.GetOtherFundId(),obj.GetAmount());    
            }
            if(obj.GetId() > 0 && obj.GetOtherAccountId() > 0 &&obj.GetId()  > 0 && obj.GetOtherAccountId() > 0 && obj.GetAmount() > 0)
            {
                if(obj.GetId() == obj.GetOtherAccountId())
                {
                    
                    four_one->Record(obj,obj.GetType());
                    four_one->Record(obj,obj.GetOtherFundId());
                    
                }
                if(obj.GetId() != obj.GetOtherAccountId())
                {
                    
                    four_one->Record(obj,obj.GetType());
                    four_two->Record(obj,obj.GetType());
                }       
            }
                
            
        }
        else if(obj.GetAction() == 'A')
        {
            Account* five;
            if((obj.GetType() < 0 || obj.GetType() > 7))
            {
                cerr << "ERROR: " << obj.GetType() << " Incorrect Fund Type " << endl; 
            }
            
            else if(accounts_.Retrieve(obj.GetId(),five))
            {
                five->DisplayFundsinAccount();
            }
        }
        else if(obj.GetAction() == 'F')
        {
            Account* six;
            if((obj.GetType() < 0 || obj.GetType() > 7))
            {
                cerr << "ERROR: " << obj.GetType() << " Incorrect Fund Type " << endl; 
            }
            
            else if(accounts_.Retrieve(obj.GetId(),six))
            {
                six->DisplayFunds(obj.GetType());
            }
        }
        storage_transaction.pop();
    }   
    return true;
}
void Bank::Display_Transactions () 
{
    cout << "\nFINAL BALANCES: " << endl;
    accounts_.Display();
}