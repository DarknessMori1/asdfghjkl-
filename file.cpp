#include <iostream>
#include <string>
#include "file.h"
#include "libhelp.h"

using namespace std;

   bool Hflag = false;
    bool Rflag = false;
    int RetValue = 0;

    for (int i=0; i<argc; i++){
        cout <<"argv[" << i << "] = " << argv[i] << endl;
        if( (string(argv[i]) == "-h" ) or 
            (string(argv[i]) == "--help")  )
            { 
                Hflag = true;
            }

            if ((string(argv[i]) == "--return") and
                ((i + 1) < argc))
            { 
                Rflag = true;
                RetValue = atoi(argv[i+1]);
                cout << "RetValue = " << RetValue << endl ;
            }
    }
    cout << "hello world\n";
    if(Hflag == true){
        help(31,15,81); //вызов функции HELP
        PrintHelp(55,11,22); //вызов функции HELP бибилиотечный
    }

    return RetValue;
 }/*void foo(); //объявление функции foo (перенесено в file.h)*/

 int main(int argc, char* argv[]){
 

void help(
    int major_ver, //первое значение функции
    int minor_ver, //второе
    int patch_ver /*третье*/
){
        cout << "Print help from file.cpp" << endl;    
        cout<< major_ver << "." << minor_ver << "." << patch_ver << endl;
}

/*int main (int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    cout << "Hello world!!!\n";
    cerr << "ERROR\n";
    cout << "Hello world!!!\n";
    cerr << "ERROR\n";
    cout << "Hello world!!!\n";
    cerr << "ERROR\n";
    cout << "Hello world!!!\n";
    cerr << "ERROR\n";
    cout << "Hello world!!!\n";
    cerr << "ERROR\n";
    cout << "Hello world!!!\n";
    cerr << "ERROR\n";

    for (int i=0; i<argc; i++){
        cout <<"argv[" << i << "] = " << argv[i] << endl;

    }

    return 0;
}*/

