#ifndef RENDER_H
#define RENDER_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "solver.h"


class Render {
    public:
        struct SpawnParams {
            Vec2 velocity;
            double mass;
        };

    private:
        Solver* m_solver;
        sf::RenderWindow* m_window;

    public:
        Render();
        ~Render();

        void initialize(Solver* solver, sf::RenderWindow* window);
        void renderFrame();
        static void setSpawnParams(SpawnParams spawn_params);
};

#endif // RENDER_H
