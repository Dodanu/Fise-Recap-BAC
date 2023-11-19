#include <iostream>
#include <string.h>

using namespace std;

///Documentatie librarie string.h: https://legacy.cplusplus.com/reference/cstring/

/**
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Pentru a intelege mare parte din asta, trebuie sa intelegem ce e ala un Pointer, deci am sa explica aici rapid.
Un pointer este o data, care retine o adresa din memoria ram. O vriabila de tip pointer, este o variabila ce retine adresa RAM a altei variabile;
Se declara:
tip* nume;
Ex1:
int* p;
&p = adresa de memorie
*p = valoarea din adresa de memorie

Un pointer poate fii vazuta ca o structura(nu explcati asa niciodata, dar e un mod de a concepe mai usor), avand ca variabile din structura:
* - valoarea adresei de memorie catre care este memorata la adresa de memorie catre care arata pointerul
& - adresa de memorie

Ex2:
int n;
n = 7
int *p;
&p = n //adresei de memorie a lui n este data pointerului p
*p = 10 //modificam valoarea de la acea adresa de memorie, deci in consecinta modificam si n(in acest caz din 7 in 10)
cout<<n; //10

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

void concatenare(char s[],char s2[])    ///Alipeste 2 vectori Ex: s = "ab", s2 = "cd" => s = "abcd"
{
    ///Cu librarie: strcat(s, s2);
    ///Facut de mana:
    /**
    de la finalul lui s, adaugam pe rand, de la inceput, caracterele din s1
    */
    ///Explicatie
    int j=strlen(s);
    for(int i=0; i<strlen(s2); i++){
        s[j] = s2[i];
        j++;
    }
    s[j] = '\0';    ///La inceputul for-ului inlocuim caracterul de final al vectorului s, pe care nu il adaugam inapoi la finalul forului, deci trebuie sa il adaugam noi manual dupa
}

void concatenareNr(char s[],char s2[],int n)    ///Alipeste 2 vectori, dar numai n caractere din al doilea vector Ex: s = "ab", s2 = "cdefg", n = 2 => s = "abcd"
{
    ///Cu librarie: strcat(s, s2, n);
    ///Facut de mana:
    /**
    la fel ca la concatenare, numai ca in loc sa mergem pana la strlen(s2), mergem numai pana la n
    */
    ///Explicatie
    int j=strlen(s);
    int lun;
    if(n>strlen(s2))
        lun = strlen(s2);
    else
        lun = n;
    for(int i=0; i<lun; i++){
        s[j] = s2[i];
        j++;
    }
    s[j] = '\0';
}

int comparare(char s[],char s2[])       ///Compara 2 siruri de caractere
{
    ///Cu librarie: strcmp(s, s2);
    ///Facut de mana:
    /**
    Se compara pe rand fiecare caracter din ambele caractere. Daca se returneaza 0 inseamna ca siruriile sunt egale, in caz contrar inseamna ca sunt diferite
    */
    ///Explicatie
    int i=0, j=0;
    while(i<strlen(s) || j<strlen(s2)){
        if(s[i]!=s2[j])
            return s[i]-s2[j];
        i++;
        j++;
    }
    return 0;
}

int comparareNr(char s[],char s2[],int n)   ///Compara un interval de la 0 la n dat, din 2 siruri de caractere
{
    ///Cu librarie: strncmp(s, s2, n);
    ///Explicatie
    /**
    La fel ca la comparare, dar se compara numai n caractere
    */
    ///Facut de mana:
    for(int i=0; i<n; i++)
        if(s[i]!=s2[i])
            return s[i]-s2[i];
    return 0;
}

char* caracter(char s[],char c)     ///Returneaza un pointer catre prima aparitie a caracterului c in s, sau NULL in caz ca nu exista
{
    ///Cu librarie: strchr(s, c);
    ///Explicatie
    /**
    Foloseste pointeri, deci idk cat de bine va functiona explicatia, dar o sa fac o fisa si cu pointeri candva.
    Functia returneaza pointerul catre prima aparitie a literei c in s. Deci verificam fiecare caracter pe rand si vedem daca este egal cu caracterul cautat.
    Daca da, returnam s, care este pointerul la caracterul cautat si la restul vectorului. Daca iesim din while, inseamna ca nu sa gasit caracterul, deci returnam NULL.
    Ex: s="lobotomie", c = 'b' => botomie
    */
    ///Facut de mana:
    while(s!=NULL){
        char ver = *s;
        if(ver==c)
            return s;
        s++;
    }
    return NULL;
}

int lungimePanaLaCaracter(char s[],char s1[])   ///Lungimea de caractere din s pana la primul caracter din s1 care apare in s
{
    ///Cu librarie: strcspn(s, s1);
    ///Facut de mana:
    ///Explicatie
    /**
    Verificam fiecare caracter din s, pe rand, daca apare in s1. Daca da, returnam al catelea caracter este(i).
    */
    for(int i=0; i<strlen(s); i++){
        if(strchr(s1, s[i]))
            return i;
    }
    return strlen(s1);
}

char* pointerCatrePrimulCaracter(char s[],char s1[])    ///Returneaza un pointer din s catre primul caracter din s1 care apare in s, sau NULL daca nu exista asa ceva
{
    ///Cu librarie: strpbrk(s, s1);
    ///Facut de mana:
    ///Explicatie
    /**
    Din nou, unul cu pointeri. Verificam fiecare caracter din s daca se afla in s1, Daca de, returnam pointerul care arata catre acel caracter din s.
    Ex: s="taco", s1 = "aeiou" => aco
        s="brr", s1="aeiou" => NULL
    */
    while(s!=NULL){
        char c = *s;
        if(strchr(s1, c))
            return s;
        s++;
    }
    return NULL;
}

char* ultimaAparitieAUnuiCaracter(char s[],char c)  ///Returneaza ultima aparitie a unui caracter in sir.
{
    ///Cu librarie: return strrchr(s, c);
    ///Facut de mana:
    ///Explicatie
    /**
    Din nou, pointeri. Intai retinem adresa de memorie de unde incepe s, si apoi lui s ii atribuim adresa de memorie finala. Mergem de la final pana la inceput prin sir, pe rand.
    Daca gasim caracterul, returnam acea adresa de memorie, daca nu returnam NULL.
    Ex: s = "quack", c = 'c' => "ck"
        s = "quack", c = 'q' => "quack"
        s = "quack", c = 'r' = > NULL
    */
    char *inceput = s;
    s = s + strlen(s);
    while(s!=inceput){
        if(*s==c)
            return s;
        s--;
    }
    return NULL;
}

int numarulDeCaractereCeAparLaInceput(char s[],char s1[])   ///Returneaza numarul de caractere initiale din s1, ce se afla in s
{
    ///Cu librarie: return strspn(s, s1);
    ///Facut de mana:
    ///Explicatie
    /**
    Aceasta functie verifica cate din caracterele din s, incepand cu primul, apar in s1. Deci daca primul caracter din s nu apare in s1, se va retruna 0.
    Verificam prin n, de la inceput si pe rand, fiecare caracter din s apartine lui s1, daca da adaugam la n 1(prin n memoram cate caractere indeplinesc onditia). Daca nu, returnam n.
    Returnam n si la final in caz ca ambele siruri sunt egale.
    */
    int n=0;
    for(int i=0; i<strlen(s); i++){
        if(strchr(s1, s[i]))
            n++;
        else
            return n;
    }
    return n;
}

char* impartireaSirului(char s[],char delimitatori[])
{
    return strtok(s, delimitatori);
    /**
    Functia asta contine foarte multi pointeri, deci nu are rost sa o scriu de mana.
    Pe scurt, ce face, este sa ia partea a primului sir, pana la unul dintre delimitatori. Unde se afla delimitatorul, este inlocuit cu un cartacter NULL. si returneaza un pointer
    catre acea parte. Cand se reapeleaza strtok, in loc de s se va pun NULL, caci functia memoreaza intern de unde sa reinceapa taierea sirului.
    Ex(numai o rulare):
    s = "Sex-League este liga mea preferata de fotbal american", delimitatori = " "
    strtok(s, delimitatori) va returna: Sex-League
    https://legacy.cplusplus.com/reference/cstring/strtok/ (link la documentatia functiei)
    */
}

int main()
{
    char s[255];
    cin.getline(s, 255);
    ///scrie aici functia ce vrei sa o testezi:
    return 0;
}
