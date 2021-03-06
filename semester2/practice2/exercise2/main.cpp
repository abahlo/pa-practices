/* 
 * File:   main.cpp
 *
 * Created on 9. April 2013, 17:51
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>

#include "Frame.h"

void line(Frame &fr, int x1, int y1, int x2, int y2) {

    if (fr.on_frame(x1, y1) && fr.on_frame(x2, y2)) {
        bool checkY(false); // Merker für "steigend/fallend"
        bool checkXY(false); // Merker für "steil/fach"

        if (x1 > x2) { // Überprüfen der Voraussetzungen und setzen der "Merker"
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        if (y2 < y1) {
            y2 *= -1;
            y1 *= -1;
            checkY = true;
        }
        if ((x2 - x1)<(y2 - y1)) {
            std::swap(x1, y1);
            std::swap(x2, y2);
            checkXY = true;
        }

        int dX = x2 - x1; // Berrechnung der für den Algorithmus notwendigen Werte
        int dY = y2 - y1;
        int dXY = 2 * dY - dX;

        for (int i = 0; i <= dX; ++i) {

            if (checkY) {
                if (checkXY) fr.put_point(y1, -x1); //fallend steil
                if (!checkXY) fr.put_point(x1, -y1); //fallend flach
            }
            if (!checkY) {
                if (checkXY) fr.put_point(y1, x1); //steigend steil
                if (!checkXY) fr.put_point(x1, y1); //steigend flach
            }

            if (dXY < 0) {
                x1++; // gehe nach rechts
                dXY += 2 * dY;
            } else {
                x1++; // gehe nach rechts-oben
                y1++;
                dXY += 2 * (dY - dX);
            }
        }
    } else std::cout << "Ermitteln der Punkte nicht möglich, da Punkte nicht auf Frame\n";
}


int main(int argc, char** argv) {

    try {

        int x1 = 5;
        int y1 = 11;
        int x2 = 1;
        int y2 = 1;

        Frame frame1;
        //frame1.reset();
        frame1.put_point(x1, y1);
        frame1.put_point(x2, y2);
        //frame1.show();
        line(frame1, x1, y1, x2, y2);
        

        clock_t start = clock_t(-1);
        clock_t end = clock_t(-1);
        start = clock();
        std::cout << &frame1;
        end = clock();
        
        std::cout <<"Laufzeit "<< double (end-start)/CLOCKS_PER_SEC <<"s \n";


        return 0;
        
    } catch (std::exception &e) {
        std::cerr << e.what();
        return -2;
    } catch (...) {
        std::cerr << "Unbekannter Fehler";
        return -1;
    }
}

