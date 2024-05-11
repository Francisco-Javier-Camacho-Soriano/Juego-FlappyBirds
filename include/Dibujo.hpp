#pragma once
#include <string>
#include <list>
#include <ftxui/screen/screen.hpp>
using namespace std;
class Dibujo
{
private:
    int posicionX;
    int posicionY;
    list<string> contenido;
public:
    Dibujo() : posicionX(0), posicionY(0) {}
    Dibujo(int posX, int posY) : posicionX(posX), posicionY(posY) {}
    Dibujo(const list<string>& contenido, int posX, int posY)
        : posicionX(posX), posicionY(posY), contenido(contenido) {}

    void Dibujar(ftxui::Screen& Pantalla) {
        int posicionPalabraY = 0;
        for (const auto& linea : contenido) {
            int posicionPalabraX = 0;
            for (const auto& letra : linea) {
                int posicionFinalX = posicionX + posicionPalabraX;
                int posicionFinalY = posicionY + posicionPalabraY;
                Pantalla.PixelAt(posicionFinalX, posicionFinalY).character = letra;
                posicionPalabraX++;
            }
            posicionPalabraY++;
        }
    }

    void DesplazarX(int distancia) {
        posicionX += distancia;
    }

    void DesplazarY(int distancia) {
        posicionY += distancia;
    }

    void EstablecerPosicion(int x, int y) {
        posicionX = x;
        posicionY = y;
    }
    //Trabajo en proceso 
    bool Colisiona(const Dibujo& otro) const {
        for (int y = 0; y < contenido.size(); y++) {
            for (int x = 0; x < contenido.front().size(); x++) {
                int posX = posicionX + x;
                int posY = posicionY + y;
            if (posX >= otro.posicionX && posX < otro.posicionX + otro.contenido.front().size() &&
                posY >= otro.posicionY && posY < otro.posicionY + otro.contenido.size()) {
                return true; 
            }
        }
    }
    return false;
}
    //Trabajo en proceso
    bool AlcanzaFondo(int altoPantalla) const {
        int posicionFinalY = posicionY + contenido.size();
        return posicionFinalY >= altoPantalla;
    }

    void MoverHaciaDerecha() {
        posicionX++;
    }

    void MoverHaciaIzquierda() {
        posicionX--;
    }

    void MoverHaciaAbajo() {
        posicionY++;
    }

    void salto(){
        posicionY--;
    }


};