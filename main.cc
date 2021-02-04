/*
* Author: Blake Boehringer
* Date: 2/03/2021
* Description:
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "numlist.h"
using namespace std;

//function prototypes
int main() 
{
    NumList MyNum;
    ifstream MyIfs;
    ofstream MyOfs;
    string filename;
    int num0, num1, num2;

    cout << "-Please input the name of your file: ";
    cin >> filename;

    MyIfs.open(filename.c_str());

    if(MyIfs.fail())
    { 
        cout << "-File error." << endl;

        return 1;
    }

    MyNum.load_from_file(MyIfs);
    MyIfs.close();

    MyNum.b_sort();

    MyOfs.open("blake.dat");
    cout << "Please enter 3 of your own numbers to insert into the list: ";
    cin >> num0;
    cin >> num1;
    cin >> num2;
    MyNum.insert(num0);
    MyNum.insert(num1);
    MyNum.insert(num2);
    MyNum.b_sort();
    MyNum.save_to_file(MyOfs);
    MyOfs.close();


    return 0;
}