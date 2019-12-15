#ifndef MATRICE3D_H
#define MATRICE3D_H

class Matrice3D
{
    private:
        int x, y, z;
        int ***arr;
    public:
        Matrice3D();                                         //costruttore
        Matrice3D(int x, int y, int z);                      //costruttore
        Matrice3D(int x, int y, int z, int def);             //costruttore
        ~Matrice3D();                                        //distruttore

        int getDimX();                                       //restituisce x
        int getDimY();                                       //restituisce y
        int getDimZ();                                       //restituisce z

        void stampa();                                       //stampa la matrice a schermo

        Matrice3D* sommaByPtr(Matrice3D *m);                 //somma due matrici passate come puntatori
        Matrice3D& sommaByReference(Matrice3D &m);           //somma due matrici passate come reference

        int& getElement(int x, int y, int z);                //restituisce reference all'elemento [x][y][z]
        int getValue(int x, int y, int z);                   //restituisce il valore dell'elemento [x][y][z]

        void riempiRandom(int min, int max);                 //riempie la matrice con valori casuali
        void riempiSequenza(int start);                      //riempie la matrice con numeri a partire da start
        void riempiMultipli(int num);                        //riempie la matrice con i multipli di num

        Matrice3D& prodottoScalare(int l);                   //prodotto della matrice per uno scalare


        //valori predefiniti costruttore
        static constexpr int DEFAULT_X = 10;
        static constexpr int DEFAULT_Y = 10;
        static constexpr int DEFAULT_Z = 10;
        static constexpr int DEFAULT_VALUE = 0;
};

#endif
