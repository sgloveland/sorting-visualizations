#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>
#include "SortObject.h"
using namespace std;

const unsigned WINDOW_WIDTH = 1000;
const unsigned WINDOW_HEIGHT = 1000;
const int SORTABLE_COUNT = 100;
int delay = 100;
bool isPaused = false;

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Visualizer");

void fillSortable(SortObject sortables[]);
void drawSortable(SortObject sortables[]);

void swap(SortObject &bar1, SortObject &bar2);

void insertionSort(SortObject sortables[]);
void bubbleSort(SortObject sortables[]);
void selectionSort(SortObject sortables[]);

int main() {
    SortObject sortables[SORTABLE_COUNT];
    fillSortable(sortables);


    while(window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed) {window.close();}
        }

        if(!isPaused)
            selectionSort(sortables);
            //insertionSort(sortables);
            //bubbleSort(sortables);
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

        sf::sleep(sf::milliseconds(delay));
        drawSortable(sortables);

        while (j >= 0 && sortables[j] > key) {

            sortables[j + 1] = sortables[j];
            sortables[j] = key;

            sf::sleep(sf::milliseconds(delay));
            drawSortable(sortables);
            --j;
        }
        sortables[j + 1] = key;
        sortables[j+1].setColor(sf::Color::Green);
        sf::sleep(sf::milliseconds(delay));
        drawSortable(sortables);
    }

    isPaused = true;
}

void bubbleSort(SortObject sortables[]) {
    for(int i = SORTABLE_COUNT - 1; i >= 0; --i) {
        for(int j = 0; j < i; ++j) {
            if(sortables[j] > sortables[j+1]) {
                //color both bars to be swapped as the color red
                sortables[j].setColor(sf::Color::Red);
                sortables[j + 1].setColor(sf::Color::Red);

                //draw the array with the red bars before swap
                sf::sleep(sf::milliseconds(delay));
                drawSortable(sortables);

                swap(sortables[j], sortables[j + 1]);

                sf::sleep(sf::milliseconds(delay));
                drawSortable(sortables);

                sortables[j].setColor(sf::Color::White);
                sortables[j + 1].setColor(sf::Color::White);

                //display the array after the swap
                sf::sleep(sf::milliseconds(delay));
                drawSortable(sortables);
            }
        }
        sortables[i].setColor(sf::Color::Green);
        sf::sleep(sf::milliseconds(delay));
        drawSortable(sortables);
    }
    drawSortable(sortables);
}

void selectionSort(SortObject sortables[]) {
    int minIndex;

    for(int i = 0; i < SORTABLE_COUNT - 1; ++i) {
        isPaused = true;
        minIndex = i;
        sortables[minIndex].setColor(sf::Color::Blue);
        drawSortable(sortables);

        for(int j = i + 1; j < SORTABLE_COUNT; ++j) {
            if(sortables[j] < sortables[minIndex]) {
                sortables[minIndex].setColor(sf::Color::White);

                minIndex = j;

                sortables[minIndex].setColor(sf::Color::Blue);
                sf::sleep(sf::milliseconds(delay));
                drawSortable(sortables);
            }
        }
        if(minIndex != i) {
            sortables[i].setColor(sf::Color::Red);
            sortables[minIndex].setColor(sf::Color::Red);
            sf::sleep(sf::milliseconds(delay));
            drawSortable(sortables);

            swap(sortables[minIndex], sortables[i]);

            sf::sleep(sf::milliseconds(delay));
            drawSortable(sortables);

            sortables[minIndex].setColor(sf::Color::White);
            sortables[i].setColor(sf::Color::Green);

            sf::sleep(sf::milliseconds(delay));
            drawSortable(sortables);
        }
        else {
            sortables[i].setColor(sf::Color::Green);
            sf::sleep(sf::milliseconds(delay));
            drawSortable(sortables);
        }
    }

    sortables[SORTABLE_COUNT - 1].setColor(sf::Color::Green);
    drawSortable(sortables);
}

void swap(SortObject &bar1, SortObject &bar2) {
    SortObject temp = bar1;
    bar1 = bar2;
    bar2 = temp;
}
