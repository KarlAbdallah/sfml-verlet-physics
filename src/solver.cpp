#include <cmath>
#include <iostream>
#include "../include/solver.h"
#include "../include/math.h"


const double RADIUS = 25.0;

Solver::Solver() {

}

Solver::~Solver() {

}

void Solver::initialize(double dt) {
    m_dt = dt / m_substeps;
}

void Solver::addObject(Object* obj) {
    m_objects.push_back(obj);
}

void Solver::createObject(Vec2 pos) {
    Object* obj = new Object;
    obj->initialize(pos);
    addObject(obj);
}

void Solver::updatePositions() {
    for (Object* obj : m_objects) {
        Vec2 pos_old = obj->getOldPosition();
        Vec2 pos_cur = obj->getCurrentPosition();
        Vec2 velocity = obj->getVelocity();
        Vec2 instant_velocity;

        Vec2 dx = pos_cur - pos_old;
        pos_old = pos_cur;
        pos_cur = pos_cur + dx + velocity * m_dt;
        instant_velocity = (pos_cur - pos_old) / m_dt;
        velocity = {};
        
        obj->setOldPosition(pos_old);
        obj->setCurrentPosition(pos_cur);
        obj->setVelocity(velocity);
        obj->setInstantVelocity(instant_velocity);
    }
}

void Solver::applyGravity() {
    const Vec2 gravity = {0.0, m_gravity};
    for (Object* obj : m_objects) {
        obj->addVelocity(gravity*m_dt);
    }
}

void Solver::update() {
    for (int i = 0; i < m_substeps; i++) {
        applyGravity();
        applyConstraints();
        applyDrag();
        checkForCollisions();
        updatePositions();
    }
    // Print total energy in console
    // std::cout << totalEnergy() << std::endl;
}

void Solver::applyConstraints() {
    const Vec2 circle_origin = {400.0, 400.0};
    const double radius = 400.0;
    const double coeff_restitution = 0.90;
    for (Object* obj : m_objects) {
        const Vec2 dist_to_object = circle_origin - obj->getCurrentPosition();
        
        // TODO: optimize the use norm() / normalize() for better performance
        if (Math::norm(dist_to_object) > (radius - RADIUS)) {
            const Vec2 n_dir = Math::normalize(dist_to_object);
            // obj->setCurrentPosition(circle_origin - n_dir * (radius - RADIUS));

            obj->addVelocity(Math::norm(coeff_restitution * obj->getInstantVelocity()) * n_dir);
            obj->setCurrentPosition(circle_origin - n_dir * (radius - RADIUS));
            obj->setOldPosition(obj->getCurrentPosition());
        }
    }
}

void Solver::checkForCollisions() {
    // TODO: Implement proximity-based collision checking to avoid checking
    //       for collisions between far apart objects (better performance).
    //       Perhaps use tile method?

    const double coeff_restitution = 0.67;
    for (int i = 0; i < m_objects.size(); i++) {
        Object* obj_1 = m_objects[i];

        for (int j = i+1; j < m_objects.size(); j++) {
            Object* obj_2 = m_objects[j];

            Vec2 dist_between_object_pair = obj_1->getCurrentPosition()
                                            - obj_2->getCurrentPosition();

            if (Math::norm(dist_between_object_pair) < 2.0*RADIUS) {
                Vec2 v_rel = obj_1->getInstantVelocity()
                             - obj_2->getInstantVelocity();
                Vec2 n_dir = Math::normalize(dist_between_object_pair);
                
                if (Math::dot(v_rel, n_dir) < 0.0) {
                    double overlap = 2.0*RADIUS - Math::norm(dist_between_object_pair);
                    double m_a = obj_1->getMass();
                    double m_b = obj_2->getMass();
                    double impulse_J = -(1+coeff_restitution) * (Math::dot(v_rel, n_dir))
                        / (1/m_a + 1/m_b) / Math::dot(n_dir, n_dir);
                    obj_1->addVelocity( (impulse_J * n_dir / m_a));
                    obj_2->addVelocity(-(impulse_J * n_dir / m_b));
                }
            }
        }
    }
}

void Solver::applyDrag() {
    const double damping = 0.05;
    for (Object* obj : m_objects) {
        obj->addVelocity(-damping * obj->getInstantVelocity() * m_dt);
    }
}

std::vector<Object*>& Solver::getObjectVector() {
    return m_objects;
}

double Solver::totalEnergy() {
    double energy = 0.0;
    for (Object* obj : m_objects) {
        Vec2 pos_cur = obj->getCurrentPosition();
        double velocity = Math::norm(obj->getInstantVelocity());

        energy += m_gravity*((800-RADIUS)-pos_cur.y) + 0.5 * velocity * velocity;
    }
    return energy;
}
