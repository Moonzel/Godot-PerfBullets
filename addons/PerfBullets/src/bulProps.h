#ifndef BULPROPS_H
#define BULPROPS_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/physics_shape_query_parameters2d.hpp>
#include <godot_cpp/classes/shape2d.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>

#include <godot_cpp/variant/rid.hpp>

class Spawner;

using namespace godot;

//The Class that is used internally for the Spawner. There is one of these for every bullet in the pool.
class BulProps : public Resource {
    GDCLASS(BulProps, Resource)

private:
    Vector2 position = Vector2();
    Vector2 last_increment = Vector2();
    Vector2 direction = Vector2();
    float speed = 0.0;
    float lifetime = 0.0;
    float animationTime = 0.0;
    RID shapeRID;

    Ref<PhysicsShapeQueryParameters2D> query = memnew(PhysicsShapeQueryParameters2D);

public:
    static void _bind_methods();

    BulProps();
    ~BulProps();

    void set_query(Ref<PhysicsShapeQueryParameters2D> q);
    Ref<PhysicsShapeQueryParameters2D> get_query() const;

    void set_position(Vector2 pos);
    Vector2 get_position() const;

    void set_last_increment(Vector2 pos);
    Vector2 get_last_increment() const;

    void set_direction(Vector2 dir);
    Vector2 get_direction() const;

    void set_lifetime(float vel);
    float get_lifetime() const;

    void set_animation_lifetime(float lt);
    float get_animation_lifetime() const;

    void set_shape_rid(RID value);
    RID get_shape_rid() const;

    void set_speed(float spd);
    float get_speed() const;
};

#endif // BULPROPS_H