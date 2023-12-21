#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/System/Vector2.hpp>

using Vec2 = sf::Vector2<double>;


class Object {
    private:
        Vec2 m_pos_cur;
        Vec2 m_pos_old;
        Vec2 m_velocity;
        Vec2 m_instant_velocity;

        double m_mass;
    
    public:
        Object();
        ~Object();

        Vec2 getCurrentPosition();
        Vec2 getOldPosition();
        Vec2 getVelocity();
        Vec2 getInstantVelocity();
        
        double getMass();

        void initialize(Vec2 pos);
        void setCurrentPosition(Vec2 pos);
        void setOldPosition(Vec2 pos);
        void setVelocity(Vec2 velocity);
        void addVelocity(Vec2 velocity);
        void setInstantVelocity(Vec2 instant_velocity);
        void setMass(double mass);
};

#endif // OBJECT_H
