#include <iostream>
#include <vector>

using namespace std;

class Personaje{
private:
    string nombre;
    int id{0};
    int vida{0};
    int ataque{0};

public:
    Personaje(){}
    Personaje(const string &n, int i, int v, int a)
    {
        setNombre(n);
        setId(i);
        setVida(v);
        setAtaque(a);
    }

    void setNombre(const string &n)
    {
        nombre=n;
    }

    void setId(int i)
    {
        id=i;
    }

    void setVida(int v)
    {
        vida=v;
    }

    void setAtaque(int a)
    {
        ataque=a;
    }

    const string& getNombre(void) const
    {
        return nombre;
    }

    int getId(void) const
    {
        return id;
    }

    int getVida(void) const
    {
        return vida;
    }

    int getAtaque(void) const
    {
        return ataque;
    }

};

ostream& operator <<(ostream &os, const Personaje &p)
{
    os << "Nombre: " << p.getNombre() << endl;
    os << "Id: " << p.getId() << endl;
    os << "Vida:" << p.getVida() << endl;
    os << "Ataque: " << p.getAtaque() << endl << endl;
    return os;
}

const vector<Personaje>& operator +(vector<Personaje> &v, const Personaje &p)
{
    v.push_back(p);

    return v;
}

class Mago:public Personaje{
private:
    int nivel_Mago{0};

public:
    Mago(){}
    Mago(const string &n, int i, int v, int a, int nivel)
    {
        setNombre(n);
        setId(i);
        setVida(v);
        setAtaque(a);
        nivel_Mago=nivel;
    }

    int getNivelMago() const
    {
        return nivel_Mago;
    }

    int Atacar() const
    {
        cout << "Abracadabra" << endl;
        return this->getAtaque();
    }

};

ostream& operator <<(ostream &os, const Mago &p)
{
    os << "Nombre: " << p.getNombre() << endl;
    os << "Id: " << p.getId() << endl;
    os << "Vida:" << p.getVida() << endl;
    os << "Ataque: " << p.getAtaque() << endl;
    os << "Nivel Mago: " << p.getNivelMago() << endl << endl;
    return os;
}

const vector<Mago>& operator +(vector<Mago> &v, const Mago &m)
{
    v.push_back(m);

    return v;
}

class Barbaro:public Personaje{
private:
    int defensa{0};

public:
    Barbaro(){}
    Barbaro(const string &n, int id, int v, int atq, int d)
    {
        setNombre(n);
        setId(id);
        setVida(v);
        setAtaque(atq);
        defensa=d;
    }

    int getDefensa() const
    {
        return defensa;
    }

    int Atacar() const
    {
        cout << "Aaaaaa" << endl;
        return this->getAtaque();
    }

};

ostream& operator <<(ostream &os, const Barbaro &p)
{
    os << "Nombre: " << p.getNombre() << endl;
    os << "Id: " << p.getId() << endl;
    os << "Vida:" << p.getVida() << endl;
    os << "Ataque: " << p.getAtaque() << endl;
    os << "Defensa: " << p.getDefensa() << endl << endl;
    return os;
}

const vector<Barbaro>& operator +(vector<Barbaro> &v, const Barbaro &b)
{
    v.push_back(b);

    return v;
}

template<typename T>
class Batallon{
private:
    vector<T> miVector;

public:
    Batallon(const vector<T> &v)
    {
        miVector=v;
    }

    const vector<T>& getEquipo() const
    {
        return miVector;
    }

    friend ostream& operator <<(ostream &os, const Batallon<T> &v)
    {
        for(auto e: v.getEquipo())
        {
            os << e;
        }
            return os;
    }

    bool EncontrarPersonaje(const Batallon<T> &v, const string &cad, int i) const
    {
        for(auto e: v.getEquipo())
        {
            if(e.getNombre()==cad && e.getId()==i)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    bool res;
    vector<Personaje> VectorP;
    vector<Mago> VectorM;
    vector<Barbaro> VectorB;

    Personaje miPersonaje("Carlos",50,2600,800);
    Personaje miPersonaje2("Clara",100,5800,1230);

    Mago miMago("Hector",23,1500,150,13);
    Mago miMago2("Oscar",33,1700,170,34);

    Barbaro miBarbaro("Alejandro",56,1900,220,200);
    Barbaro miBarbaro2("Rex",26,2300,190,240);

    VectorP = VectorP + miPersonaje;
    VectorP = VectorP + miPersonaje2;

    Batallon<Personaje> bat(VectorP);
    cout << bat << endl;
    res = bat.EncontrarPersonaje(bat,"Clara",100);
    if(res==1)
        cout << "Personaje ya existente" << endl << endl;

    VectorM = VectorM + miMago;
    VectorM = VectorM + miMago2;

    Batallon<Mago> mag(VectorM);
    cout << mag << endl;

    VectorB = VectorB + miBarbaro;
    VectorB = VectorB + miBarbaro2;

    Batallon<Barbaro> bar(VectorB);
    cout << bar << endl;

    return 0;
}
