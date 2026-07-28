#include <iostream>
#include <vector>

using namespace std;

//I am learning constructor in this file
class Chai{
    public:
        string teaName;
        int servings;
        vector <string> ingredients;

        //parameter constructor

        Chai(string name, int serve, vector<string> ingr){
            teaName = name;
            servings = serve;
            ingredients = ingr;

            cout<<"Parameter Constructor Called: "<<endl;

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

    Chai lemonTea("Lemon Tea", 2, {"water","tea","honey"});

    lemonTea.displayFun();

    return 0;
}