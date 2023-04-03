

#include "BSTree.h"


BSTree::BSTree()
{

}

bool BSTree::Insert(Account *account)
{
    if(account->GetId() < 0)
    {
        return false;
    }
    else
    {
        return HelperInsert(account, root_);
    }
    return false;
    
}
bool BSTree::HelperInsert(Account* account, Node*& root)
{
    if(root == nullptr)
    {
        root = new Node();
        root->p_acct = account;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    }
    
    if(account->GetId() < root->p_acct->GetId())
    {
        HelperInsert(account, root->left);
    }
    else if(account->GetId() > root->p_acct->GetId())
    {
        HelperInsert(account, root->right);
    }
    
    return false;
}

bool BSTree::Retrieve(int account_id, Account*& account) const
{
    return HelperRetrive(account_id, account, root_);
}

bool BSTree::HelperRetrive(int account_id, Account*& account, Node* root) const
{
    if(root != nullptr)
    {
        if(account_id == root->p_acct->GetId())
        {
            account = root->p_acct;
            return true;
        }
        if(account_id < root->p_acct->GetId())
        {
            return HelperRetrive(account_id,account, root->left);
        }
        else
        {   
            return HelperRetrive(account_id,account, root->right);
        }
    }
    else
    {
        return false;
    }
}
void BSTree::HelperDisplay(Node* root)
{
    if(root != nullptr)
    {
        HelperDisplay(root->left);
        root->p_acct->DisplayFundsinBank();
        HelperDisplay(root->right);
    }
   
}
bool BSTree::HelperDisplayFunds(Node* root)
{
    if(root != nullptr)
    {
        HelperDisplayFunds(root->left);
        root->p_acct->DisplayFundsinAccount();
        HelperDisplayFunds(root->right);
    }
    return true;
   
}
void BSTree::DisplayFunds()
{
    HelperDisplayFunds(root_);
}
void BSTree::Display() 
{
    if(root_ ==nullptr)
    {
        return;
    }
    HelperDisplay(root_);
    
}
bool BSTree::Delete(const int& account_id, Account* & account)
{
    HelperDelete(root_,account_id,account);
}
bool BSTree::HelperDelete(Node* root, int account_id, Account*& account)
{
    if(root == nullptr)
    {
        return root;
    }
    if(root->p_acct->GetId() == account_id)
    {
        delete root;
        delete root->p_acct;
    }
    if(account_id < root->p_acct->GetId())
    {
        HelperDelete(root->left, account_id, account);
    }
    if(account_id > root->p_acct->GetId())
    {
        HelperDelete(root->right, account_id, account);
    }
    
}
int BSTree::Size() 
{
    return HelperSize(root_);
}
int BSTree::HelperSize(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + HelperSize(root->left) + HelperSize(root->right);
    }
}