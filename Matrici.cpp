#include <iostream>

using namespace std;

/**
Aici nu prea am ce sa prezint drept concept nou, deci doar am sa fac o problema cu generari de matrici
*/

void citire(int v[][255],int &n,int &m)
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>v[i][j];
}

void afisare(int v[][255],int n,int m)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}

/**
Considerăm o matrice pătratică cu N linii și N coloane. În această matrice sunt definite 4 zone:

zona 1, formată din elementele situate strict deasupra diagonalei principale și strict deasupra diagonalei secundare;
zona 2, formată din elementele situate strict deasupra diagonalei principale și strict sub diagonala secundară;
zona 3, formată din elementele situate strict sub diagonala principală și strict sub diagonala secundară;
zona 4, formată din elementele situate strict sub diagonala principală și strict deasupra diagonalei secundare;

Generati o matrice patratica de n linii si coloane astfel incat elementele de pe diagonala principala si cea secundara sa fie 0
Cele de pe Zona 1 sa fie egale cu 1, cele de pe Zona 2 cu 2, cele de pe Zona 3 cu 3 si cele de pe Zona 4 cu 4

Practic aici nu prea am ce sa explic, doar respect o conditie data de problema. Ca un mod de rezolvare la problemele de generare, in caz ca nu va vine idea, puteti sa scrieti matricea
pe hartie si sa va ganditi cum e i in functie de j, ca exemplu la cazul asta.
*/

void generare(int v[][255],int n)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j || i+j==n-1)
                v[i][j] = 0;
            else{
                if(j>i && j<(n-i))
                    v[i][j] = 1;
                if(j<i && j<(n-i))
                    v[i][j] = 2;
                if(j>i && j>=(n-i))
                    v[i][j] = 3;
                if(j<i && j>=(n-i))
                    v[i][j] = 4;
            }
        }
    }
}

void Ex()
{
    int v[255][255], n;
    cin>>n;
    generare(v, n);
    afisare(v, n, n);
}

int main()
{
    Ex();
    return 0;
}
