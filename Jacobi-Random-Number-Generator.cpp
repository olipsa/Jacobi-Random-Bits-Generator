#include<NTL/ZZ.h>
#include <NTL/vector.h>
using namespace std;
using namespace NTL;
int number0 = 0, number1 = 0;
void jacobiSymbol(int numberOfBits)
{
    ZZ n, t, r, a,copyOfn;
    Vec<ZZ> p;
    Vec<ZZ> listOfa;
    int countPrimeNumbers = 0;
    p.SetLength(numberOfBits);
    listOfa.SetLength(numberOfBits);
    n = 1;
    for (int i = 0; i < numberOfBits; i++)
    {
        RandomPrime(p[i],20, 10);
        n *= p[i];
        RandomLen(listOfa[i],1024);
    }

    //cout << "n has " << NumBits(n) << " bits.\n";
    //cout << "n=" << n << endl;
    copyOfn = n;   
    //compute Jacobi symbol for each pair (a_i,n)
    for (int i = 0; i < numberOfBits; i++)
    {

        a = listOfa[i] % p[i];
        n = copyOfn;
        t = 1;
        a = a % n;
        if (a == 0) a == 1;

        while (a != 0)
        {
            while (a % 2 == 0)
            {
                a /= 2;
                r = n % 8;
                if (r == 3 || r == 5)
                    t = -t;

            }
            swap(a, n);
            if (a % 4 == 3 && n % 4 == 3)
                t = -t;
            a = a % n;

        }
        if (n == 1)
        {
            if (t == -1)
            {
                cout << 1 << ' ';
                number1++;
            }
            else
            {
                cout << 0 << ' ';
                number0++;
            }


        }
        else
        {
            cout << 0 << ' ';
            number0++;
        }

    }
    
}

int main()
{
    int numberOfBits;
    cout << "Select number of random bits to be generated: ";
    cin >> numberOfBits;
    jacobiSymbol(numberOfBits);
    cout << "\n0 was generated " << number0 << " times and 1 was generated " << number1 << " times";
    
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
