#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

/**
Mod de functionare:
n       sum          ecran
1971    0+1 = 1      9
197     1+7 = 8
19      8+9 = 17
1       17+1 = 18
0
18      0+8 = 8
1       8+1 = 9
0
9

Adunam cifrele din n, si repetam si adunarea rezultatului, pana cand numarul rezultand este numai o cifra(adica mai mic ca 10)
*/
int main()
{
    int n;
    fin>>n;
    while(n>10){
        int sum = 0;
        while(n){
            sum = sum+n%10;
            n = n/10;
        }
        n = sum;
    }
    fout<<n;
    return 0;
}
