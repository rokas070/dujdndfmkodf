#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED


#include <algorithm>

using namespace std;

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


#endif // STRUKTURA_H_INCLUDED
