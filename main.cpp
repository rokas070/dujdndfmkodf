#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

struct irasas{
    string var, pav;
    int egz;
    vector <int> paz;
    double vid, med, rez;
    void Vid();
    void Med();
    void Rez();
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
     temp.Vid(); temp.Med(); temp.Rez();
     duomenubaze.push_back(temp);
     cout<<"Ar norite ivesti kita? t/kitas kl. ";
     cin>>pakl;
     }while (pakl == 't');

     for (irasas a: duomenubaze)
     {
         cout<<"Vardas: "<<a.var<<endl;
         cout<<"Pavarde: "<<a.pav<<endl;
         cout<<"Egzaminas: "<<a.egz<<endl;
         for(int p: a.paz)
            cout<<p<<" : ";
         cout<<endl;
         cout<<"Vid.: "<<a.vid<<endl;
         cout<<"Med.: "<<a.med<<endl;
         cout<<"Rez.: "<<a.rez<<endl;
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
    void irasas::Rez(){
        rez=0.4*vid+0.6*egz;
    }
