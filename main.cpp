#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::setw;
using std::setfill;
using std::left;
using std::right;
using std::setprecision;

struct irasas{
    string var, pav;
    int egz;
    vector <int> paz;
    double vid, med, rez1, rez2;
    void Vid();
    void Med();
    void Rez1();
    void Rez2();
};

int main()
{
    vector <irasas> duomenubaze;
    irasas temp; int temp_nd; char pakl;
    do{
        cout<<"Iveskite varda: "; cin>>temp.var;
        cout<<"Iveskite pavarde: "; cin>>temp.pav;
        cout<<"Iveskite egzamino pazymi: "; cin>>temp.egz;
        cout<<"iveskite pazymi: "<<endl; cin>>temp_nd;
        temp.paz.clear();
        while(temp_nd!=0){
            if(temp_nd>0 && temp_nd<11) temp.paz.push_back(temp_nd);
            else{cout<<"Netinkamas pazymys, bandykite is naujo: ";}
            cin>>temp_nd;
        }
     temp.Vid(); temp.Med(); temp.Rez1();temp.Rez2();
     duomenubaze.push_back(temp);
     cout<<"Ar norite ivesti kita? (t/kitas kl.) ";
     cin>>pakl;
     }while (pakl == 't');
     cout<<"Rezultatui skaiciuoti naudojama vidurkis ar mediana? (v/m) ";
     char h;
     cin>>h;

     cout<<setfill(' ')<<setw(12)<<left<<"Vardas"<<setw(13)<<left<<"Pavarde"<<right<<"Galutinis (Vid.)/Galutinis (Med.)"<<endl;
     cout<<setfill('-')<<setw(58)<<'-'<<endl;
     for (irasas a: duomenubaze)
     {
         if (h=='m')
            cout<<setfill(' ')<<setw(12)<<left<<a.var<<setw(25)<<left<<a.pav<<right<<a.rez2<<setprecision(3)<<endl;
         else
         cout<<setfill(' ')<<setw(12)<<left<<a.var<<setw(25)<<left<<a.pav<<right<<a.rez1<<setprecision(3)<<endl;
     }


}

    void irasas::Vid(){
        vid=0;
        for (int a : paz)
            vid+=a;
        vid=double(vid)/paz.size();
    }
    void irasas::Med(){
        sort(paz.begin(), paz.end());
       med=(paz.size()%2==0) ? (paz[paz.size()/2-1]+paz[paz.size()/2])/2 : paz[paz.size()/2];
    }
    void irasas::Rez1(){
        rez1=0.4*vid+0.6*egz;
    }
    void irasas::Rez2(){
        rez2=0.4*med+0.6*egz;
    }
