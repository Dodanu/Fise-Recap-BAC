#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int cmmdc(int a,int b)
{
   while(a!=b){
        if(a>b)
            a = a-b;
        else
            b = b-a;
   }
   return a;
}

int cmmmc(int a,int b)
{
    int cmd = cmmdc(a, b);
    return (a*b)/cmd;
}

/**
Concept de functionare:
    (7/6)+(1/3)+(1/4)+(2/5) = 2.15
    =  215/100 | /5 = 43/20 - solutia finala

double - numar rational

a    b    suma                       numitor    numarator    cm    ecran
7    6    0+(7/6)[~1.167] = 1.167                                  43 10
1    3    1.167+(1/3)[~0.3] = 1.5
1    4    1.5+(1/4)[~0.25] = 1.75
2    5    1.75+(2/5)[~0.4] = 2.15
          2.15                       1
          21.5                       10
          215                        100
                                                215          5
*/
void varianta1()
{
    int n;
    int numitor = 1, numarator;
    double suma = 0;    ///declaram o variabila numar rational, care va constituia suma fractiilor
    fin>>n;
    for(int i=0; i<n; i++){
        double a, b;
        fin>>a>>b;      ///incepem prin a citi doua numere rationale, a fiind numaratorul si b fiind numitoral fractiilor citite(Ex: a = 7, b = 6)
        suma = suma + (a/b);    ///impartim a la b, si rezultatul acela il adunam la suma tuturor fractiilor
    }
    /**
    in acest while vrem sa scriem un numar fractional ca x/(10^y), spre exemblu:
    2.15 poate fii scris ca 215/100, deci vrem sa inmultim suma cu 10 pana cand acesta devine un numar rational, si sa memoram de cate ori am inmultit suma cu 10.
    2.15 il inmultim de 2 ori cu 10 => 2.15 = 215/100, deci suma dupa acest while va fi 215, iar variabila numitor va fi 100.

    Explicare a liniei: suma - int(suma) != 0
        prin linia asta verificam daca suma este un numar rational sau nu.
        Vom lua din nou drept exemplu 2.15:
        suma = 2.15
        int(suma) = 2 (int() reprezentand partea intreaga a unui numar)
        2.15 - 2 = 0.15 != 0, deci numarul nostru ramane rational
        dupa o trecere prin while suma va fi 21.5
        suma = 21.5
        int(suma) = 21
        21.5 - 21 = 0.5 != 0, deci tot este un numar rational
        dupa ultima trecere prin while suma va fii 215
        suma = 215
        int(sume) = 215 (215 ne avand o partea rationala nu se taie nimic)
        215 - 215 = 0, suma a devenit numar rational, deci nu se mai repeta while-ul
    */
    while(suma - int(suma) != 0){
        suma = suma * numitor;
        numitor = numitor * 10;
    }
    /**
    cum din cauza sintaxei si modului de functionare a limbajului C++ nu putem atribui unui int direct un double si el sa inteleaga ca ii alocam numai partea
    trebuie sa folosim din nou int() ca sa ii atribuim numai partea intreaga, care in memorie este memorata drept un int.
    practic vorbind un double este memorat drept doua inturi, primul reprezentand partea intreaga iar al doilea partea fractionala a unui numar rational.
    in linia de mai joc practic numai ii dam numaratorului suma
    */
    numarator = int(suma);
    int cm = cmmdc(numarator, numitor);     ///aici calculam cmmdc dintre numitor si numarator ca sa aducem fractia dintre suma/(10^y) la o forma ireductibila.
    numarator = numarator/cm;       ///impartim numaratorul(suma) si numitorul la cmmdc
    numitor = numitor/cm;
    fout<<numarator<<" "<<numitor<<endl;
}

/**
Concept de funtionare:
    7   1   1   2
    - + - + - + - (aducem la acelasi numitor, care este cmmmc-ul numitoriilor(cmmc(6, 3, 4, 5) = 30) impartit la numitor in sine):
    6   3   4   5
    =>
    60/6   7    60/3   1   60/4   1   60/5   2
    ---- * -  + ---- * - + ---- * - + ---- * - (aducem la acelasi numitor, care este cmmmc-ul numitoriilor(cmmc(6, 3, 4, 5) = 30). Deci inmultim fiecare impartit la numitor in sine)
    60/6   6    60/3   3   60/4   4   60/5   5
    =>
    70 + 20 + 15 + 24   129                                                                                            43
    ----------------- = --- (impartim la cmmdc-ul dintre 129, 60, acela fiind 3, pentru a face fractia ireductibila) = --  adica chiar raspunsul problemei
           60           60                                                                                             20


*/
void varianta2()
{
    int mat[2][11];    ///pentru a face ce am scris mai sus avem nevoie de o matrice cu 2 randuri, primul retine numaratorii fractiilor, iar al doilea numitorii
    int cmmc;          ///aici vom retine cmmc-ul tuturor numitoriilor
    int n;
    fin>>n;
    ///in for-ul de mai jos calculam numitorul comun al fractiilor citite, acela fiind cel mai mic multiplu comun al tuturor numitoriilor cititi
    for(int i=0; i<n; i++){
        fin>>mat[0][i]>>mat[1][i];
        /**
        cmmmc-ul a mai multor numere(spre exemplu 6, 3, 4, 5) se face astfel:
        cmmmc-ul dintre 6 si 3
        dupa cmmmc dintre cmmmc-ul anterior(cmmmc 6, 3) si 4, etc.

        mai jos se face prin aceiasi metoda cmmmc-ul tuturor numitoriilor cititi
        Exemplu:
        mat[1] = {6, 3, 4, 5}
        i mat[1][i] cmmc
        0 6         6
        1 3         6
        2 4         12
        3 5         60
        */
        if(i==0)
            cmmc = mat[1][i];
        if(i>0)
            cmmc = cmmmc(mat[1][i], cmmc);
    }
    int numarator = 0;  ///suma tuturor numaratoriilor cititi adusi la numitor comun
    for(int i=0; i<n; i++){
        numarator = numarator + (mat[0][i]*(cmmc/mat[1][i]));   ///spre exemplu ca sa aducem numaratorul 7, din 7/6, la numaratorul comun 60, inmultim 7 cu 60/6, adica 7*10 = 70
    }
    int cmdc = cmmdc(cmmc, numarator);      ///cel mai mic numitor comun dintre suma numaratorilor la numitor comun, si numitorul comun, necesar pentru a face fractia ireductibila
    fout<<(numarator/cmdc)<<" "<<(cmmc/cmdc);       ///afisam si numitorul si numaratorul impariti la cmmdc, pentru a avea fractia finala ireductibila, ergo rezultatul final
}

/**
varianta1, cea pe care am facuto in clasa e mai eficienta din punctul de vedere a utilizarii memoriei, si si al complexitatii.
Motive: nu folosesc vectori, in cel mai rau caz un numar mai mic de pasi.
Ambele metode is ok totusi
*/

int main()
{
    ///varianta1();
    ///varianta2();
    return 0;
}
