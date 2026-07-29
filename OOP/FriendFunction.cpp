#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Chai{
    private:
        string teaName;
        int servings;

    public:
        Chai(string Name, int serve){
            string TeaName = Name;
            int servings = serve;
        }

        friend bool compareServings(const Chai &Chai1, const Chai &Chai2);

        void display() const{

            cout<<"tea Name:"<<teaName<<endl;

        }

};

bool compareServings(const Chai &Chai1, const Chai &Chai2){
    return Chai1.servings>Chai2.servings;
}




int main(){

    Chai MasalaChai("Masala Chai",2);
    MasalaChai.display();

    Chai GingerTea("Ginger Tea", 4);
    GingerTea.display();

    return 0;
}