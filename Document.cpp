/*Adi Achwal 311233688*/
/*Amit nuni 204359400*/

#include "Document.h"
#include <iostream>
using namespace std;

Document::Document() : curr(-1) {}
/**
 * prints the current line
 */
void Document :: print_curr_line(){

    if (this->curr == -1) {
        cout << "no lines" << endl;
        return;
    }
    cout<<this->lines[this->curr]<<endl;
}
/**
 makes Tab than prints the current line using print_curr_line() .
 */
void Document :: print_line_num(){
   cout << this->curr+1 << "         ";
    this->print_curr_line();
}

/**
 * prints all lines
 */
void Document :: print_all(){
    for (int i = 0; i < this->lines.size(); i++) {
       cout << this->lines[i] << endl;
    }
}
/**
 * n is now the current line and prints it using print_curr_line()
 * @param n the new current line
 */
void Document :: line_num(int n){
    n--;
    if (this->lines.size() <= n) {
        cout << "?" << endl;
        return;
    }
    this->curr = n;
   cout<<this->lines[this->curr]<<endl;

}
/**
 Append line to doc
 */
void Document :: append(){
 
    string line;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, line);
    while (line != ".") {
        vector<string>::iterator it;
        it = lines.begin();
        this->curr++;
        this->lines.insert(it + this->curr, line);
        getline(cin, line);
    }
}

/**
 * insert line to doc before the current line
 */
void Document :: insert(){
    string line;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, line);
    if (this->curr == -1) {
        this->curr++;
    }
    while (line != ".") {
        vector<string>::iterator it;
        it = lines.begin();
        this->lines.insert(it + this->curr, line);
        this->curr++;
        getline(cin, line);
    }
}
/**
 * changing the line with new data
 */
void Document :: change(){
 
    this->delete_curr();
    this->append();
}

/**
 * delete current line
 */
void Document :: delete_curr(){
    vector<string>::iterator it;
    it = lines.begin();
    this->lines.erase(it + this->curr);
    this->curr--;
}
/**
 * search for string in doc
 */
void Document :: search(string text){

    for (int i = this->curr; i < this->lines.size(); i++) {
        if (this->lines[i].find(text) != string::npos) {
            cout << this->lines[i] << endl;
            this->curr = i;
            return;
        }
    }
    for (int i = 0; i < this->curr; i++) {
        if (this->lines[i].find(text) != string::npos) {
            cout << this->lines[i] << endl;
            this->curr = i;
            return;
        }
    }

}
void Document :: replace(string old_s, string new_s){
    if (this->lines[this->curr].find(old_s) != std::string::npos) {
        int index = this->lines[this->curr].find(old_s);
        this->lines[this->curr].replace(index, old_s.size(), new_s);
    }

}
void Document :: quits(){}