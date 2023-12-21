#include "../include/event.h"
#include <cmath>


Render::SpawnParams current_spawn_params = {
    .velocity = {0.0, 0.0},
    .mass     = 1.0
};

Event::Event() {

}

Event::~Event() {

}

void Event::initialize(Solver* solver, sf::RenderWindow* window) {
    m_solver = solver;
    m_window = window;
}

void Event::checkForEvents() {
    sf::Event event;
    while (m_window->pollEvent(event)) {
        // close window and stop process
        if (event.type == sf::Event::Closed) m_window->close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) m_window->close();

        // spawn objects and initialize them through solver
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            m_solver->createObject({(double) event.mouseButton.x, (double) event.mouseButton.y});
            // Updating params of last spawned object
            m_solver->getObjectVector().back()->setVelocity(current_spawn_params.velocity);
            m_solver->getObjectVector().back()->setMass(current_spawn_params.mass);
        }

        // edit spawned objects initial velocity
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
            current_spawn_params.velocity.x += 5.0;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
            current_spawn_params.velocity.x -= 5.0;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
            current_spawn_params.velocity.y -= 5.0;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
            current_spawn_params.velocity.y += 5.0;
        }

        // edit spawned objects initial mass
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::PageUp) {
            current_spawn_params.mass += 1.0;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::PageDown) {
            if (current_spawn_params.mass > 1.0) {
                current_spawn_params.mass -= 1.0;
            }
        }

        // Push params to render unit
        Render::setSpawnParams(current_spawn_params);
    }
}