#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../include/object.h"


class Solver {
    private:
        double m_dt;
        const int m_substeps = 16;
        const double m_gravity = 100.0;
        std::vector<Object*> m_objects;
        
    public:
        Solver();
        ~Solver();
        
        void initialize(double dt);
        void addObject(Object* obj);
        void createObject(Vec2 pos);
        void update();
        void updatePositions();
        void applyGravity();
        void applyConstraints();
        void checkForCollisions();
        void applyDrag();

        std::vector<Object*>& getObjectVector();
        
        double totalEnergy();
};

#endif // SOLVER_H
