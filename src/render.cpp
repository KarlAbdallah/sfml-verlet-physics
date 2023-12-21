#include <cmath>
#include "../include/render.h"

Render::SpawnParams spawn_param = {
    .velocity = {0.0, 0.0},
    .mass     = 1.0
};

const sf::Color dark_gray(20, 20, 20);
sf::CircleShape circle_constraint;

Render::Render() {

}

Render::~Render() {

}

void Render::initialize(Solver* solver, sf::RenderWindow* window) {
    m_solver = solver;
    m_window = window;
}

void Render::renderFrame() {
    m_window->clear(sf::Color::Black);

    circle_constraint.setPosition({0, 0});
    circle_constraint.setRadius(400.0);
    circle_constraint.setPointCount(200);
    circle_constraint.setFillColor(dark_gray);

    m_window->draw(circle_constraint);


    sf::Font font;
    font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");

    sf::Text velocity;
    velocity.setFont(font);
    velocity.setString("Vel.: [" + std::to_string((int) spawn_param.velocity.x) + ", "
        + std::to_string((int) spawn_param.velocity.y) + "]");
    velocity.setCharacterSize(24);

    sf::Text mass;
    mass.setFont(font);
    mass.setString("Mass: " + std::to_string((int) spawn_param.mass));
    mass.setCharacterSize(24);
    mass.setOrigin(0, -30);

    m_window->draw(velocity);
    m_window->draw(mass);

    for (Object* obj : m_solver->getObjectVector()) {
        sf::CircleShape circle;
        circle.setOrigin({25.0, 25.0});
        circle.setPosition((sf::Vector2<float>) obj->getCurrentPosition());
        circle.setRadius(25.0);
        circle.setPointCount(200);
        circle.setFillColor(sf::Color::White);
        m_window->draw(circle);
    }

    m_window->display();
}


void Render::setSpawnParams(SpawnParams spawn_params) {
    spawn_param = spawn_params;
}