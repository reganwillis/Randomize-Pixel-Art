#ifndef CREATEFLOWER_H
#define CREATEFLOWER_H

#include <iostream>
#include <vector>
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
This class randomly choses 1 of 4 weighted images and pairs it with a color scheme
randomly chosen from 4 weighted color schemes to create a new image.

The most common color scheme (basic) should match the color schemes
of the 4 input images. If a color scheme other than basic is chosen, the class will map
the colors in the image from basic to the chosen color scheme.
*/
class CreateFlower {
    private:
        // color palettes
        struct Palette {
            sf::Color outline;
            sf::Color stem;
            sf::Color stem_detail;
            sf::Color center;
            sf::Color center_detail;
            sf::Color petals;
            sf::Color petals_detail;
            sf::Color eye;
            sf::Color pupil;
        } basic, dark, rare, ultrarare;

        // flower image
        sf::Image flower;

        // functions
        sf::Image getImage();
        void initColorPalettes();
        Palette getColorPalette();
        sf::Image changePixelColorsToPalette(sf::Image img, Palette palette);

    public:
        // constructors and deconstructors
        CreateFlower();
        virtual ~CreateFlower();

        // getters
        sf::Image getFlower();
};

#endif