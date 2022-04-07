#include <iostream>
#include <cstring>
using namespace std;

class film {
    char *den_film, *gen, *regizor;
    double rating;
public:
    film() {
        den_film = new char[31];
        gen = new char[20];
        regizor = new char[51];
    }

    ///DESTRUCTOR
    ~film() {
        delete[] den_film;
        delete[] gen;
        delete[] regizor;
    }

    ///constructor de copiere
    char *getDenFilm() const;

    char *getGen() const;

    char *getRegizor() const;

    double getRating() const;

    film(const film &alt_film) {
        den_film = new char[31];
        gen = new char[20];
        regizor = new char[51];


        strcpy(den_film, alt_film.den_film );
        strcpy(gen, alt_film.gen );
        strcpy(regizor, alt_film.regizor );


        rating=alt_film.rating ;
    }
    ///constructor parametrizat
    film(const char filmulet[], const char genu[], const char om[], const double rating1) {
        gen = new char[20];
        strcpy(gen, genu);

        den_film = new char[31];
        strcpy(den_film, filmulet);

        regizor = new char[51];
        strcpy(regizor, om);

        rating = rating1;
    }

    ///supraincarcare pe =
    film& operator=( const film &alt_film) {
        delete den_film;
        int lung = strlen(alt_film.den_film);
        den_film = new char[lung];
        strcpy(den_film, alt_film.den_film );

        delete gen;
        lung = strlen(alt_film.gen);
        gen = new char[lung];
        strcpy(gen,alt_film.gen );

        delete regizor;
        lung = strlen(alt_film.regizor);
        regizor = new char[lung];
        strcpy(regizor,alt_film.regizor );

        rating=alt_film.rating;
        return *this;
    }

    ///supraincarcare pe >> si <<
    friend istream &operator>>(istream &sin, film &movie);

    friend ostream &operator<<(ostream &siaut, film &movie);

    ///supraincarcare pe operatorii specifici de comparare
    bool operator == (const film &alt_movie) const{
        if (rating == alt_movie.rating) return true;
        else return false;
    }
    bool operator >= (const film &alt_movie) const{
        if (rating >= alt_movie.rating) return true;
        else return false;
    }
    bool operator <= (const film &alt_movie)const {
        if (rating <= alt_movie.rating) return true;
        else return false;
    }
    bool operator < (const film &alt_movie)const{
        if (rating < alt_movie.rating) return true;
        else return false;
    }
    bool operator > (const  film &alt_movie)const{
        if (rating > alt_movie.rating) return true;
        else return false;
    }

    ///modificare info
    void setden_film (char *denu)
    {
        delete[] den_film;
        int lungime = strlen(denu);
        den_film = new char[lungime];
        strcpy(den_film, denu);
    }
    void setgen(char *genu)
    {
        delete[] gen;
        int lungime = strlen(genu);
        gen = new char[lungime];
        strcpy(gen, genu);
    }
    void setregizor (char *reg)
    {
        delete[] regizor;
        int lungime = strlen(reg);
        regizor = new char[lungime];
        strcpy(regizor, reg);
    }
    void setrating (double rat)
    {
        rating=rat;
    }

};
istream &operator>>(istream &sin, film &movie){
    sin.getline (movie.den_film, 31);
    sin.getline (movie.gen, 20);
    sin.getline (movie.regizor,51);
    sin>>movie.rating; sin.get();
    return sin;
}
ostream &operator<<(ostream &siaut, film &movie){
    siaut<<movie.den_film; siaut<<endl;
    siaut<<movie.gen; siaut<<endl;
    siaut<<movie.regizor; siaut<<endl;
    siaut<<movie.rating;
    return siaut;
}

char *film::getDenFilm() const {
    return den_film;
}

char *film::getGen() const {
    return gen;
}

char *film::getRegizor() const {
    return regizor;
}

double film::getRating() const {
    return rating;
}

film *mov[100];
int main() {
    ///Sa se citeasca de la tastatura un vector declarat dinamic de filme, sa se poata compara doua
    ///filme, dupa rating, sa se poata modifica informatiile unui film din meniu si sa se afiseze toate filmele.
    //citire filme de la tastatura

    int n;
    cin>>n; ///nr total de filme
    cin.get();
    cout<<endl;
    for (int i = 1; i <= n; i++){
        cout<<i<<endl;
        mov[i] = new film;
        cin>>*mov[i];
        cout<<endl;
    }

    //citire comenzi
    char com[10];

    while (strcmp(com,"stop")!=0){
        cout<<"Comanda:";cout<<endl;
        cin.getline(com,10);
        //comanda de modificare
        if (strcmp(com,"change")==0){
            int nr_film;
            cout<<"Introdu nr film:";
            cin>>nr_film;
            cin.get();
            cout<<endl;
            cout<<"Introdu ce doresti sa modifici:";
            char modificare[10];
            cin.getline(modificare,10);
            cout<<endl;

            if (strcmp(modificare,"nume")==0){ //modificarea numelui
                cout<<"Numele nou:";
                char nume[50];
                cin.getline(nume,50);
                cout<<endl;
                mov[nr_film]->setden_film(nume);
            }
            else if (strcmp(modificare,"gen")==0){ //modificarea genului
                cout<<"Genul nou:";
                char gen[30];
                cin.getline(gen,30);
                cout<<endl;
                mov[nr_film]->setgen(gen);
            }
            else if (strcmp(modificare,"regizor")==0){ //modificarea regizorului
                cout<<"Regizor nou:";
                char regizor[50];
                cin.getline(regizor,50);
                cout<<endl;
                mov[nr_film]->setregizor(regizor);
            }
            else if (strcmp(modificare,"rating")==0){ //modificarea rating-ului
                cout<<"Rating-ul nou:";
                double rating;
                cin>>rating;
                cin.get();
                cout<<endl;
                mov[nr_film]->setrating(rating);
            }
        }
            //comanda de stergere
        else if (strcmp(com,"delete")==0){
            cout<<"Filmul ce urmeaza a fi sters: ";
            int nr_film;
            cin>>nr_film;
            cin.get();
            cout<<endl;
            for (int i = nr_film; i < n; i++)
                mov[i] = mov[i+1];
            n--;
        }
            //comanda de comparare
        else if (strcmp(com,"compara")==0){
            cout<<"Alege filmele pe care sa le compari: ";
            int primul, al_doilea;
            cin>>primul>>al_doilea;
            cin.get();
            cout<<endl;
            if (*mov[primul] > *mov[al_doilea])
                cout<<primul<<" pe imdb are nota mai buna ;) "<<endl;
            else if (*mov[primul] < *mov[al_doilea])
                cout<<al_doilea<<" pe imdb are nota mai buna ;) "<<endl;
            else cout<<"Filmele sunt la fel de bune... sau proaste...(depinde)";
        }
            //comanda de afisare
        else if (strcmp(com,"afisare")==0)
            for (int i = 1; i <= n; i++) cout<<*mov[i]<<endl;

    }
     const film test("numelee", "genull", "omul", 6.5);
     const film f2 = test;


    return 0;
}

