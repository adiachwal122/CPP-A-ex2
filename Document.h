/*Adi Achwal 311233688*/
/*Amit nuni 204359400*/
#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <vector>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

class Document {

private:
    vector <string> lines;
    int curr;
public:

    Document();
    void print_curr_line();  //p- prints the current line
    void print_line_num();  //n- prints line number of current line followed by TAB followed by current line
    void print_all(); // %p- prints all lines
    void line_num(int);    //7- makes line #7 the current line
    void append(); //a- appends new text after the current line
    void insert();  //  i- inserts new text before the current line
    void change();  // c- changes the current line for text that follows
    void delete_curr();  //d- deletes the current line
    void search(string); // /text- searches forward after current line for the specified text. The search wraps to the beginning of the buffer and continues down to the current line, if necessary
    void replace(string, string);  // s/old/new/- replaces old string with new in current line
    void quits(); //Q- Quits the editor without saving
};
#endif



