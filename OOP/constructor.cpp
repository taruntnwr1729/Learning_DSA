#include <iostream>
#include <vector>

using namespace std;

//I am learning constructor in this file
class Chai{
    public:
        string teaName;
        int servings;
        vector <string> ingredients;

        //default constructor

        Chai(){
            teaName = "Unknown Tea";
            servings = 1;
            ingredients = {"Water","Tea Leaves"};

        }

        void displayFun(){
            cout<< "Tea Name: "<<teaName<<endl;
            cout<<"Servings: "<<servings<<endl;
            cout<<"Ingredients: ";

            for(string ingri : ingredients){
                cout<<"ingridient"<<" ";
            }

            cout<<endl;
        }

};

int main(){

    Chai chaiOne;

    chaiOne.displayFun();

    return 0;
}