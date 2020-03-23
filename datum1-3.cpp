#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

#define true 1
#define false 0

class datum
{
public:
//Konstruktor
    datum();
    datum(const int tt);
    datum(const int tt,const int mm);
    datum(const int tt,const int mm,const int jjjj);
    datum(const string sDatum);
    
    void display(void) 
    {
        cout << "Datum: "<<TAG<<"."<<MONAT<< "."<<JAHR << endl;
        Sleep(5000);
    }

private:   
    int TAG= 0, MONAT= 0, JAHR= 0;

    bool schaltjahr (void)
    {
        if (JAHR % 4 == 0 && JAHR % 100 != 0 || JAHR % 4 == 0)
        {
            return (true);
        } 
        else return (false);
    }
    
    unsigned int anzahl_tage (void)
    {
        if (schaltjahr()) 
        {
            return (366);
        }
        else return (365);
    }

    void tag_vor (void)
    {
        TAG = TAG -1;
    }

    void tag_zurueck (void)
    {
        TAG = TAG -1;
    }
}; 

//Konstruktordefinitionen
datum::datum(){   
    time_t Uhrzeit;
    struct tm *timeinfo;
    char puffer [5] = {0};

    time (&Uhrzeit);
    timeinfo = localtime(&Uhrzeit); 
    //Tag
    strftime (puffer,5,"%d",timeinfo);
    TAG = atoi(puffer);
    //Monat
    strftime (puffer,5,"%m",timeinfo);
    MONAT = atoi(puffer);
    //Jahr
    strftime (puffer,5,"%Y",timeinfo);
    JAHR = atoi(puffer);
}
datum::datum(const int tt){   
    TAG = tt;
    datum();
}
datum::datum(const int tt, const int mm){
    datum();
    TAG = tt;
    MONAT = mm;
}
datum::datum(const int tt, const int mm, const int jjjj){
    datum();
    TAG = tt;
    MONAT = mm;
    JAHR = jjjj;
}
datum::datum(const string sDatum){
    istringstream strin;
    
    string sTag, sMonat, sJahr,sZeichen;
    sTag.clear();
    sMonat.clear();
    sJahr.clear();
    sZeichen.clear();

    sZeichen = ".";
    int position = 0, position2 = 0;
   
    if(!sDatum.empty())
    {
        position = sDatum.find(sZeichen);
        sTag = sDatum.substr(0,position);
        TAG = stoi(sTag);

        position2 = sDatum.find(sZeichen,position+1);
        sMonat = sDatum.substr(position+1,position2-(position+1));
        MONAT = stoi(sMonat);

        sJahr = sDatum.substr(position2+1,4);   
        JAHR = stoi(sJahr);
        /*
        strin.str(sTag);
        strin>>TAG;
        strin.str(sMonat);
        strin>>MONAT;
        strin.str(sJahr);
        strin>>JAHR;  
        */
    }   
}

int main (void)
{
    string sDatum ("17.06.1953");
    datum Aufgabe_a, Aufgabe_b(17),Aufgabe_c(17,6),Aufgabe_d(17,6,1953),Aufgabe_e(sDatum);
    char eingabe;

    cout<<"Welche Aufgabe aus D53A soll ausgefuehrt werden?"<<endl <<"a); b); c); d); e)" <<endl;
    cin >> eingabe;

    switch(eingabe)
    {
        case 'A':
        case 'a':
                Aufgabe_a.display();
                break;
        case 'B':
        case 'b':
                Aufgabe_b.display();
                break;     
        case 'C':
        case 'c':
                Aufgabe_c.display();
                break;
        case 'D':
        case 'd':
                Aufgabe_d.display();
                break;
        case 'E':
        case 'e':
                Aufgabe_e.display();
                break;
        default :
                cout<<"Eingabe fehlerhaft!"<<endl;
                Sleep(2000);
    }

    return 0; 
}  
