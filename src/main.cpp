#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <ftxui/screen/screen.hpp>
#include <thread>
#include <experimental/random>
#include "Archivo.hpp"

using namespace ftxui;
using namespace std;

int main(int argc, char const* argv[]) {
    vector<string> rutasPiezas = {
        "./assets/Pajaro.txt",
        "./assets/tuberia1.txt",
        "./assets/Tuberia2.txt",
        "./assets/Tuberia3.txt",
        "./assets/tuberia4.txt",

        
    };

    auto Pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

    while (true) {
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);

        list<Dibujo> dibujos;

        for (const auto& ruta : rutasPiezas) {
            Archivo pieza(ruta);
            Dibujo d = pieza.CrearDibujo();
            d.EstablecerPosicion(experimental::randint(0, 20), 0); 
            dibujos.push_back(d);
        }

        while (true) {
            bool algunaPiezaCayendo = false;

            for (auto& d : dibujos) {
                if (!d.AlcanzaFondo(40)) {
                    algunaPiezaCayendo = true;
                    d.MoverHaciaAbajo();
                    d.Dibujar(Pantalla);
                }
            }

            Pantalla.Print();
            cout << Pantalla.ResetPosition();
            this_thread::sleep_for(0.1s);
            Pantalla.Clear();

            if (!algunaPiezaCayendo)
                break;
        }
    }

    return 0;
}