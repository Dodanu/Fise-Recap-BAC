#include <iostream>

using namespace std;

void citire()
{
    int n, v[255];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>v[i];
}

void afisare()
{
    int n = 5, v[255] = {1, 2, 3, 4, 5};
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
}

void inserarePePozitie()
{
    int n = 5, v[255] = {1, 2, 3, 4, 5};
    int deInserat = 6, pozInserat = 4;

    n++;

    for(int i=n; i>=pozInserat; i--){
        v[i] = v[i-1];
    }

    v[pozInserat] = deInserat;

    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
}

void eliminarePePozitie()
{
    int n = 5, v[255] = {1, 2, 3, 4, 5};
    int pozEliminat = 3;

    for(int i=pozEliminat; i<n; i++)
        v[i] = v[i+1];

    n--;

    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
}

void bubbleSort()
{
    int n = 5, v[255] = {3, 2, 5, 4, 1};
    bool sortat = false;
    while(!sortat){
        sortat = true;
        for(int i=0; i<n-1; i++){
            if(v[i]>v[i+1]){        ///foloseste < pt sortare descrescatoare
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                sortat = false;
            }
        }
    }
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
}

void cautareBinara()        ///Merge numai pe un vector sortat
{
    int n = 5, v[255] = {3, 2, 5, 4, 1};
    int st = 0, dr = n-1, mij;
    int deCautat = 1;
    bool sortat = false, gasit = 0;
    while(!sortat){
        sortat = true;
        for(int i=0; i<n-1; i++){
            if(v[i]>v[i+1]){        ///foloseste < pt sortare descrescatoare
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                sortat = false;
            }
        }
    }
    while(st<=dr){
        mij = (st+dr)/2;
        if(v[mij] == deCautat){
            gasit = 1;
            break;
        }
        if(v[mij]>deCautat)
            st = mij+1;
        else
            dr = mij-1;
    }
    cout<<gasit;
}

int main()
{
    cautareBinara();
    return 0;
}
