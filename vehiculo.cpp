#include <iostream>
#include <string>
using namespace std;

// CLASE BASE: VEHICULO
class Vehiculo {
protected:
    string numeroPlaca;
    string color;
    string marca;
    float velocimetro;

public: 
    Vehiculo(string n, string c, string m, float v);
    void mostrarDatos();
    void cambiarVelocidad(float nuevaVelocidad);
};

Vehiculo::Vehiculo(string n, string c, string m, float v) {
    numeroPlaca = n;
    color = c;
    marca = m;
    velocimetro = v;
}

void Vehiculo::mostrarDatos() {
    cout << "Placa: " << numeroPlaca << " | Color: " << color << " | Marca: " << marca << " | Velocidad: " << velocimetro << " km/h." << endl;
}

void Vehiculo::cambiarVelocidad(float nuevaVelocidad) {
    if (nuevaVelocidad >= 0) {
        velocimetro = nuevaVelocidad;
    }
}

// CLASE DERIVADA: AUTOMOVIL
class Automovil : public Vehiculo {
private: 
    int cantidadPuertas;
    int cantidadPasajeros;

public:
    Automovil(string n, string c, string m, float v, int p, int pas);
    void mostrarAutomovil();
    void subirPasajeros(int nuevosPasajeros);
    void bajarPasajeros(int pasajerosBajan);
};
Automovil::Automovil(string n, string c, string m, float v, int p, int pas) 
    : Vehiculo(n, c, m, v) {
    cantidadPuertas = p;
    cantidadPasajeros = pas;
}

void Automovil::subirPasajeros(int nuevosPasajeros) {
    if (nuevosPasajeros > 0) {
        cantidadPasajeros += nuevosPasajeros;
    }
}

void Automovil::bajarPasajeros(int pasajerosBajan) {
    if (pasajerosBajan > 0 && pasajerosBajan <= cantidadPasajeros) {
        cantidadPasajeros -= pasajerosBajan;
    }
}

void Automovil::mostrarAutomovil() {
    mostrarDatos();
    cout << "  -> Puertas: " << cantidadPuertas << " | Pasajeros: " << cantidadPasajeros << endl;
}

// CLASE DERIVADA: CAMION
class Camion : public Vehiculo {
private:
    float carga;

public:
    Camion(string n, string c, string m, float v, float car);
    void mostrarCamion();
    void cambiarCarga(float nuevaCarga);
};

Camion::Camion(string n, string c, string m, float v, float car)  : Vehiculo(n, c, m, v) {
    carga = car;
}

void Camion::mostrarCamion() {
    mostrarDatos();
    cout << "  -> Carga: " << carga << " kg" << endl;
}

void Camion::cambiarCarga(float nuevaCarga) {
    if (nuevaCarga >= 0) {
        carga = nuevaCarga;
    }
}

// PROGRAMA PRINCIPAL
int main() {
    cout << "--- AUTOMOVIL ---" << endl;
    Automovil j("SHA-203", "Negro", "Subaru", 60.0, 4, 6);
    cout << "Estado inicial:" << endl;
    j.mostrarAutomovil();

    cout << "\nModificando estado (suben 5 pasajeros y aumenta velocidad a 89 km/h)..." << endl;
    j.subirPasajeros(5);
    j.cambiarVelocidad(89.0);
    cout << "Estado actualizado:" << endl;
    j.mostrarAutomovil();

    cout << "\n--- CAMION ---" << endl;
    Camion k("S0N-124", "Azul", "Hino", 50.0, 1500.0);
    cout << "Estado inicial:" << endl;
    k.mostrarCamion();

    cout << "\nModificando estado (se ajusta la carga a 2500 kg y velocidad a 65 km/h)..." << endl;
    k.cambiarCarga(2500.0);
    k.cambiarVelocidad(65.0);
    cout << "Estado actualizado:" << endl;
    k.mostrarCamion();

    return 0;
}

