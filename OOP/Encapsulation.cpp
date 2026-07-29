#include <iostream>

using namespace std;

class BankAccount{
    private: 
        string AccountNumber;
        double balance;
    
    public:
        BankAccount(string AccNo, double Bal){
            AccountNumber = AccNo;
            balance = Bal;

        }
        //getter
        double GetBalance()const{
            return balance;
        }
        //method to deposit money

        void DepositMoney(double Ammount){
            if(Ammount>0){
                balance += Ammount;
                
                cout<<"Ammount Deposited : "<< Ammount<<endl;

            }else{
                cout<<"Invalid Deposit"<<endl;

            }

        }
};