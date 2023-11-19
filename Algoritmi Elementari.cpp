#include <iostream>

using namespace std;

///Algoritmi de baza

/**
Exemplu:
a  b ecran
15 5 5
10 5
5  5

Explicatie:
Daca scazi din 2 numere, numarul mai mic din numarul mai mare, pana cand acele doua numere devin egale, rezultatul scaderiilor este egal cu CMMDC.
*/
void CMMDCScadere()     ///Euclid prin scadere
{
    int a,b;
    cin>>a>>b;
    while(a!=b){
        if(a>b)
            a = a-b;
        else
            b = b-a;
    }
    cout<<a<<endl;
}

/**
Exemplu 1:
a  b r ecran
15 5 0 5
5  0 0

Exemplu 2:
a  b r ecran
15 9 6 3
9  6 3
6  3 0
3  0

Explicatie:
Se bazeaza pe formula: d(deimpartitorul) = i(Impartitorul) * c(catul) + r(restul)
Cand restul este 0, inseamnca ca impartitorul divide deimpartitorul.
*/
void CMMDCImpartire()   ///Euclid prin impartire
{
    int a, b;
    cin>>a>>b;
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    cout<<a<<endl;
}

/**
Cum stiu care Metoda dintre astea doua e mai eficienta?(Explic putin mai in detaliu la CMMMC)
Complexitate Metoda Scaderi Repetate:
3 * O(1) + O(n) + O(1) => Complexitate = O(n)

Complexitate Metoda Impartiri repetate:
3 * O(1) + O(n) => Complexitate = O(n)

Teoretic, ambele metode is la fel de eficiente, cea cu Impartiri repetate e putin mai eficienta.
Alegeo pe aia care o reti mai usor, in cazul asta e foarte irelevant.
*/

/**
Exemplu 1:
a  b cmmdc ecran
15 5 75    15
10 5 75
5  5 15

Ememplu 2:
a b cmmdc ecran
6 7 42    42
6 1 42

Explicatie:
Daca doua numere au CMMDC-ul 1, inseamna ca CMMMC-ul lor este inmultirea lor.
Daca, CMMDC-ul lor e diferit de 1, inseamna ca CMMMC-ul lor este inmultirea lor impartita la CMMDC.
*/
void CMMMCMetoda1()     ///CMMMC folosind CMMDC
{
    int a, b;
    cin>>a>>b;
    int cmmdc = a*b;
    while(a!=b){
        if(a>b)
            a = a-b;
        else
            b = b-a;
    }
    cmmdc = cmmdc/a;
    cout<<cmmdc<<endl;
}

/**
Exemplu 1:
a  b n  m  ecran
15 5 15 5  15
     15 10
     15 15

Exemplu 2:
a b n  m  ecran
6 7 6  7  42
    12 7
    12 14
    18 14
    18 21
    24 21
    24 28
    30 28
    30 35
    36 35
    42 35
    42 42

Explicatie:
Un fel de Euclid prin scaderi, dar invers. Daca aduni numarul mai mic, cu el insusi, pana cand ambele numere is egale, la final, vei avea CMMMC.
*/
void CMMMCMetoda2()     ///CMMMC metoda originala
{
    int a, b;
    cin>>a>>b;
    int n=a, m=b;
    while(n!=m){
        if(n>m)
            m = m+b;
        else
            n = n+a;
    }
    cout<<n<<endl;
}

/**
Cum stiu care Metoda dintre astea doua e mai eficienta?
Folosind modul de notatie a complexitatii O(exista si alte moduri de notatie a complexitatii)
[Explicatie de la University of Wisconsin: https://pages.cs.wisc.edu/~vernon/cs367/notes/3.COMPLEXITY.html ](Pot explica si eu candva daca nu intelegeti de aici)
Complexitate Metoda 1:
5 * O(1) + O(n) + O(1) => Complexitate = O(n)

Complexitate Metoda 2:
4 * O(1) + O(n) + O(1) => Complexitate = O(n)

Teoretic vorbind, ambele metode au aceiasi complexitate, practic vorbind Metoda 2 ocupa cu 4 bytes mai mult in memorie decat Metoda 1,
in schimb ce Metoda 1 are o operatie iterativa in plus fata de Metoda 2.
In concluzie, in cazul asta nu ar conta asa mult ce metoda folosesti, alegeo pe aia ce o retii mai usor.
*/

/**
Exemplu 1:
n i ecran
7 2 1
7 3

Exemplu 2:
n i ecran
2   1

Exemplu 3:
n i ecran
8 2 0

Explicatie:
Prin regula, 0 si 1 nu sunt numere prime. Doi este prin regula prim, dar daca intra in for, lam valida drept un numar non prim. Un numar este prim daca se divide
numai la 1 si la el insusi. Deci, prin for verificam daca numarul de validat se divide si la alte numere. Daca da, nu este prim, daca nu, atunci este prim.
*/
int prim()     ///Algoritmul prin care aflam daca un numar este prim
{
    int n;
    cin>>n;
    if(n==0 || n==1)
        return 0;
    if(n==2)
        return 1;
    for(int i=2; i*i<=n; i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}


/**
Exemplu:
n  k ecran
12 2 2 3
6  2
3  2
3  3
1

Explicatie:
Primele numere de la 2 in sus(adica 2 si 3) sunt prime. Impartind prin 2, pana cand nu mai poti, scoti toti multiplii lui 2 din posibilitatea de impartire. Facand asta
cu toate numerele pe rand, vei imparti numai la numere prime. Deci practic, trecand prin asta imparti si afisezi numere prime.
*/
void DivPrim()
{
    int n, k=2;
    cin>>n;
    while(n>1){
        if(n%k==0){
            cout<<k<<" ";
            while(n%k==0)
                n = n/k;
        }
        k++;
    }
}

int main()
{
    ///CMMDCScadere();
    ///CMMDCImpartire();
    ///CMMMCMetoda1();
    ///CMMMCMetoda2();
    ///prim();
    ///DivPrim();
    return 0;
}
