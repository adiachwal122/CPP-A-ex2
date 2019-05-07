/*Adi Achwal 311233688*/
/*Amit nuni 204359400*/
#include "Editor.h"
#include <iostream>
using namespace std;

Editor:: Editor() {}

void Editor :: loop (){
    bool b = true;
    string temp;
    int number;
    while (b){
        cin>>temp;
      
        if (temp == "p"){
            test.print_curr_line();
        }
        else if (temp == "n"){
            test.print_line_num();
        }
        else if (temp == "%p"){
            test.print_all();
        }

        else if (temp == "a"){
            test.append();
        }
        else if (temp == "i"){
            test.insert();
        }
        else if (temp == "c"){
            test.change();
        }
        else if (temp == "d"){
            test.delete_curr();
        }
        else if (temp.at(0) == '/'){
            test.search(temp.substr(1,temp.size()));
        }
        else if (temp.at(0) == 's') {
            if (temp.substr(2, temp.size()).find('/') != std::string::npos) {
                int index = temp.substr(2, temp.size()).find('/');
                test.replace(temp.substr(2, index), temp.substr(index + 3, temp.size() - (index + 4)));
            } else
                cout << "not found" << endl;
        }
        else if (temp == "Q"){
            test.quits();
            exit(0);
            b=false;
        }
        else{
            istringstream iss (temp);
            iss >> number;
            if(number > 0) {
                test.line_num(number);
            }
        }
    }
}