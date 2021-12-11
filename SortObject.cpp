//
// Created by Sean Loveland on 12/6/21.
//

#include "SortObject.h"

SortObject::SortObject() {
    m_value = 0;
    m_shape.setSize(sf::Vector2f(20, 20));
}

int SortObject::getValue() const {
    return m_value;
}

sf::RectangleShape SortObject::getShape() const {
    return m_shape;
}

void SortObject::setValue(int newValue) {
    m_value = newValue;
}

void SortObject::setShapePosition(float xPos, float yPos) {
    m_shape.setPosition(xPos, yPos);
}

void SortObject::setShapeSize(float pixelWidth, float pixelHeight) {
    m_shape.setSize(sf::Vector2f(pixelWidth, pixelHeight));
}

void SortObject::setColor(sf::Color color) {
    m_shape.setFillColor(color);
}

bool SortObject::operator <(const SortObject& other) {
    return m_value < other.m_value;
}

bool SortObject::operator >(const SortObject& other) {
    return m_value > other.m_value;
}

bool SortObject::operator ==(const SortObject& other) {
    return m_value == other.m_value;
}

