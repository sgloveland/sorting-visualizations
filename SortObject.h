//
// Created by Sean Loveland on 12/6/21.
//

#ifndef SORTINGVISUALIZER_SORTOBJECT_H
#define SORTINGVISUALIZER_SORTOBJECT_H
#include <SFML/Graphics.hpp>

class SortObject {
public:
    /*
     * Default constructor
     * Sets m_value to 0, creates a rectangle of width 20 and height of 200
     * sets default color to sf::Color::Blue
     */
    SortObject();

    /*
     * Getters
     */
    int getValue() const;
    sf::RectangleShape getShape() const;

    /*
     * Setters
     */
    void setValue(int newValue);
    void setShapePosition(float xPos, float yPos);
    void setShapeSize(float pixelWidth, float pixelHeight);
    void setColor(sf::Color color);

    /*
     * Overloaded operators
     */
    bool operator <(const SortObject& other);
    bool operator >(const SortObject& other);
    bool operator ==(const SortObject& other);

private:
    int m_value;
    sf::RectangleShape m_shape;
};


#endif //SORTINGVISUALIZER_SORTOBJECT_H
