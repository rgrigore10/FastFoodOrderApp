#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>

using namespace std;

//! CLASE

class FastFood {
public:
    const int ff_id;
    static int ff_id_curent;
    float pret;
    int cantitate;

    FastFood() : ff_id(ff_id_curent++) {
        pret = 0;
        cantitate = 1;
    }

    ~FastFood() {}


    FastFood& operator++ (int cantitate)
    {
        FastFood* aux = this;
        (*aux).cantitate++;
        cout << (*aux).cantitate;
        return *aux;
    }
    FastFood& operator-- (int cantitate)
    {
        FastFood* aux = this;
        (*aux).cantitate--;
        cout << (*aux).cantitate;
        return *aux;
    }

    //* GETTERI
    float getPret() {
        return this->pret;
    }

    int getID() {
        return ff_id;
    }

};
int FastFood::ff_id_curent = 0;


class Pizza :public FastFood {
    float dimensiune;
    int selector_topping, selector_crusta;
    const char* tip_crusta[3] = { "Pufos","Subtire","Normal" };
    const char* tip_topping[4] = { "Branza","Salam","Bacon","Mici" };

public:

    Pizza() {
        dimensiune = 0;
        selector_topping = 0;
        selector_crusta = 0;
    }
    Pizza(float dimensiune, int selector_topping, int selector_crusta)
    {
        this->dimensiune = dimensiune;
        this->selector_topping = selector_topping;
        this->selector_crusta = selector_crusta;
        pret = dimensiune * 1.2;
    }

    Pizza(const Pizza& copy) {

        this->dimensiune = copy.dimensiune;
        this->selector_topping = copy.selector_topping;
        this->selector_crusta = copy.selector_crusta;
        this->pret = copy.pret;
    }
    ~Pizza() {

    };

    //* SETTERI
    void setDimensiune(int dimensiune) {
        this->dimensiune = dimensiune;
    }

    void setTopping(int selector_topping) {
        this->selector_topping = selector_topping;
    }

    void setCrusta(int selector_crusta) {
        this->selector_crusta = selector_crusta;
    }

    //* GETTERI
    const char* getTipCrusta(int i) {
        return tip_crusta[i];
    }

    const char* getTipTopping(int i) {
        return tip_topping[i];
    }

    int getDimensiune() {
        return this->dimensiune;
    }

    int getSelectorTopping() {
        return this->selector_topping;
    }

    int getSelectorCrusta() {
        return this->selector_crusta;
    }

    //* OVERWRITE
    friend void operator<<(ofstream& fileoutput, Pizza& f) {
        fileoutput << "Pizza" << ' ' << f.getID() << ' ' << f.getDimensiune() << ' ' << f.getSelectorTopping() << ' ' << f.getSelectorCrusta() << ' ' << f.getPret() << endl;
    }

    //* ALTE FUNCTII
    void calculPret() {
        this->pret = dimensiune * 1.2;
    }



};



class Burger : public FastFood {
    int selector_size, selector_burger;
    const char* tip_burger[4] = { "Vita","Pui","Porc","Curcan" };
    const char* tip_size[3] = { "Mic","Mediu","Mare" };

public:

    Burger() {
        selector_size = 0;
        selector_burger = 0;
    };
    Burger(int selector_size, int selector_burger)
    {
        this->selector_size = selector_size;
        this->selector_burger = selector_burger;

        switch (selector_size)
        {
        case 0:
            pret = 20;
            break;

        case 1:
            pret = 25;
            break;

        case 2:
            pret = 28;
            break;

        default:
            pret = 0;
            break;
        }

    }

    Burger(const Burger& copy) {

        this->selector_burger = copy.selector_burger;
        this->selector_size = copy.selector_size;
        this->pret = copy.pret;
    }

    ~Burger() {

    };

    //* SETTERI
    void setSelectorSize(int selector_size) {
        this->selector_size = selector_size;
    }

    void setSelectorBurger(int selector_burger) {
        this->selector_burger = selector_burger;
    }

    //* GETTERI
    const char* getTipBurger(int i) {
        return tip_burger[i];
    }

    const char* getTipSize(int i) {
        return tip_size[i];
    };

    int getSelectorBurger() {
        return this->selector_burger;
    }

    int getSelectorSize() {
        return this->selector_size;
    }

    //* OVERWRITE
    friend void operator<<(ofstream& fileoutput, Burger& f) {
        fileoutput << "Burger" << ' ' << f.getID() << ' ' << f.getSelectorSize() << ' ' << f.getSelectorBurger() << ' ' << f.getPret() << endl;
    }

    //* ALTE FUNCTII
    void calculPret() {
        switch (selector_size)
        {
        case 0:
            this->pret = 20;
            break;

        case 1:
            this->pret = 25;
            break;

        case 2:
            this->pret = 28;
            break;

        default:
            this->pret = 0;
            break;
        }
    }
};



class Fries : public FastFood {
    int selector_cartofi;
    int selector_size;
    const char* tip_cartofi[2] = { "French", "Wedges" };
    const char* tip_size[3] = { "Mic","Mediu","Mare" };

public:
    Fries() {
        selector_cartofi = 0;
        selector_size = 0;
    };

    Fries(int selector_cartofi, int selector_size) {
        this->selector_cartofi = selector_cartofi;
        this->selector_size = selector_size;

        switch (selector_size)
        {
        case 0:
            pret = 5;
            break;

        case 1:
            pret = 10;
            break;

        case 2:
            pret = 12;
            break;

        default:
            pret = 0;
            break;
        }

    };

    Fries(const Fries& copy) {
        this->selector_cartofi = copy.selector_cartofi;
        this->selector_size = copy.selector_size;
        this->pret = copy.pret;
    };

    ~Fries() {

    };

    //* SETTERI
    void setSelectorSize(int selector_size) {
        this->selector_size = selector_size;
    }

    void setSelectorCartofi(int selector_cartofi) {
        this->selector_cartofi = selector_cartofi;
    }

    //* GETTERI
    const char* getTipCartofi(int i) {
        return tip_cartofi[i];
    }

    const char* getTipSize(int i) {
        return tip_size[i];
    }

    int getSelectorCartofi() {
        return this->selector_cartofi;
    }

    int getSelectorSize() {
        return this->selector_size;
    }

    //* OVERWRITE
    friend void operator<<(ofstream& fileoutput, Fries& f) {
        fileoutput << "Fries" << ' ' << f.getID() << ' ' << f.getSelectorSize() << ' ' << f.getSelectorCartofi() << ' ' << f.getPret() << endl;
    }

    //* ALTE FUNCTII
    void calculPret(int selector_size) {
        switch (selector_size)
        {
        case 0:
            this->pret = 5;
            break;

        case 1:
            this->pret = 10;
            break;

        case 2:
            this->pret = 12;
            break;

        default:
            this->pret = 0;
            break;
        }
    }
};



class Shaorma : public FastFood {
private:
    int selector_size, selector_carne, selector_sosuri;
    const char* tip_size[3] = { "Mica", "Medie", "Mare" };
    const char* tip_carne[3] = { "Vita", "Pui", "Amestec" };
    const char* tip_sosuri[4] = { " ", "Maioneza","Ketchup","Usturoi" };

public:
    Shaorma() {
        selector_size = 0;
        selector_carne = 0;
        selector_sosuri = 0;
    };

    Shaorma(int selector_size, int selector_carne, int selector_sosuri) {
        this->selector_size = selector_size;
        this->selector_carne = selector_carne;
        this->selector_sosuri = selector_sosuri;

        switch (selector_size)
        {
        case 0:
            pret = 15;
            break;

        case 1:
            pret = 17;
            break;

        case 2:
            pret = 22;
            break;

        default:
            pret = 0;
            break;
        }

    };

    Shaorma(const Shaorma& copy) {
        this->selector_size = copy.selector_size;
        this->selector_carne = copy.selector_carne;
        this->selector_sosuri = copy.selector_sosuri;
        this->pret = copy.pret;
    }

    ~Shaorma() {

    };

    //* SETTERI
    void setSelectorSize(int selector_size) {
        this->selector_size = selector_size;
    }

    void setSelectorCarne(int selector_carne) {
        this->selector_carne = selector_carne;
    }

    void setSelectorSosuri(int selector_sosuri) {
        this->selector_sosuri = selector_sosuri;
    }

    //* GETTERI
    const char* getTipCarne(int i) {
        return tip_carne[i];
    }

    const char* getTipSosuri(int i) {
        return tip_sosuri[i];
    }

    const char* getTipSize(int i) {
        return tip_size[i];
    }

    int getSelectorCarne() {
        return this->selector_carne;
    }

    int getSelectorSosuri() {
        return this->selector_sosuri;
    }

    int getSelectorSize() {
        return this->selector_size;
    }

    //* OVERWRITE
    friend void operator<<(ofstream& fileoutput, Shaorma& f) {
        fileoutput << "Shaorma" << ' ' << f.getID() << ' ' << f.getSelectorSize() << ' ' << f.getSelectorCarne() << ' ' << f.getSelectorSosuri() << ' ' << f.getPret() << endl;
    }

    //* ALTE FUNCTII
    void calculPret() {
        switch (selector_size)
        {
        case 0:
            pret = 15;
            break;

        case 1:
            pret = 17;
            break;

        case 2:
            pret = 22;
            break;

        default:
            pret = 0;
            break;
        }
    }
};



class ChickenNuggets :public FastFood
{
    int selector_size, selector_sosuri;
    const char* tip_size[2] = { "Portie de 6", "Portie de 12" };
    const char* tip_sosuri[4] = { "Maioneza","Ketchup","Usturoi","Dulce acrisor" };

public:
    ChickenNuggets() {
        selector_size = 0;
        selector_sosuri = 0;
    };

    ChickenNuggets(int selector_size, int selector_sosuri) {
        this->selector_size = selector_size;
        this->selector_sosuri = selector_sosuri;

        switch (selector_size)
        {
        case 0:
            pret = 10;
            break;

        case 1:
            pret = 18;
            break;

        default:
            pret = 0;
            break;
        }

    };

    ChickenNuggets(const ChickenNuggets& copy) {
        this->selector_size = copy.selector_size;
        this->selector_sosuri = copy.selector_sosuri;
        this->pret = copy.pret;
    }

    ~ChickenNuggets() {

    };

    //* SETTERI
    void setSelectorSize(int selector_size) {
        this->selector_size = selector_size;
    }

    void setSelectorSosuri(int selector_sosuri) {
        this->selector_sosuri = selector_sosuri;
    }

    //* GETTERI
    const char* getTipSize(int i) {
        return tip_size[i];
    }

    const char* getTipSosuri(int i) {
        return tip_sosuri[i];
    }

    int getSelectorSize() {
        return selector_size;
    }

    int getSelectorSosuri() {
        return selector_sosuri;
    }

    //* OVERWRITE
    friend void operator<<(ofstream& fileoutput, ChickenNuggets& f) {
        fileoutput << "ChickenNuggets" << ' ' << f.getID() << ' ' << f.getSelectorSize() << ' ' << f.getSelectorSosuri() << ' ' << f.getPret() << endl;
    }

    //* ALTE FUNCTII
    void calculPret() {
        switch (selector_size)
        {
        case 0:
            pret = 10;
            break;

        case 1:
            pret = 18;
            break;

        default:
            pret = 0;
            break;
        }
    }
};



class Suc : public FastFood {
    int selector_size, selector_suc;
    const char* tip_size[3] = { "Mic", "Mediu", "Mare" };
    const char* tip_suc[6] = { "Cola", "Pepsi", "Sprite", "Fanta", "7-Up", "Portocale" };

public:

    Suc() {
        selector_size = 0;
        selector_suc = 0;
    };

    Suc(int selector_size, int selector_suc) {
        this->selector_size = selector_size;
        this->selector_suc = selector_suc;

        switch (selector_size)
        {
        case 0:
            pret = 5;
            break;

        case 1:
            pret = 10;
            break;

        case 2:
            pret = 12;
            break;

        default:
            pret = 0;
            break;
        }

    };

    Suc(const Suc& copy) {
        this->selector_size = copy.selector_size;
        this->selector_suc = copy.selector_suc;
        this->pret = copy.pret;
    }

    ~Suc() {};

    //* SETTERI
    void setSelectorSize(int selector_size) {
        this->selector_size = selector_size;
    }

    void setSelectorSuc(int selector_suc) {
        this->selector_suc = selector_suc;
    }

    //* GETTERI
    const char* getTipSize(int i) {
        return tip_size[i];
    }

    const char* getTipSuc(int i) {
        return tip_suc[i];
    }

    int getSelectorSize() {
        return selector_size;
    }

    int getSelectorSuc() {
        return selector_suc;
    }

    //* OVERWIRTE
    friend void operator<<(ofstream& fileoutput, Suc& f) {
        fileoutput << "Suc" << ' ' << f.getID() << ' ' << f.getSelectorSize() << ' ' << f.getSelectorSuc() << ' ' << f.getPret() << endl;
    }

    //* ALTE FUNCTII
    void calculPret() {
        switch (selector_size)
        {
        case 0:
            pret = 5;
            break;

        case 1:
            pret = 10;
            break;

        case 2:
            pret = 12;
            break;

        default:
            pret = 0;
            break;
        }
    }
};



class Sandwich : public FastFood {
    int selector_size, selector_carne, selector_topping, selector_ingrediente;
    const char* tip_size[3] = { "Mic", "Mediu", "Mare" };
    const char* tip_carne[4] = { "Vita", "Pui", "Peste", "Curcan" };
    const char* tip_topping[5] = { " ", "Ketchup", "Maioneza", "Mustar", "Sos BBQ" };
    const char* tip_ingrediente[8] = { " ", "Rosii", "Salata", "Muraturi", "Cascaval", "Masline", "Ceapa", "Castraveti" };

public:

    Sandwich() {
        this->selector_size = 0;
        this->selector_carne = 0;
        this->selector_topping = 0;
        this->selector_ingrediente = 0;
    };
    Sandwich(int selector_size, int selector_carne, int selector_topping, int selector_ingrediente) {
        this->selector_size = selector_size;
        this->selector_carne = selector_carne;
        this->selector_topping = selector_topping;
        this->selector_ingrediente = selector_ingrediente;

        switch (selector_size)
        {
        case 0:
            pret = 10;
            break;

        case 1:
            pret = 12;
            break;

        case 2:
            pret = 14;
            break;

        default:
            pret = 0;
            break;
        }

    };

    Sandwich(const Sandwich& copy) {
        this->selector_size = copy.selector_size;
        this->selector_carne = copy.selector_carne;
        this->selector_topping = copy.selector_topping;
        this->selector_ingrediente = copy.selector_ingrediente;
        this->pret = copy.pret;
    };

    ~Sandwich() {};

    //* SETTERI
    void setSelectorSize(int selector_size) {
        this->selector_size = selector_size;
    }

    void setSelectorCarne(int selector_carne) {
        this->selector_carne = selector_carne;
    }

    void setSelectorTopping(int selector_topping) {
        this->selector_topping = selector_topping;
    }

    void setSelectorIngrediente(int selector_ingrediente) {
        this->selector_ingrediente = selector_ingrediente;
    }

    //* GETTERI
    const char* getTipSize(int i) {
        return tip_size[i];
    }

    const char* getTipCarne(int i) {
        return tip_carne[i];
    }

    const char* getTipTopping(int i) {
        return tip_topping[i];
    }

    const char* getTipIngrediente(int i) {
        return tip_ingrediente[i];
    }

    int getSelectorSize() {
        return selector_size;
    }

    int getSelectorCarne() {
        return selector_carne;
    }

    int getSelectorTopping() {
        return selector_topping;
    }

    int getSelectorIngrediente() {
        return selector_ingrediente;
    }

    //* OVERWRITE
    friend void operator<<(ofstream& fileoutput, Sandwich& f) {
        fileoutput << "Sandwich" << ' ' << f.getID() << ' ' << f.getSelectorSize() << ' ' << f.getSelectorCarne() << ' ' << f.getSelectorTopping() << ' ' << f.getSelectorIngrediente() << ' ' << f.getPret() << endl;
    }

    //* ALTE FUNCTII
    void calculPret() {
        switch (selector_size)
        {
        case 0:
            pret = 10;
            break;

        case 1:
            pret = 12;
            break;

        case 2:
            pret = 14;
            break;

        default:
            pret = 0;
            break;
        }
    }
};



class Comanda {
    const int com_id;
    static int com_id_curent;
    int data_zi, data_luna, data_an;
    bool stare;
    float total_comanda;

public:
    Comanda() : com_id(com_id_curent++) {
        data_zi = 1;
        data_luna = 1;
        data_an = 2000;
        stare = false;
        total_comanda = 0;
    };

    Comanda(int data_zi, int data_luna, int data_an) : com_id(com_id_curent++) {
        this->data_zi = data_zi;
        this->data_luna = data_luna;
        this->data_an = data_an;
        stare = false;
    };

    ~Comanda() {}


    //* SETTERI
    void setTotalComanda(float total_comanda) {
        this->total_comanda = total_comanda;
    }

    //* GETTERI
    int getID() {
        return com_id;
    }

    bool get_stare() {
        return stare;
    }

    float getTotalComanda() {
        return this->total_comanda;
    }

    int getDataZi() {
        return this->data_zi;
    }

    int  getDataLuna() {
        return this->data_luna;
    }

    int getDataAn() {
        return this->data_an;
    }

    //* OVERWRITE
    friend void operator<<(ofstream& fileoutput, Comanda& comanda) {
        fileoutput << comanda.getID() << ' ' << comanda.getDataZi() << ' ' << comanda.getDataLuna() << ' ' << comanda.getDataAn() << ' ' << comanda.get_stare() << ' ' << comanda.getTotalComanda() << endl;
    }

    //* ALTE FUNCTII
    void adaugareLaTotalComanda(float valoare) {
        this->total_comanda = valoare;
    }

    void finalizareComanda() {
        this->stare = true;
    }
};
int Comanda::com_id_curent = 0;


class Cos {
private:

    //! FUNCTII STOCARE

    void stocareComenzi(Comanda& comanda) {
        ofstream outputFile;

        outputFile.open("comenzi.txt", fstream::out | fstream::app);
        if (outputFile.is_open()) {
            cout << "Fisierul s-a deschis cu succes\n";
            outputFile << comanda;
            outputFile.close();
        }
        else {
            cout << "Fisierul nu s-a putut deschide\n";
        }
    }

    template<typename T>
    void stocareDetaliiComanda(T produs, int com_id) {
        ofstream outputFile;

        outputFile.open("detaliiComenzi.txt", fstream::out | fstream::app);
        if (outputFile.is_open()) {
            cout << "Fisierul s-a deschis cu succes\n";
            outputFile << com_id << ' ';
            outputFile << produs;
            outputFile.close();
        }
        else {
            cout << "Fisierul nu s-a putut deschide\n";
        }
    }

    float crearePizza(int com_id) {
        Pizza f;
        int dimensiune, selector_topping, selector_crusta;

        cout << "Introduceti dimensiunea dorita(cm): ";
        cin >> dimensiune;

        cout << "Selectati toppingul dorit:\n";
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << f.getTipTopping(i) << endl;
        }
        cin >> selector_topping;

        cout << "Selectati crusta dorita:\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << f.getTipCrusta(i) << endl;
        }
        cin >> selector_crusta;

        f.setDimensiune(dimensiune);
        f.setTopping(selector_topping - 1);
        f.setCrusta(selector_crusta - 1);
        f.calculPret();

        stocareDetaliiComanda<Pizza>(f, com_id);

        return f.getPret();
    }

    float creareBurger(int com_id) {
        Burger f;
        int selector_size, selector_burger;

        cout << "Selectati marimea dorita:\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << f.getTipSize(i) << endl;
        }
        cin >> selector_size;

        cout << "Selectati tipul de carne dorit:\n";
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << f.getTipBurger(i) << endl;
        }
        cin >> selector_burger;

        f.setSelectorSize(selector_size - 1);
        f.setSelectorBurger(selector_burger - 1);
        f.calculPret();

        stocareDetaliiComanda<Burger>(f, com_id);

        return f.getPret();
    }

    float creareFries(int com_id) {
        Fries f;
        int selector_size, selector_cartofi;

        cout << "Selectati marimea dorita:\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << f.getTipSize(i) << endl;
        }
        cin >> selector_size;

        cout << "Selectati tipul de cartofi dorit:\n";
        for (int i = 0; i < 2; i++) {
            cout << i + 1 << ". " << f.getTipCartofi(i) << endl;
        }
        cin >> selector_cartofi;

        f.setSelectorSize(selector_size - 1);
        f.setSelectorCartofi(selector_cartofi - 1);
        f.calculPret(f.getSelectorSize());

        stocareDetaliiComanda<Fries>(f, com_id);

        return f.getPret();
    }

    float creareShaorma(int com_id) {
        Shaorma f;
        int selector_size, selector_carne, selector_sosuri = 0, n_sosuri, c_sos;

        cout << "Selectati marimea dorita:\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << f.getTipSize(i) << endl;
        }
        cin >> selector_size;

        cout << "Selectati tipul de carne dorit:\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << f.getTipCarne(i) << endl;
        }
        cin >> selector_carne;

        cout << "Cate sosuri doriti? (max. 3): ";
        cin >> n_sosuri;
        cout << "Selectati sosul dorit:\n";
        for (int i = 1; i < 4; i++) {
            cout << i << ". " << f.getTipSosuri(i) << endl;
        }
        for (int i = 0; i < n_sosuri; i++) {
            cin >> c_sos;
            selector_sosuri = selector_sosuri * 10 + c_sos;
        }

        f.setSelectorSize(selector_size - 1);
        f.setSelectorCarne(selector_carne - 1);
        f.setSelectorSosuri(selector_sosuri);
        f.calculPret();

        stocareDetaliiComanda<Shaorma>(f, com_id);

        return f.getPret();
    }

    float creareChickenNuggets(int com_id) {
        ChickenNuggets f;
        int selector_size, selector_sosuri;

        cout << "Selectati marimea dorita:\n";
        for (int i = 0; i < 2; i++) {
            cout << i + 1 << ". " << f.getTipSize(i) << endl;
        }
        cin >> selector_size;

        cout << "Selectati sosul dorit:\n";
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << f.getTipSosuri(i) << endl;
        }
        cin >> selector_sosuri;

        f.setSelectorSize(selector_size - 1);
        f.setSelectorSosuri(selector_sosuri - 1);
        f.calculPret();

        stocareDetaliiComanda<ChickenNuggets>(f, com_id);

        return f.getPret();
    }

    float creareSuc(int com_id) {
        Suc f;
        int selector_size, selector_suc;

        cout << "Selectati marimea dorita:\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << f.getTipSize(i) << endl;
        }
        cin >> selector_size;

        cout << "Selectati tipul de suc dorit:\n";
        for (int i = 0; i < 6; i++) {
            cout << i + 1 << ". " << f.getTipSuc(i) << endl;
        }
        cin >> selector_suc;

        f.setSelectorSize(selector_size - 1);
        f.setSelectorSuc(selector_suc - 1);
        f.calculPret();

        stocareDetaliiComanda<Suc>(f, com_id);

        return f.getPret();
    }

    float creareSandwich(int com_id) {
        Sandwich f;
        int selector_size, selector_carne, selector_topping = 0, n_topping, c_topping, selector_ingrediente = 0, n_ingrediente, c_ingredient;

        cout << "Selectati marimea dorita:\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << f.getTipSize(i) << endl;
        }
        cin >> selector_size;

        cout << "Selectati tipul de carne dorit:\n";
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << f.getTipCarne(i) << endl;
        }
        cin >> selector_carne;

        cout << "Cate topping-uri doriti? (max. 4): ";
        cin >> n_topping;
        cout << "Selectati topping-ul(urile) dorit(e):\n";
        for (int i = 1; i < 5; i++) {
            cout << i << ". " << f.getTipTopping(i) << endl;
        }
        for (int i = 0; i < n_topping; i++) {
            cin >> c_topping;
            selector_topping = selector_topping * 10 + c_topping;
        }

        cout << "Cate ingrediente doriti? (max. 7): ";
        cin >> n_ingrediente;
        cout << "Selectati ingredientul(ele) dorit(e):\n";
        for (int i = 1; i < 8; i++) {
            cout << i << ". " << f.getTipIngrediente(i) << endl;
        }
        for (int i = 0; i < n_ingrediente; i++) {
            cin >> c_ingredient;
            selector_ingrediente = selector_ingrediente * 10 + c_ingredient;
        }

        f.setSelectorSize(selector_size - 1);
        f.setSelectorCarne(selector_carne - 1);
        f.setSelectorTopping(selector_topping);
        f.setSelectorIngrediente(selector_ingrediente);
        f.calculPret();

        stocareDetaliiComanda<Sandwich>(f, com_id);

        return f.getPret();
    }

public:

    Cos() {}

    ~Cos() {}

    //! CREATOR COMENZI

    void creareComanda() {
        int n_produse, tip_produs;
        int data_zi, data_luna, data_an;
        char optiune;

        cout << "Cate produse doriti sa comandati?: ";
        cin >> n_produse;

        cout << "Introduceti data (zi/luna/an):";
        cin >> data_zi >> data_luna >> data_an;

        Comanda c(data_zi, data_luna, data_an);

        for (int i = 0; i < n_produse; i++) {
            cout << "Ce tip de produs doriti sa comandati?\n";
            cout << "\t1. Pizza\n";
            cout << "\t2. Burger\n";
            cout << "\t3. Fries\n";
            cout << "\t4. Shaorma\n";
            cout << "\t5. Chicken Nuggets\n";
            cout << "\t6. Suc\n";
            cout << "\t7. Sandwich\n";
            cin >> tip_produs;
            switch (tip_produs) {
            case 1:
                c.adaugareLaTotalComanda(crearePizza(c.getID()));
                break;
            case 2:
                c.adaugareLaTotalComanda(creareBurger(c.getID()));
                break;
            case 3:
                c.adaugareLaTotalComanda(creareFries(c.getID()));
                break;
            case 4:
                c.adaugareLaTotalComanda(creareShaorma(c.getID()));
                break;
            case 5:
                c.adaugareLaTotalComanda(creareChickenNuggets(c.getID()));
                break;
            case 6:
                c.adaugareLaTotalComanda(creareSuc(c.getID()));
                break;
            case 7:
                c.adaugareLaTotalComanda(creareSandwich(c.getID()));
                break;
            }
        }

        do {
            cout << "Confirmati comanda?(Y/N):";
            cin >> optiune;
            if (optiune == 'N' || optiune == 'n') {
                cout << "Comanda a fost anulata";
            }
            else {
                if (optiune == 'Y' || optiune == 'y') {
                    c.finalizareComanda();
                    stocareComenzi(c);
                }
            }
        } while (optiune != 'Y' && optiune != 'y' && optiune != 'N' && optiune != 'n');
    }
};


class Raport {
private:
    int numar_comenzi;
    float total_comenzi;
public:
    Raport() {
        this->numar_comenzi = 0;
        this->total_comenzi = 0;
    }

    Raport(const Raport& copy) {
        this->numar_comenzi = copy.numar_comenzi;
        this->total_comenzi = copy.total_comenzi;
    }

    ~Raport() {}

    //* GETTERI
    int getNumarComenzi() {
        return this->numar_comenzi;
    }

    float getTotalComenzi() {
        return this->total_comenzi;
    }

    //* ALTE FUNCTII
    void raportZi(int data_zi, int data_luna, int data_an) {
        float total = 0, total_comanda;
        int com_id, zi, luna, an, stare;

        ifstream inputFile;

        inputFile.open("comenzi.txt", ios::in);
        if (inputFile.is_open()) {
            while (inputFile >> com_id >> zi >> luna >> an >> stare >> total_comanda) {
                if (stare == 1 && zi == data_zi && luna == data_luna && an == data_an) {
                    total += total_comanda;
                    this->numar_comenzi++;
                }
            }
        }
        else {
            cout << "Fisierul nu a putut fi deschis";
        }

        this->total_comenzi = total;
    }

    void raportLuna(int data_luna, int data_an) {
        float total = 0, total_comanda;
        int com_id, zi, luna, an, stare;

        ifstream inputFile;

        inputFile.open("comenzi.txt", ios::in);
        if (inputFile.is_open()) {
            while (inputFile >> com_id >> zi >> luna >> an >> stare >> total_comanda) {
                if (stare == 1 && luna == data_luna && an == data_an) {
                    total += total_comanda;
                    this->numar_comenzi++;
                }
            }
        }
        else {
            cout << "Fisierul nu a putut fi deschis";
        }

        this->total_comenzi = total;
    }

    void raportAn(int data_an) {
        float total = 0, total_comanda;
        int com_id, zi, luna, an, stare;

        ifstream inputFile;

        inputFile.open("comenzi.txt", ios::in);
        if (inputFile.is_open()) {
            while (inputFile >> com_id >> zi >> luna >> an >> stare >> total_comanda) {
                if (stare == 1 && an == data_an) {
                    total += total_comanda;
                    this->numar_comenzi++;
                }
            }
        }
        else {
            cout << "Fisierul nu a putut fi deschis";
        }

        this->total_comenzi = total;
    }
};



void wipeDocument(char* denumire) {
    ofstream outputfile;
    outputfile.open(denumire, ofstream::out | ofstream::trunc);
    if (outputfile.is_open()) {
        cout << "Datele au fost sterse cu succes.\n";
        outputfile.close();
    }
    else {
        cout << "Fisierul nu a putut fi deschis.\n";
    }
}



int main() {

    char nume[] = "detaliiComenzi.txt";
    char nume2[] = "comenzi.txt";
    wipeDocument(nume);
    wipeDocument(nume2);

    Cos cos1;

    cos1.creareComanda();
    

    Raport raport1, raport2, raport3;

    raport1.raportZi(1, 1, 2021);
    cout << "Totalul pe 1/1/2021 este: " << raport1.getTotalComenzi() << ", cu " << raport1.getNumarComenzi() << " comenzi\n";


    raport2.raportLuna(1, 2021);
    cout << "Totalul pe luna 1 anul 2021 este: " << raport2.getTotalComenzi() << ", cu " << raport2.getNumarComenzi() << " comenzi\n";

    raport3.raportAn(2021);
    cout << "Totalul pe anul 2021 este: " << raport3.getTotalComenzi() << ", cu " << raport3.getNumarComenzi() << " comenzi\n";


    return 0;
}

