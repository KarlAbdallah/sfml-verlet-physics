#ifndef EVENT_H
#define EVENT_H

#include <SFML/Graphics.hpp>
#include "solver.h"
#include "render.h"

class Event {
    private: 
        Solver* m_solver;
        sf::RenderWindow* m_window;
    
    public:
        Event();
        ~Event();

        void initialize(Solver* solver, sf::RenderWindow* window);
        void checkForEvents();
        void drawCurrentSpawnParams();
};

#endif // EVENT_H
