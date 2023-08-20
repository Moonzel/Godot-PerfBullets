#ifndef BULLET_H
#define BULLET_H

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/mesh_instance2d.hpp>
#include <godot_cpp/classes/shape2d.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

//The class that the user chooses the properties for the bullet. Can be saved as a Resource and used again with another Spawner.
class BulletType : public Resource {
    GDCLASS(BulletType, Resource);

private:
    float animationSpeed = 0.2;
    float initialSpeed = 100;
    float maxLifetime = 10.0;
    Ref<Shape2D> shape;
    float acceleration = 0.0; 
    float minSpeed = -9999999.0;
    float maxSpeed = 9999999.0;
    int mask = 1;
    bool collideWithBodies = false;
    bool collideWithAreas = true;
    float scale = 1.0;
    int numberOfQueries = 1;

public:
    static void _bind_methods();

    BulletType();
    ~BulletType();

    //Setter and getter functions for the BulletType Class

    void set_animation_lifetime(float animation_lifetime);
    float get_animation_lifetime() const;

   void set_initial_speed(float ispd);
   float get_initial_speed() const;

    void set_max_lifetime(float life);
    float get_max_lifetime() const;

    void set_animation_speed(float speed);
    float get_animation_speed() const;

    void set_acceleration(float acc);
    float get_acceleration() const;

    void set_min_speed(float miSpeed);
    float get_min_speed() const;

    void set_max_speed(float maSpeed);
    float get_max_speed() const;

    void set_shape(Ref<Shape2D> s);
    Ref<Shape2D> get_shape() const;

    void set_mask(int m);
    int get_mask() const;

    void set_collide_with_bodies(bool c);
    bool get_collide_with_bodies() const;

    void set_collide_with_areas(bool c);
    bool get_collide_with_areas() const;

    void set_scale(float s);
    float get_scale() const;

    void set_number_of_queries(int num);
    int get_number_of_queries() const;
};

#endif // BULLET_H
