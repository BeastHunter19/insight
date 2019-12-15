#ifndef MATRICE2D_H
#define MATRICE2D_H

class Matrice2D
{
    private:
        int x, y;
        int **arr;
        bool error;                                     //flag di errore
    public:
        Matrice2D();                                    //costruttore
        Matrice2D(int x, int y);                        //costruttore
        Matrice2D(int x, int y, int def);               //costruttore
        ~Matrice2D();                                   //distruttore

        int getDimX();                                  //restituisce il numero di righe
        int getDimY();                                  //restituisce il numero di colonne

        bool fail();                                    //restituisce true se si è verificato un errore
        void clear();                                   //reimposta il flag di errore a false

        int getValue(int x, int y);                     //accesso in sola lettura all'elemento
        int& getElement(int x, int y);                  //accesso lettura/scrittura (reference)

        void stampa();                                  //stampa la matrice a schermo

        void riempiSequenza(int start);                 //riempi con sequenza a partire da start
        void riempiMultipli(int start);                 //riempi con multipli di start
        void riempiRandom(int min, int max);            //riempi con numeri casuali da min a max
        void riempiRandom(int min, int max, int seed);  //riempi casualmente con seed custom
        void riempiPotenze(int base);                   //riempi con potenze di base
        void riempiManuale();                           //riempi la matrice manualmente per righe
        void riempiUniforme(int n);                     //riempi con tutte n

        void riempiDiagonaleP();                        //riempi manualmente la diagonale principale
        void riempiDiagonaleS();                        //riempi manualmente la diagonale secondaria

        void triangolareInf();                          //trasforma in triangolare inferiore
        void triangolareSup();                          //trasforma in triangolare superiore
        void diagonale();                               //trasforma in diagonale
        void scalare(int k);                            //trasforma in scalare
        void unita();                                   //trasforma in matrice unità

        Matrice2D* somma(Matrice2D *m);                 //somma con matrice m
        Matrice2D& prodottoScalare(int l);              //prodotto per uno scalare
        Matrice2D* prodotto(Matrice2D *m);              //prodotto tra matrici con m

        Matrice2D& getComplemento(int x, int y);         //restituisce il complemento dell'elemento
        int determinante();                             //calcola il determinante della matrice

        bool isQuadrata();                              //verifica matrice quadrata
        bool isTriangolareInf();                        //verifica triangolare superiore
        bool isTriangolareSup();                        //verifica triangolare inferiore
        bool isSimmetricaP();                           //verifica simmetrica rispetto a diagonale principale
        bool isDiagonale();                             //verifica matrice diagonale
        bool isScalare();                               //verifica matrice scalare
        bool isUnita();                                 //verifica matrice unità
        bool isVuota();                                 //verifica matrice vuota
        bool isRiga();                                  //verifica vettore riga
        bool isColonna();                               //verifica vettore colonna



        //valori predefiniti costruttore
        static constexpr int DEFAULT_X = 10;
        static constexpr int DEFAULT_Y = 10;
        static constexpr int DEFAULT_VALUE = 0;
};

#endif
