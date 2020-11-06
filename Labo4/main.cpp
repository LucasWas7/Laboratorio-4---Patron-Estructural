#include <iostream>
using namespace std;

class Objetivo {
public:
    virtual ~Objetivo() = default;

    virtual string Solicitud() const {
        return "Objetivo: Comportamiento del objetivo predeterminado";
    }
};

class Adaptado {
public:
    string SolicitudEspecifica() const {
        return ".odatpadA ed laicepse otneimatropmoC";
    }
};

class Adaptador : public Objetivo {
private:
    Adaptado* adaptado_;
public:
    Adaptador(Adaptado* adaptado) : adaptado_(adaptado){}
    string Solicitud() const override {
        string to_reverse = this->adaptado_->SolicitudEspecifica();
        reverse(to_reverse.begin(), to_reverse.end());
        return "Adaptador: (TRADUCIDO) " + to_reverse;
    }
};

void CodigoCliente(const Objetivo* objetivo) {
    cout << objetivo->Solicitud();
}

int main() {
    cout << "Cliente: Puedo trabajar bien con los objetos de destino: "<<endl;
    Objetivo* objetivo = new Objetivo;
    CodigoCliente(objetivo);
    cout << endl;
    cout << endl;
    Adaptado* adaptado = new Adaptado;
    cout << "Cliente: La clase Adaptado tiene una interfaz extraña. Mira, no lo entiendo: "<<endl;
    cout << "Adaptado: " << adaptado->SolicitudEspecifica();
    cout << endl;
    cout << endl;
    cout << "Cliente: Pero puedo trabajar con el a traves del adaptador: " << endl;
    Adaptador* adaptador = new Adaptador(adaptado);
    CodigoCliente(adaptador);
    cout << endl;
    delete objetivo;
    delete adaptado;
    delete adaptador;
    return 0;
}