#include <iostream>
#include <windows.h>
using namespace std;

struct bruch
{
    int ZAEHLER;
    int NENNER;

    bool is_ok (void)
    {
        if(NENNER != 0) return true;
        return false;
    }
    void display(void)
    {
        if(is_ok()) cout << ZAEHLER << "/" << NENNER;
        else        cout << "Bruch fehlerhaft!";
    }
    unsigned int ggT (void)  
    {
        if (is_ok())
        {
            int rest, temp1 = ZAEHLER, temp2= NENNER;
            //Eukalidischer Algorithmus
            while (temp2)
            {
                rest = temp1 % temp2;   
                temp1 = temp2;
                temp2 = rest;    
            }
            return (temp1);
        }
        else display();  
    }
    void kuerzen (void)
    {
        if(is_ok())
        {
            unsigned int temp = ggT();
            ZAEHLER = ZAEHLER / temp;
            NENNER = NENNER / temp;
        }
        else display();

    }
    void plus1(void)
    {
        if(is_ok()) ZAEHLER = ZAEHLER + NENNER;
        else        display();
    }
    void minus1(void)
    {
        if(is_ok()) ZAEHLER = ZAEHLER - NENNER;
        else        display();
    }
    void plusx(int x)
    {
        if(is_ok()) ZAEHLER = ZAEHLER + ZAEHLER * NENNER;
        else        display();
    }
    void minusx(int x)
    {
        if(is_ok()) ZAEHLER = ZAEHLER - ZAEHLER * NENNER;
        else        display();
    }
    void malx(int x)
    {
        if(is_ok()) ZAEHLER = ZAEHLER * x;
        else        display();
    }
    void durchx(int x)
    {
        if(is_ok()) ZAEHLER = ZAEHLER / x;
        else        display();
    }
    double dblwert()
    {
        return (float) ZAEHLER / (float)NENNER;
    }
};

int main (void)
{
    bruch Zahl = {24531,10893};  //Vier Fünftel
    Zahl.plus1();
    Zahl.malx(10);
    Zahl.display();   
    cout << endl << Zahl.dblwert() << endl;
    cout << "ggT ist: " << Zahl.ggT()  << endl;
    Sleep(5000);
    return 0;
}


