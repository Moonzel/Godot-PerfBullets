#include "bulProps.h"
#include "spawner.h"


#include <godot_cpp/core/class_db.hpp>

void BulProps::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_position", "pos"), &BulProps::set_position);
    ClassDB::bind_method(D_METHOD("get_position"), &BulProps::get_position);

    ClassDB::bind_method(D_METHOD("set_last_increment", "last"), &BulProps::set_last_increment);
    ClassDB::bind_method(D_METHOD("get_last_increment"), &BulProps::get_last_increment);

    ClassDB::bind_method(D_METHOD("set_speed", "spd"), &BulProps::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &BulProps::get_speed);

    ClassDB::bind_method(D_METHOD("set_direction", "dir"), &BulProps::set_direction);
    ClassDB::bind_method(D_METHOD("get_direction"), &BulProps::get_direction);

    ClassDB::bind_method(D_METHOD("set_lifetime", "life"), &BulProps::set_lifetime);
    ClassDB::bind_method(D_METHOD("get_lifetime"), &BulProps::get_lifetime);

    ClassDB::bind_method(D_METHOD("set_animation_lifetime", "lt"), &BulProps::set_animation_lifetime);
    ClassDB::bind_method(D_METHOD("get_animation_lifetime"), &BulProps::get_animation_lifetime);

    ClassDB::bind_method(D_METHOD("set_shape_rid", "value"), &BulProps::set_shape_rid);
    ClassDB::bind_method(D_METHOD("get_shape_rid"), &BulProps::get_shape_rid);

    ClassDB::bind_method(D_METHOD("set_query", "q"), &BulProps::set_query);
    ClassDB::bind_method(D_METHOD("get_query"), &BulProps::get_query);
    
    ClassDB::add_property("BulProps", PropertyInfo(Variant::RID, "shapeRID"), "set_shape_rid", "get_shape_rid");
    ClassDB::add_property("BulProps", PropertyInfo(Variant::VECTOR2, "position"), "set_position", "get_position");
    ClassDB::add_property("BulProps", PropertyInfo(Variant::VECTOR2, "last_increment"), "set_last_increment", "get_last_increment");
    ClassDB::add_property("BulProps", PropertyInfo(Variant::VECTOR2, "direction"), "set_direction", "get_direction");
    ClassDB::add_property("BulProps", PropertyInfo(Variant::FLOAT, "lifetime"), "set_lifetime", "get_lifetime");
    ClassDB::add_property("BulProps", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
}

BulProps::BulProps() {
}

BulProps::~BulProps() {
}

void BulProps::set_position(Vector2 pos) {
    position = pos;
}

Vector2 BulProps::get_position() const {
    return position;
}

void BulProps::set_last_increment(Vector2 last) {
    last_increment = last;
}

Vector2 BulProps::get_last_increment() const {
    return last_increment;
}

void BulProps::set_direction(Vector2 dir) {
    direction = dir;
}

Vector2 BulProps::get_direction() const {
    return direction;
}

void BulProps::set_lifetime(float life) {
    lifetime = life;
}

float BulProps::get_lifetime() const {
    return lifetime;
}

void BulProps::set_shape_rid(RID value) {
        shapeRID = value;
}

RID BulProps::get_shape_rid() const {
    return shapeRID;
}

void BulProps::set_speed(float spd) {
        speed = spd;
    }

float BulProps::get_speed() const {
    return speed;
}

void BulProps::set_animation_lifetime(float lt) {
        animationTime = lt;
    }

float BulProps::get_animation_lifetime() const {
    return animationTime;
}

void BulProps::set_query(Ref<PhysicsShapeQueryParameters2D> q) {
        query = q;
    }

Ref<PhysicsShapeQueryParameters2D> BulProps::get_query() const {
    return query;
}