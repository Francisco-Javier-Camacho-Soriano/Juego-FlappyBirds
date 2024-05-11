#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <ftxui/screen/screen.hpp>
#include <thread>
#include <experimental/random>
#include "Dibujo.hpp" // Incluimos la definición de la clase Dibujo

using namespace ftxui;
using namespace std;

int main(int argc, char const* argv[]) {
    vector<string> rutasElementos = {
        "./assets/images/Pajaro.txt",
        "./assets/images/Tuberia1.txt",
        "./assets/images/Tuberia2.txt",
        "./assets/images/Tuberia3.txt",
        "./assets/images/Tuberia4.txt"
    };

    auto Pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

    while (true) {
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);

        list<Dibujo> dibujos;

        for (const auto& ruta : rutasElementos) {
            ifstream archivo(ruta);
            if (archivo) {
                list<string> contenido;
                string linea;
                while (getline(archivo, linea)) {
                    contenido.push_back(linea);
                }
                archivo.close();
                Dibujo d(contenido, experimental::randint(0, 20), 0);
                dibujos.push_back(d);
            }
        }

        while (true) {
            bool algunElementoCayendo = false;

            for (auto& d : dibujos) {
                if (!d.AlcanzaFondo(40)) {
                    algunElementoCayendo = true;
                    d.MoverHaciaAbajo();
                    d.Dibujar(Pantalla);
                }
            }

            Pantalla.Print();
            cout << Pantalla.ResetPosition();
            this_thread::sleep_for(0.1s);
            Pantalla.Clear();

            if (!algunElementoCayendo)
                break;
        }
    }

    return 0;
}
