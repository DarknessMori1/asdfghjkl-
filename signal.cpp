#include <iostream>
#include <csignal>
using namespace std;

void SIGTERM_h (int signal){
    cout << signal << " ? Ha-ha-ha" << endl;
}

void SIGINT_h (int signal){
    cout << signal << " ? Ha-ha-ha" << endl;
}

void SIGHUP_h (int signal){
    cout << signal << " ? Ha-ha-ha" << endl;
}

void SIGTSTP_h (int signal){
    cout << signal << " ? Ha-ha-ha" << endl;
}

void SIGQUIT_h (int signal){
    cout << signal << " ? Ha-ha-ha" << endl;
}

void SIGSTOP_h (int signal){
    cout << signal << " ? Ha-ha-ha" << endl;
}

void SIGABRT_h (int signal){
    cout << signal << " ? Ha-ha-ha" << endl;
}

int main ()
{
    setlocale(LC_ALL, "Russian");

    signal(SIGTERM, SIGTERM_h);
    //raise(SIGTERM);

    signal(SIGINT, SIGINT_h);
    //raise(SIGINT);

    signal(SIGHUP, SIGHUP_h);
   // raise(SIGHUP);

    signal(SIGTSTP, SIGTSTP_h);
   // raise(SIGTSTP);

    signal(SIGQUIT, SIGQUIT_h);
   // raise(SIGQUIT);
    
    signal(SIGSTOP, SIGSTOP_h);
   // raise(SIGTERM);

    signal(SIGABRT, SIGABRT_h);
   // raise(SIGABRT);

    for (int i = 0; i < 55; i++){
        sleep(1);
    }
    return EXIT_SUCCESS;

    /*cout << "Hello world!!!\n";
    return 0;*/
}