#include <curses.h>
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

int main(int argc, char const *argv[])
{
    vector<string> rutasPiezas = {
        "./assets/Pajaro.txt",
        //"./assets/tuberia1.txt",
        //"./assets/Tuberia2.txt",
        //"./assets/Tuberia3.txt",
        //"./assets/tuberia4.txt",
    };

    // Use initscr() to initialize curses mode
    initscr();

    // Initialize colors if you want to use color attributes
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    // Disable input echoing and enable keypad mode
    noecho();
    keypad(stdscr, TRUE);

    auto Pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

    while (true)
    {
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);

        list<Dibujo> dibujos;

        bool algunaPiezaCayendo = false;

        for (const auto &ruta : rutasPiezas)
        {
            Archivo pieza(ruta);
            Dibujo d = pieza.CrearDibujo();
            d.EstablecerPosicion(experimental::randint(0, 20), 0);
            dibujos.push_back(d);
        }

        while (true)
        {
            for (auto &d : dibujos)
            {
                if (!d.AlcanzaFondo(40))
                {
                    algunaPiezaCayendo = true;

                    // Use getch() to get a character from the keyboard
                    int tecla = getch();
                    if (tecla == 'w' || tecla == 'W')
                    {
                        d.salto();
                    }
                    else if (tecla == 's' || tecla == 'S')
                    {
                        d.MoverHaciaAbajo();
                    }
                    else if (tecla == 'a' || tecla == 'A')
                    {
                        d.MoverHaciaIzquierda();
                    }
                    else if (tecla == 'd' || tecla == 'D')
                    {
                        d.MoverHaciaDerecha();
                    }

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

    // End curses mode
    endwin();

    return 0;
}