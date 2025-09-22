#include <iostream>
#include <string>
#include "file.h"


using namespace std;

/*void foo(); //объявление функции foo (перенесено в file.h)*/

 int main(int argc, char* argv[]){
    bool flag = false;
    
    for (int i=0; i<argc; i++){
        cout <<"argv[" << i << "] = " << argv[i] << endl;
        if( (string(argv[i]) == "-h" ) or 
            (string(argv[i]) == '--help')  )
            { 
                flag = true;
            }
    }
    cout << "hello world\n";
    if(flag == true){
        help(3,5,8); //вызов функции HELP
    }
 }

void help(
    int major_ver, //первое значение функции
    int minor_ver, //второе
    int patch_ver /*третье*/
){
    
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

