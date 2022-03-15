#include "mat.hpp"
#include <iostream>
using namespace std;


int main(int argc, char  **argv)
{
    char firstSymbol, secondSymbol;
    int row, column;

    cout << "Please insert column size : " << endl;
    cin >> column;

    cout << "Please insert row size : " << endl;
    cin >> row;

    cout << "Please insert first symbol: " << endl;
    cin >> firstSymbol;

    cout << "Please insert second symbol: " << endl;
    cin >> secondSymbol;

    try {  cout << ariel::mat(column, row, firstSymbol, secondSymbol) << endl; }
    catch (exception& e)
    { cout << "exception was happen :" << e.what() << endl;}

    return 0;
}
