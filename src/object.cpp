#include "../include/object.h"
#include <cmath>


Object::Object() {

}

Object::~Object() {

}

Vec2 Object::getCurrentPosition() {
    return m_pos_cur;
}

Vec2 Object::getOldPosition() {
    return m_pos_old;
}

Vec2 Object::getVelocity() {
    return m_velocity;
}

Vec2 Object::getInstantVelocity() {
    return m_instant_velocity;
}

double Object::getMass() {
    return m_mass;
}

void Object::initialize(Vec2 pos) {
    m_pos_cur = pos;
    m_pos_old = pos;
    m_velocity = {0.0, 0.0};
    m_mass = 1.0;
}

void Object::setCurrentPosition(Vec2 pos) {
    m_pos_cur = pos;
}

void Object::setOldPosition(Vec2 pos) {
    m_pos_old = pos;
}

void Object::setVelocity(Vec2 velocity) {
    m_velocity = velocity;
}

void Object::addVelocity(Vec2 velocity) {
    m_velocity += velocity;
}

void Object::setInstantVelocity(Vec2 instant_velocity) {
    m_instant_velocity = instant_velocity;
}

void Object::setMass(double mass) {
    m_mass = mass;
}