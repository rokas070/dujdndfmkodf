#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct eil{
    string var, pav;
    double egz, nds=0, rez, nd[100];
}eil[100];

int main () {
    int w=0, i=0, q=1;
    while( q==1)
    {
        char tn;
        cout << "Ar norite ivesti nauja mokini i sistema? (t/n): " << endl;
        cin >> tn;
        if (tn == 'n')
        {
            q=0;
        }
        else if (tn =='t')
        {
            w++;
            q=1;
            double e;
            cout << "Mokinio vardas: ";
            cin >> eil[i].var;

            cout << "Mokinio pavarde: ";
            cin >> eil[i].pav;
            cout<<"namu darbu skaicius: ";
            cin>>e;
            cout<<"namu darbu balai: ";
            for(int j=0; j<e; j++)
            {
               cin>>eil[i].nd[j];
               eil[i].nds=eil[i].nds+eil[i].nd[j];
            }
            eil[i].nds=eil[i].nds/e;
            cout<<"egzamino balas: ";
            cin>>eil[i].egz;
            eil[i].rez=0.4*eil[i].nds+0.6*eil[i].egz;
            i++;
        }
    }
    cout<<setfill(' ')<<setw(12)<<left<<"Vardas"<<setw(13)<<left<<"Pavarde"<<right<<"Galutinis (Vid.)"<<endl;
    cout<<setfill('-')<<setw(42)<<'-'<<endl;
    for (int n=0; n<w; n++)
    cout<<setfill(' ')<<setw(12)<<left<<eil[n].var<<setw(25)<<left<<eil[n].pav<<right<<eil[n].rez<<setprecision(3)<<endl;
  return 0;
}
