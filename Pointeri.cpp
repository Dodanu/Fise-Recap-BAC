#include <iostream>
#include <string.h>

using namespace std;

/**
Memoria este o succesiune de octeti(bytes) numerotati. Numarul de ordine a byte-ului este adresa lui, si este in general reprezentata in baza 16(adica este un numar hexadecimal).
O variabila ocupa in memorie un anumit numar de bytes, iar adresa primului byte este adresa variabilei.

Un pointer este o data care retine o adresa de memorie. O variabila pointer este o variabila a carei valoaroi este adresa altor variabile.

Declarare:
tip* nume;

int* p; //o variabile pointer ce a carei valoare este adresa unei variabile int
&p - adresa pointerului (operator de referentiere)
*p - variabila memorata in adresa pointerului (operator de dereferentiere)
*/

/**
Să se realizeze un program ce permite citirea de la tastatură a două numere întregi şi calculează
suma, diferenţa şi media aritmetică a lor. Operațiile se vor realiza indirect, prin intermediul
unor variabile pointer. Să se afişeze pe ecran valorile, adresele de memorie și valorile indicate
de pointeri cât şi valorile şi adresele de memorie pentru rezultate.
*/
void Ex1()
{
    int a, b;
    cin>>a>>b;
    int *p, *q;
    p = &a;
    q = &b;
    int suma, diferenta;
    double media;
    suma = *p + *q;
    diferenta = *p - *q;
    media = (*p + *q)/2;
    cout<<suma<<" "<<diferenta<<" "<<media<<endl;
}

/**
Să se realizeze un program ce permite citirea de la tastatură a unui vector cu 10 elemente
numere întregi. Să se afişeze pe ecran adresele de memorie si valoarea ale elementelor vectorului şi apoi
să se determine suma elementelor acestuia. Operațiile se vor realiza prin intermediul
pointerilor.
*/
void Ex2()
{
    /**
    Cand declaram un vector(ex: int v[10]), variabila vector v va stoca intotdeauna adresa de memorie a primului element din vector. Deci un vector este un fel de pointer.
    */
    int v[10], n, suma=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>*(v+i);
    }
    for(int i=0; i<n; i++){
        cout<<v+i<<" "<<*(v+i)<<endl;
        suma += *(v+i);
    }
    cout<<suma;
}

/**
Să se realizeze un program ce permite citirea de la tastatură a două şiruri de caractere şi
afişează pe ecran şirul concatenat. Operaţiile se vor realiza folosind pointeri.
*/
void concatenare(char a[],char b[])
{
    a = a+strlen(a);
    while(b!=b+strlen(b)){  ///Normal ar trebui sa mearga cu b!=NULL, idk de ce nu merge in cazul asta. Siruriile de caractere is retardate pe codeblocks
        *a = *b;
        b++;
        a++;
    }
}

void Ex3()
{
    char a[255], b[255];
    cin.getline(a, 255);
    cin.getline(b, 255);
    concatenare(a, b);
    cout<<a<<endl;
}

int main()
{
    //Ex1();
    //Ex2();
    //Ex3();
    return 0;
}
