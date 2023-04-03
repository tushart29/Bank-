

#include "Bank.h"

using namespace std;
int main(int argc, char* argv[])
{
    Bank one; 
    string file(argv[1]);
    one.ReadFile(file);
    one.ExecuteTransactions();
    one.Display_Transactions();
}