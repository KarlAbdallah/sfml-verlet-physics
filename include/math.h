#ifndef MATH_H
#define MATH_H

#include <cmath>
#include <SFML/System/Vector2.hpp>

using Vec2 = sf::Vector2<double>;

namespace Math {
    double norm(Vec2 vec) {
        return sqrt(vec.x*vec.x + vec.y*vec.y);
    }
    
    Vec2 normalize(Vec2 vec) {
        return vec / norm(vec);
    }

    double dot(Vec2 a, Vec2 b) {
        return a.x*b.x + a.y*b.y;
    }

    // Vec2 cross(Vec2 a, Vec2 b) {
    //     return {a.x*b.y, -b.x*a.y};
    // }
};

#endif // MATH_H
