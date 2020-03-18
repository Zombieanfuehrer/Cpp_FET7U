#include <iostream>
#include <windows.h>
using namespace std;

class bruch
{
public: 
    //Konstruktoren
    // a)
    bruch();
    // b)
    bruch(const int Ganzzahlen);
    // c)
    bruch(const int zaehler,const int nenner);
private:
    int ZAEHLER;
    int NENNER;

    bool is_ok (void)
    {
        if(NENNER != 0) return true;
        return false;
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
public:
    void display(void)
    {
        if(is_ok()) cout << ZAEHLER << "/" << NENNER;
        else        cout << "Bruch fehlerhaft!";
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

bruch::bruch(){
        ZAEHLER = 0;
        NENNER = 1;
}
bruch::bruch(const int Ganzzahlen){
        ZAEHLER = Ganzzahlen;
        NENNER = 1;
}
bruch::bruch(const int zaehler,const int nenner){
        ZAEHLER = zaehler;
        NENNER = nenner;
}

int main (int argc, char *argv[])
{
    bruch Zahl;

    if (argc >= 2)
    {
        if (strcmp(argv[2],"b"))
        {
            bruch Zahl(7);    
        }
        if (strcmp(argv[2],"c"))
        {
            bruch Zahl(3,4);
        } 
    }

    Zahl.plus1();
    Zahl.malx(10);
    Zahl.display();   
    cout << endl << Zahl.dblwert() << endl;
    Sleep(5000);
    return 0;
}


