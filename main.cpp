#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include "SortObject.h"
using namespace std;

const unsigned WINDOW_WIDTH = 1000;
const unsigned WINDOW_HEIGHT = 1000;
const int SORTABLE_COUNT = 100;
bool isPaused = false;

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Visualizer");

void fillSortable(SortObject sortables[]);
void drawSortable(SortObject sortables[]);

void swap(SortObject &bar1, SortObject &bar2);

void insertionSort(SortObject sortables[]);

int main() {
    SortObject sortables[SORTABLE_COUNT];
    fillSortable(sortables);


    while(window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed) {window.close();}
        }

        if(!isPaused)
            insertionSort(sortables);
    }


    return 0;
}


void fillSortable(SortObject sortables[]) {
    default_random_engine generator(time(NULL));
    uniform_int_distribution<int> distribution(SORTABLE_COUNT, WINDOW_HEIGHT - 20);
    int temp;

    for(int i = 0; i < SORTABLE_COUNT; ++i) {
        temp = distribution(generator);
        sortables[i].setShapeSize((float)WINDOW_WIDTH / SORTABLE_COUNT, (float)temp);
        sortables[i].setValue(temp);
    }

}

void drawSortable(SortObject sortables[]) {
    window.clear(sf::Color::Black);
    for(int i = 0; i < SORTABLE_COUNT; ++i) {
        sortables[i].setShapePosition((float) i * sortables[i].getShape().getSize().x, WINDOW_HEIGHT - sortables[i].getShape().getSize().y);
        window.draw(sortables[i].getShape());
    }

    window.display();
}

void insertionSort(SortObject sortables[]) {
    SortObject key;
    int i, j;

    sortables[0].setColor(sf::Color::Green);
    drawSortable(sortables);

    for(i = 1; i < SORTABLE_COUNT; ++i) {
        //set the key to be inserted to the color Red
        sortables[i].setColor(sf::Color::Red);
        key = sortables[i];
        j = i - 1;

        //sf::sleep(sf::milliseconds(150));
        drawSortable(sortables);

        while (j >= 0 && sortables[j] > key) {

            sortables[j + 1] = sortables[j];
            sortables[j] = key;

            //sf::sleep(sf::milliseconds(150));
            drawSortable(sortables);
            --j;
        }
        sortables[j + 1] = key;
        sortables[j+1].setColor(sf::Color::Green);
        //sf::sleep(sf::milliseconds(150));
        drawSortable(sortables);
    }

    isPaused = true;
}

void swap(SortObject &bar1, SortObject &bar2) {
    SortObject temp;
}
