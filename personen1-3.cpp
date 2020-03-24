#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

class personen
{
private:
    string Vorname, Nachname, Kennzeichen;
    int Geburtsdatum, Kilometerstand;   
public:
    personen();
    personen(const string firstname, const string lastname);
    personen(const string firstname, const string lastname, const int birthday);
    void print1 (void)
    {
        cout<<Vorname<<" "<<Nachname<<" "<<Geburtsdatum<<endl;
        Sleep(2000);
    }
    void print2 (void)
    {
        cout<<Nachname<<" "<<Vorname<<endl;
    }
    bool is_ok(void)
    {
        if (!Vorname.empty() && !Nachname.empty() && !Kennzeichen.empty() && Geburtsdatum > 0 && Kilometerstand > 0) return true;
        else return false;
    }
};
personen::personen()
{
    Vorname.clear();
    Nachname.clear();

    time_t Rawtime;
    struct tm * timeinfo;
    char puffer[9] = {0};
    time (&Rawtime);
    timeinfo = localtime(&Rawtime);

    strftime(puffer,9,"%Y%m%d",timeinfo);
    Geburtsdatum = stoi(puffer);
}

personen::personen(const string firstname, const string lastname)
{
    this->Vorname = firstname;
    this->Nachname = lastname;
    this->Geburtsdatum = personen().Geburtsdatum;
}

personen::personen(const string firstname, const string lastname, const int birthday)
{
    this->Vorname = firstname;
    this->Nachname = lastname;
    this->Geburtsdatum = birthday;  
}

int main (void)
{
    string V_Name = "Paul", N_Name = "Meier";
    int G_Datum = 19901003;
    char eingabe;
    personen *Aufg_a,*Aufg_b,*Aufg_c; 
    
    cout<<"Welche Aufgabe aus D53A soll ausgefuehrt werden?"<<endl <<"a); b); c);" <<endl;
    cin.get(eingabe);

    switch(eingabe)
    {
        case 'A':
        case 'a':
                Aufg_a = new personen;
                Aufg_a->print1();
                break;
        case 'B':
        case 'b':
                Aufg_b = new personen(V_Name,N_Name);
                Aufg_b->print1();
                break;     
        case 'C':
        case 'c':               
                Aufg_c = new personen(V_Name,N_Name,G_Datum);
                Aufg_c->print1();
                break;
        default :
                cout<<"Eingabe fehlerhaft!"<<endl;
                Sleep(2000);
    }
    return 0;
}
