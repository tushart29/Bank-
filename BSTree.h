
#include "Account.h"
class BSTree  
{ 
    public: 
        BSTree(); 
        BSTree(const BSTree& tree); 
        //~BSTree();
        
        bool Insert(Account *account); 
        
        // retrieve object, first parameter is the ID of the account 
        // second parameter holds pointer to found object, NULL if not found 
        bool Retrieve(int account_id, Account* & account) const; 
        
        // Delete object, first parameter is the ID of the account 
        // second parameter holds pointer to found object, NULL if not found 
        bool Delete(const int& account_id, Account* & account); 
        
        BSTree& operator=(const BSTree& tree); 
        void Display();
        void DisplayFunds();
        
        
        int Size();
    
        private:

            struct Node  
            {  
                Account* p_acct; 
                Node* right; 
                Node* left; 
            }; 
            Node* root_ = nullptr;
            void HelperDisplay(Node* root);
            bool HelperInsert(Account* account, Node* &root);
            bool HelperRetrive(int account_id ,Account*& account, Node* root) const;
            bool HelperDisplayFunds(Node* root);
            bool HelperDelete(Node* root, int account_id, Account*& account);
            int HelperSize(Node* root);
}; 
