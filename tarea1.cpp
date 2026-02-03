#include <iostream>
#include <string>
#include <functional>

using namespace std;

class Celular {
private:
    string marca;
    string modelo;

public:
    int bateria;

    // Métodos tipo "arrow function" (lambdas como propiedades)
    function<void()> cargar;
    function<void(int)> usar;

    // Constructor
    Celular(string m, string mod, int bat) {
        marca = m;
        modelo = mod;
        bateria = bat;

        // Lambda para cargar el celular
        cargar = [this]() {
            bateria = 100;
            cout << "Celular cargado al 100% 🔋" << endl;
        };

        // Lambda para usar el celular
        usar = [this](int minutos) {
            bateria -= minutos;
            if (bateria < 0) bateria = 0;
            cout << "Usando el celular por " << minutos 
                 << " minutos. Batería actual: " 
                 << bateria << "%" << endl;
        };
    }

    // Método tradicional
    void llamar() {
        cout << "Llamando desde el " << marca << " " << modelo << endl;
    }

    // Método tradicional
    void mostrarInfo() {
        cout << "Marca: " << marca 
             << ", Modelo: " << modelo 
             << ", Batería: " << bateria << "%" << endl;
    }
};

int main() {
    // Crear dos instancias
    Celular celular1("Samsung", "S23", 80);
    Celular celular2("Apple", "iPhone 14", 60);

    // Probar métodos
    celular1.mostrarInfo();
    celular1.llamar();
    celular1.usar(30);
    celular1.cargar();

    cout << endl;

    celular2.mostrarInfo();
    celular2.usar(20);
    celular2.llamar();

    return 0;
}
