#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>

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
using std::ifstream;
using std::getline;

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
    char h;
    cout<<"Ar norite ivesti duomenis is failo? (t/kt. kl.) ";
    cin>>h;
    string line;
    vector <irasas> duomenubaze;
    if(h=='t')
    {

    ifstream failas("kursiokai.txt");
    while(getline(failas, line))
       {

        std::stringstream ss;
        ss<<line;
        irasas temp; int temp_nd;temp.paz.clear();
        ss>>temp.var;
        ss>>temp.pav;
        for(int i=0; i<6; i++){ss>>temp_nd;
        temp.paz.push_back(temp_nd);

        }
        temp.egz=temp.paz.back();
        temp.paz.pop_back();
        temp.Vid(); temp.Med(); temp.Rez1();temp.Rez2();
        duomenubaze.push_back(temp);
//        cout<<temp.var<<" "<<temp.pav<<" "<<endl;
//        for(int p: temp.paz)
//            cout<<p<<" ";
//        cout<<endl;
    }}
        else
    {
    string line;
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
     }
     cout<<setfill(' ')<<setw(12)<<left<<"Vardas"<<setw(13)<<left<<"Pavarde"<<right<<"Galutinis (Vid.)    Galutinis (Med.)"<<endl;
     cout<<setfill('-')<<setw(62)<<'-'<<endl;
     for (irasas a: duomenubaze)
     {
        cout<<setfill(' ')<<setw(12)<<left<<a.var<<setw(13)<<left<<a.pav<<setw(20)<<left<<a.rez1<<setprecision(3)<<right<<a.rez2<<setprecision(3)<<endl;
     }
     system("pause");
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
