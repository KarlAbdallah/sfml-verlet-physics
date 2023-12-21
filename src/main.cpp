#include <SFML/Graphics.hpp>
#include "../include/solver.h"
#include "../include/object.h"
#include "../include/render.h"
#include "../include/event.h"


int main() {
    Solver solver;
    Render render;
    Event event;

    // window creation
    sf::RenderWindow window(sf::VideoMode(800, 800), "Engine");
    window.setFramerateLimit(500);
    
    solver.initialize(0.01);
    render.initialize(&solver, &window);
    event.initialize(&solver, &window);

    // run until window is closed
    while (window.isOpen()) {
        event.checkForEvents();
        solver.update();
        render.renderFrame();
    }
    
    return 0;
}
