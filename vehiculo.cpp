#include<iostream>
#include<string>
using namespace std;

//CLASE BASE: VEHICULO
class Vehiculo{
	private:
		string numeroPlaca;
		string color;
		string marca;
		float velocimetro;
	public:
		Vehiculo();
		void mostrarDatos();
		// cambiarVelocidad();
};

Vehiculo :: Vehiculo(string, string, string, float){
	numeroPlaca = n;
	color = c;
	marca = m;
	velocimetro = v;
}

void Vehiculo :: mostrarDatos() {
	cout << numeroPlaca << "de color " << color << ", de la marca " << marca << "y su velocimetro es de " << velocimetro << " km/h." << endl;
}
	
//CLASE DERIVADA: AUTOMOVIL
class Automovil : public Vehiculo {
	private:
		int cantidadPuertas;
		int cantidadPasajeros;
	private:
		Automovil(string, string, string, float, int, int);
		void mostrarAutomovil();
		//subirPasajeros();
		//bajarPasajeros();
};

Automovil :: Automovil(string n, string c, string m, float v, int p, int x) : Vehiculo(n, c, m, v){
	cantidadPuertas = p;
	cantidadPasajeros = x;
}

void Automovil :: mostrarAutomovil(){
	mostrarDatos();
	cout << "\El automovil tiene " << cantidadPuertas << " puertas y " << cantidadPasajeros << " pasajeros." << endl;
}

//CLASE DERIVADA: CAMION
class Camion : public Vehiculo {
	private:
		float carga;
	public:
		Camion(string, string, string, float, int);
		void mostrarCamion();
		//cambiarCarga();
};

Camion :: Camion(string n, string c, string m, float v, int g) : Vehiculo(n, c, m, v){
	carga = g;
}

void Camion :: mostrarCamion() {
	mostrarDatos();
	cout << "\El camion tiene una carga de " << carga << " kg." << endl;
}

//PROGRAMA PRINCIPAL
int main(){
	//string ;
	
	Vehiculo j("sha-", "negro", "Toyota", "90");
	j.mostrarDatos();
	cout << endl;
	
	Automvil s("son-", "azul", "Subaru", "67", "4", "20");
	k.mostrarDatos();
	cout << endl;
	
	Camion t("tai-", "amarillo", "Suzuki", "76", "50");
	t.mostrarDatos();
	cout << endl;	
}
