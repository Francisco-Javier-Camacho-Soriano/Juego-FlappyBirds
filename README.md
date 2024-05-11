# FlappyBirds
## Objetivo
El objetivo del juego Flappy Bird es sencillo, tenemos que conseguir llegar lo más lejos posible esquivando los obstáculos que van apareciendo en el camino de nuestro personaje volador.
## Exploracion

### Carpetas 
- bin/ - Contiene los ejecutables del proyecto 
- src/ - Contiene el codigo fuente 
- include/ - Los archivos de cabecera 
- assets/ - Contiene los recursos del proyecto 
- docs/ - Contiene la documentacion del archivo 
# Descripcion
-Los jugadores controlan un pájaro haciendo click, lo que hace que el pájaro dé pequeños saltos.
-El objetivo es volar el pájaro a través de una serie de tuberías sin chocar contra ellas.
-Los jugadores ganan puntos por cada tubería que pasan con éxito.
-El juego termina una vez que el pajaro hace contacto con alguna tuberia o borde del mapa.
# Funcionamiento
Archivo.hpp: La clase Archivo abre un archivo de texto, lee su contenido línea por línea y lo almacena en una lista. Luego, proporciona un método para crear un objeto de tipo Dibujo utilizando el contenido almacenado en esa lista.
Dibujo.hpp: La clase Dibujo define objetos gráficos con coordenadas y contenido de texto. Proporciona métodos para dibujarlos en una pantalla, desplazarlos, verificar colisiones con otros dibujos y controlar su movimiento vertical.
main.cpp: Este código es un programa que utiliza la biblioteca ftxui para dibujar objetos en una pantalla y permite interactuar con ellos mediante el teclado. Utiliza la clase Archivo para cargar dibujos desde archivos de texto y los muestra en la pantalla, permitiendo al usuario moverlos hacia arriba, abajo, izquierda o derecha. El programa continúa ejecutándose en un bucle principal, generando constantemente nuevas piezas y permitiendo al jugador interactuar con ellas.
# Instrucciones
-Descargar todo el repertorio para que el juego funcione de manera correcta.
-Correrlo con make run.
-Si el juego presenta error, usar el codigo que viene en NOTAS, en el main.
-Despues de correrlo, puedes controlar al pajaro con las letras W,S,D,A.
