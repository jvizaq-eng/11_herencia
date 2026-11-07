#include <iostream>
#include <string>
using namespace std;

// CLASE BASE: FIGURA
class Figura {
protected:
    string color;

public:
    Figura(string c);
};

Figura::Figura(string c) {
    color = c;
}

// CLASE DERIVADA: CIRCULO
class Circulo : public Figura {
private: 
    double radio;

public:
    Circulo(string c, double r);
    double calcularArea();
    double calcularPerimetro();
    void mostrarDatos();
};

Circulo::Circulo(string c, double r) : Figura(c) {
    radio = r;
}

double Circulo::calcularArea() {
    return 3.1416 * radio * radio;
}

double Circulo::calcularPerimetro() {
    return 2 * 3.1416 * radio;
}

void Circulo::mostrarDatos() {
    cout << "--- CIRCULO ---" << endl;
    cout << "Color: " << color << endl;
    cout << "Radio: " << radio << endl;
    cout << "Area: " << calcularArea() << endl;
    cout << "Perimetro: " << calcularPerimetro() << endl;
}

// CLASE DERIVADA: RECTANGULO
class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(string c, double b, double h);
    double calcularArea();
    void mostrarDatos();
};

Rectangulo::Rectangulo(string c, double b, double h) : Figura(c) {
    base = b;
    altura = h;
}

double Rectangulo::calcularArea() {
    return base * altura;
}

void Rectangulo::mostrarDatos() {
    cout << "--- RECTANGULO ---" << endl;
    cout << "Color: " << color << endl;
    cout << "Base: " << base << ", altura: " << altura << endl;
    cout << "Area: " << calcularArea() << endl;
}

// CLASE DERIVADA: TRIANGULO
class Triangulo : public Figura {
private:
    double base;
    double altura;
    string tipo;

public:
    Triangulo(string c, double b, double h, string t);
    double calcularArea();
    void mostrarDatos();
};

Triangulo::Triangulo(string c, double b, double h, string t) : Figura(c) {
    base = b;
    altura = h;
    tipo = t;
}

double Triangulo::calcularArea() {
    return (base * altura) / 2.0;
}

void Triangulo::mostrarDatos() {
    cout << "--- TRIANGULO ---" << endl;
    cout << "Color: " << color << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Base: " << base << ", altura: " << altura << endl;
    cout << "Area: " << calcularArea() << endl;
}

// PROGRAMA PRINCIPAL
int main() {
    Circulo cir("Rojo", 5.0);
    Rectangulo re("Verde", 4.0, 6.0);
    Triangulo tri("Azul", 3.0, 8.0, "Isósceles");

    cir.mostrarDatos();
    cout << endl;
    re.mostrarDatos();
    cout << endl;
    tri.mostrarDatos();

    return 0;
}
