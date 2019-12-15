#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

#include "Matrice2D.h"

using namespace std;

//costruttori

Matrice2D::Matrice2D()
{
    //error flag
    this->error = false;

    //dimensioni default
    this->x = this->DEFAULT_X;
    this->y = this->DEFAULT_Y;

    //allocazione dinamica Matrice2D
    this->arr = new int * [this->x];
    for (int i=0; i<this->x; i++)
        this->arr[i] = new int [this->y];

    //riempimento con valore di default
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            this->arr[i][j] = this->DEFAULT_VALUE;
}

Matrice2D::Matrice2D(int x, int y)
{
    //error flag
    this->error = false;

    //dimensioni custom
    this->x = x;
    this->y = y;

    //allocazione dinamica Matrice2D
    this->arr = new int * [this->x];
    for (int i=0; i<this->x; i++)
        this->arr[i] = new int [this->y];

    //riempimento con valore di default
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            this->arr[i][j] = this->DEFAULT_VALUE;
}

Matrice2D::Matrice2D(int x, int y, int def)
{
    //error flag
    this->error = false;

    //dimensioni custom
    this->x = x;
    this->y = y;

    //allocazione dinamica Matrice2D
    this->arr = new int * [this->x];
    for (int i=0; i<this->x; i++)
        this->arr[i] = new int [this->y];

    //riempimento con valore custom
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            this->arr[i][j] = def;
}

//distruttore
Matrice2D::~Matrice2D()
{
    //deallocazione Matrice2D
    for (int i=0; i<this->x; i++)
        delete [] this->arr[i];
    delete [] this->arr;
}

//dimensioni
int Matrice2D::getDimX()
{
    return this->x;
}

int Matrice2D::getDimY()
{
    return this->y;
}

//controlla la presenza di errori
bool Matrice2D::fail()
{
    return this->error;
}

//ripulisce il flag di errore
void Matrice2D::clear()
{
    this->error = false;
}

//accesso al valore di un elemento (sola lettura)
int Matrice2D::getValue(int x, int y)
{
    return this->arr[x][y];
}

//accesso a un elemento come reference (lettura/scrittura)
int& Matrice2D::getElement(int x, int y)
{
    return this->arr[x][y];
}

//stampa la matrice a schermo
void Matrice2D::stampa()
{
    cout <<endl;
    for (int i=0; i<this->x; i++){
        for (int j=0; j<this->y; j++){
            cout << this->getValue(i,j) << "  ";
        }
        cout <<endl <<endl;
    }
    cout <<endl;
}

//riempi con sequenza crescente di numeri a partire da start
void Matrice2D::riempiSequenza(int start)
{
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            this->getElement(i,j) = start++;
}

//riempi con multipli di start
void Matrice2D::riempiMultipli(int start)
{
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            this->getElement(i,j) = start*(i*this->y+j);
}

//riempi casualmente usando time(NULL) come seed
void Matrice2D::riempiRandom(int min, int max)
{
    srand(time(NULL));
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            this->getElement(i,j) = rand()%(max-min+1)+min;
}

//riempi casualmente usando un seed personalizzato
void Matrice2D::riempiRandom(int min, int max, int seed)
{
    srand(seed);
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            this->getElement(i,j) = rand()%(max-min+1)+min;
}

//riempi con potenze di base
void Matrice2D::riempiPotenze(int base)
{
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            this->getElement(i,j) = pow(base, i*this->y+j);
}

//riempi manualmente per righe
void Matrice2D::riempiManuale()
{
    int n;
    cout << "Inserisci un elemento per volta, ";
    cout << "la matrice sarà riempita per righe: " <<endl;
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++){
            do {
                cout << "Elemento di indici x=" << i << ", y=" << j << ": ";
                cin >> n;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while(cin.fail());
            cin.clear();
            this->getElement(i,j) = n;
        }
}

//riempi con tutte n
void Matrice2D::riempiUniforme(int n)
{
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            this->getElement(i,j) = n;
}

//riempi manualmente la diagonale principale
void Matrice2D::riempiDiagonaleP()
{
    if (!(this->isQuadrata())){
        this->error = true;
        return;
    }

    int n;
    cout << "Inserisci un elemento per volta: " <<endl;
    for (int i=0; i<this->x; i++){
        do {
            cout << "Elemento di indici x=" << i << ", y=" << i << ": ";
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while(cin.fail());
        cin.clear();
        this->getElement(i,i) = n;
    }
}

//riempi manualmente la diagonale secondaria
void Matrice2D::riempiDiagonaleS()
{
    if (!(this->isQuadrata())){
        this->error = true;
        return;
    }

    int n, i=0, j=this->y-1;
    cout << "Inserisci un elemento per volta: " <<endl;
    while ((i)<this->x && (j)>=0){
        do {
            cout << "Elemento di indici x=" << i << ", y=" << j << ": ";
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while(cin.fail());
        cin.clear();
        this->getElement(i,j) = n;
        i++;
        j--;
    }
}

//azzera tutti gli elementi sotto la diagonale principale
void Matrice2D::triangolareInf()
{
    if (!(this->isQuadrata())){
        this->error = true;
        return;
    }

    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            if (i>j)
                this->getElement(i,j) = 0;
}

//azzera tutti gli elementi sopra la diagonale principale
void Matrice2D::triangolareSup()
{
    if (!(this->isQuadrata())){
        this->error = true;
        return;
    }

    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            if (i<j)
                this->getElement(i,j) = 0;
}

//azzera tutti gli elementi al di fuori della diagonale principale
void Matrice2D::diagonale()
{
    this->triangolareInf();
    this->triangolareSup();
}

//rende la matrice diagonale e riempie la diagonale principale con k
void Matrice2D::scalare(int k)
{
    if (!(this->isQuadrata())){
        this->error = true;
        return;
    }

    this->diagonale();
    for (int i=0; i<this->x; i++)
        this->getElement(i,i) = k;
}

//trasforma la matrice in matrice unità
void Matrice2D::unita()
{
    this->scalare(1);
}

//somma tra matrici della stessa dimensione
Matrice2D* Matrice2D::somma(Matrice2D *m)
{
    if (this->getDimX()==m->getDimX() && this->getDimY()==m->getDimY()){
        Matrice2D *somma = new Matrice2D(this->getDimX(), this->getDimY());

        for (int i=0; i<this->getDimX(); i++)
            for (int j=0; j<this->getDimY(); j++)
                somma->getElement(i,j) = this->getValue(i,j) + \
                                         m->getValue(i,j);

        return somma;
    }
    else
        return nullptr;
}

//prodotto con uno scalare l
Matrice2D& Matrice2D::prodottoScalare(int l)
{
    Matrice2D &lm = *(new Matrice2D(this->getDimX(), this->getDimY()));

    for (int i=0; i<this->getDimX(); i++)
        for (int j=0; j<this->getDimY(); j++)
            lm.getElement(i,j) = this->getValue(i,j)*l;

    return lm;
}

//prodotto tra matrici del tipo NxM MxL
Matrice2D* Matrice2D::prodotto(Matrice2D *m)
{
    if (this->getDimY()==m->getDimX()){
        Matrice2D *prodotto = new Matrice2D(this->getDimX(), m->getDimY());

        for (int i=0; i<prodotto->getDimX(); i++)
            for (int j=0; j<prodotto->getDimY(); j++)
                for (int M=0; M<this->getDimY(); M++)
                    prodotto->getElement(i,j) += this->getValue(i,M)*m->getValue(M,j);

        return prodotto;
    }
    else
        return nullptr;
}

//restituisce il complemento algebrico minore dell'elemento
Matrice2D& Matrice2D::getComplemento(int x, int y)
{
    Matrice2D &complemento = *(new Matrice2D(this->x-1, this->y-1));

    int i=0, j=0, n=0, m=0;
    while (i<complemento.getDimX()){
        if (i==x)
            n++;
        while (j<complemento.getDimY()){
            if (j==y)
                m++;
            complemento.getElement(i,j) = this->getValue(n,m);
            j++;
            m++;
        }
        i++;
        n++;
        j=0;
        m=0;
    }

    return complemento;
}

//calcola il determinante
int Matrice2D::determinante()
{
    int determinante=0;
    if (this->x==this->y && this->x==1)
        return this->getValue(0,0);

    for (int i=0; i<this->y; i++){
        determinante += this->getValue(0,i)*(pow(-1,i)*(this->getComplemento(0,i)).determinante());
    }
    return determinante;
}

//verifica matrice quadrata
bool Matrice2D::isQuadrata()
{
    if (this->x == this->y)
        return true;
    else
        return false;
}

//verifica triangolare inferiore
bool Matrice2D::isTriangolareInf()
{
    if (!(this->isQuadrata()))
        return false;

    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            if (i>j && this->getValue(i,j)!=0)
                return false;

    return true;
}

//verifica triangolare superiore
bool Matrice2D::isTriangolareSup()
{
    if (!(this->isQuadrata()))
        return false;

    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            if (i<j && this->getValue(i,j)!=0)
                return false;

    return true;
}

//verifica simmetrica rispetto alla diagonale principale
bool Matrice2D::isSimmetricaP()
{
    if (!(this->isQuadrata()))
        return false;

    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            if (this->getValue(i,j) != this->getValue(j,i));
                return false;

    return true;
}

//verifica matrice diagonale
bool Matrice2D::isDiagonale()
{
    return (this->isTriangolareSup() && this->isTriangolareInf());
}

//verifica matrice scalare
bool Matrice2D::isScalare()
{
    if (!(this->isDiagonale()))
        return false;

    for (int i=0; i<this->x-1; i++)
        if (this->getValue(i,i)!=this->getValue(i+1,i+1))
            return false;

    return true;
}

//verifica matrice unità
bool Matrice2D::isUnita()
{
    if (!(this->isDiagonale()))
        return false;

    for (int i=0; i<this->x; i++)
        if (this->getValue(i,i)!=1)
            return false;

    return true;
}

//verifica matrice vuota
bool Matrice2D::isVuota()
{
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            if (this->getValue(i,j)!=0)
                return false;

    return true;
}

//verifica vettore riga
bool Matrice2D::isRiga()
{
    if (this->x==1)
        return true;
    else
        return false;
}

//verifica vettore colonna
bool Matrice2D::isColonna()
{
    if (this->y==1)
        return true;
    else
        return false;
}
