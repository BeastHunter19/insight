#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Matrice3D.h"

using namespace std;

//costruttore
Matrice3D::Matrice3D()
{
    //allocazione dinamica matrice 3d
    this->arr = new int ** [this->DEFAULT_X];
    for (int i=0; i<this->DEFAULT_X; i++){
        this->arr[i] = new int * [this->DEFAULT_Y];
        for (int j=0; j<this->DEFAULT_Y; j++){
            this->arr[i][j] = new int [this->DEFAULT_Z];
        }
    }

    //riempimento con valore di default
    for (int i=0; i<this->DEFAULT_X; i++)
        for (int j=0; j<this->DEFAULT_Y; j++)
            for (int k=0; k<this->DEFAULT_Z; k++)
                this->arr[i][j][k] = this->DEFAULT_VALUE;

    //aggiornamento stato dell'oggetto
    this->x = this->DEFAULT_X;
    this->y = this->DEFAULT_Y;
    this->z = this->DEFAULT_Z;

    cout << "Matrice3D creata" <<endl;
}

//costruttore
Matrice3D::Matrice3D(int x, int y, int z)
{
    //allocazione dinamica matrice 3d
    this->arr = new int ** [x];
    for (int i=0; i<x; i++){
        this->arr[i] = new int * [y];
        for (int j=0; j<y; j++){
            this->arr[i][j] = new int [z];
        }
    }

    //riempimento con valore di default
    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            for (int k=0; k<this->z; k++)
                this->arr[i][j][k] = this->DEFAULT_VALUE;


    //aggiornamento stato dell'oggetto
    this->x = x;
    this->y = y;
    this->z = z;

    cout << "Matrice3D creata" <<endl;
}

//costruttore
Matrice3D::Matrice3D(int x, int y, int z, int def)
{
    //allocazione dinamica matrice 3d
    this->arr = new int ** [x];
    for (int i=0; i<x; i++){
        this->arr[i] = new int * [y];
        for (int j=0; j<y; j++){
            this->arr[i][j] = new int [z];
        }
    }

    //riempimento con valore di default
    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++)
            for (int k=0; k<z; k++)
                this->arr[i][j][k] = def;

    //aggiornamento stato dell'oggetto
    this->x = x;
    this->y = y;
    this->z = z;

    cout << "Matrice3D creata" <<endl;
}

//distruttore
Matrice3D::~Matrice3D()
{
    //deallozaione matrice 3d
    for (int i=0; i<this->x; i++){
        for (int j=0; j<this->y; j++){
            delete [] this->arr[i][j];
        }
        delete [] this-> arr[i];
    }
    delete this->arr;

    cout << "Matrice3D distrutta" <<endl;
}

//interroga l'oggetto sulle sue dimensioni
int Matrice3D::getDimX()Matrice3D &m2
{
    return this->x;
}

int Matrice3D::getDimY()
{
    return this->y;
}

int Matrice3D::getDimZ()
{
    return this->z;
}

//stampa la matrice fissando z
void Matrice3D::stampa()
{
    for (int k=0; k<this->z; k++){
        cout << "z = " << k <<endl <<endl;
        for (int i=0; i<this->x; i++){
            for (int j=0; j<this->y; j++){
                cout << this->getValue(i,j,k) << "  ";
            }
            cout <<endl <<endl;
        }
        cout <<endl <<endl;
    }
}

//metodi per somma di matrici
Matrice3D* Matrice3D::sommaByPtr(Matrice3D *m)
{
    if (this->x==m->getDimX() && this->y==m->getDimY() && \
        this->z==m->getDimZ()) {
        Matrice3D * sum = new Matrice3D(this->x, this->y, this->z, 0);

        for (int i=0; i<this->x; i++)
            for (int j=0; j<this->y; j++)
                for (int k=0; k<this->z; k++)
                    sum->getElement(i,j,k) = this->getValue(i,j,k) + \
                        m->getValue(i,j,k);

        return sum;
    }
    else
        return nullptr;
}

Matrice3D& Matrice3D::sommaByReference(Matrice3D &m)
{
    if (this->x==m.getDimX() && this->y==m.getDimY() && \
        this->z==m.getDimZ()) {
        Matrice3D &sum = *(new Matrice3D(this->x, this->y, this->z, 0));

        for (int i=0; i<this->x; i++)
            for (int j=0; j<this->y; j++)
                for (int k=0; k<this->z; k++)
                    sum.getElement(i,j,k) = this->getValue(i,j,k) + \
                        m.getValue(i,j,k);

        return sum;
    }
    else {
        cerr << "Matrici di dimensioni diverse!" <<endl;
        Matrice3D &void_sum = *(new Matrice3D(1,1,1,0));
        return void_sum;
    }
}

//accesso a elementi singoli (lettura/scrittura)
int& Matrice3D::getElement(int x, int y, int z)
{
    return this->arr[x][y][z];
}

//valore elementi singoli (sola lettura)
int Matrice3D::getValue(int x, int y, int z)
{
    return this->arr[x][y][z];
}

//riempimento della matrice
void Matrice3D::riempiRandom(int min, int max)
{
    srand(time(NULL));

    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            for (int k=0; k<this->z; k++)
                this->getElement(i,j,k) = rand()%(max-min+1)+min;
}

void Matrice3D::riempiSequenza(int start)
{
    for (int k=0; k<this->z; k++)
        for (int i=0; i<this->x; i++)
            for (int j=0; j<this->y; j++)
                this->getElement(i,j,k) = start++;
}

void Matrice3D::riempiMultipli(int num)
{
    int n=0;
    for (int k=0; k<this->z; k++)
        for (int i=0; i<this->x; i++)
            for (int j=0; j<this->y; j++)
                this->getElement(i,j,k) = (n++)*num;
}

Matrice3D& Matrice3D::prodottoScalare(int l)
{
    Matrice3D& lm = *(new Matrice3D(this->x, this->y, this->z));

    for (int i=0; i<this->x; i++)
        for (int j=0; j<this->y; j++)
            for (int k=0; k<this->z; k++)
                lm.getElement(i,j,k) = this->getValue(i,j,k)*l;

    return lm;
}
