#ifndef SPAWNER_H
#define SPAWNER_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/multi_mesh_instance2d.hpp>
#include <godot_cpp/classes/physics_server2d.hpp>
#include <godot_cpp/classes/multi_mesh.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/circle_shape2d.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/variant/transform2d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/classes/texture.hpp>
#include <godot_cpp/classes/mesh_instance2d.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include <godot_cpp/classes/material.hpp>
#include <godot_cpp/classes/shader.hpp>
#include <godot_cpp/classes/shader_material.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/classes/physics_shape_query_parameters2d.hpp>
#include <godot_cpp/classes/world2d.hpp>
#include <godot_cpp/classes/physics_direct_space_state2d.hpp>
#include <godot_cpp/classes/quad_mesh.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/shader_material.hpp>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <type_traits>

#include "bullet_type.h"
#include "bulProps.h"

using namespace godot;

class Spawner : public MultiMeshInstance2D {
    GDCLASS(Spawner, MultiMeshInstance2D)

public:
    enum Mode {
        PROCESS = 0,
        PHYSICS = 1
    };

    enum StartMode {
        ONSTART = 0,
        PATTERNMANAGER = 1,
        MANUAL = 2
    };

private:
    //Export variables for the user to modifiy
    Spawner::StartMode startMode = ONSTART;
    Array bullets;
    int ID = 1;
    bool moveWithParent = false;
    Node2D *trackedNode = nullptr;
    Rect2 boundBox;
    bool start = false;
    int poolCount = 1000;
    MeshInstance2D *sprite = nullptr;
    float textureRotation = 0.0;
    float fireRate = 1.0;
    float fireRadiusDegrees = 360.0;//0-360
    float startRotation = 0.0;
    int numberOfRadii = 1;
    float degreesBetweenRadii = 0.0;
    int bulletsPerRadius = 1;
    float spinRate = 0.0;
    Ref<BulletType> bulletType;
    int numberOfShots = -1;
    bool randomStart = false;
    float randomRadius = 360.0;
    float maxSpin = 50.0;
    float minSpin = 50.0;
    bool restartAtSpin = true;
    float spinAcceleration = 0.0;
    Spawner::Mode spawnerMode = PROCESS;
    bool homing = false;
    float homingWeight = 1.0;
    bool startTowardPlayer = false;//sets as the first rotation, doesnt change after instanciation, can still use spirals if needed
    bool staysTowardPlayer = false;//keeps setting it for every bullet in the pattern, spin cant work
    float offsetTowardPlayer = 0.0;//offsets the amount in degrees 
    float gravity = 0.0; 
    int rowsInAtlas = 1;
    int columnsInAtlas = 1;
    bool returnBulletsToPoolAutomatically = true;
    bool manualStart = false;

    //Variables for the user to not modify; Used internally
    Timer *timer = nullptr;
    int count = 0;
    Ref<MultiMesh> multi;
    Array vis;
    float fRotation = 0.0;
    float spinSign = 1.0;
    int currentIdx = 0;
    Ref<RandomNumberGenerator> randItem = memnew(RandomNumberGenerator);
    PhysicsDirectSpaceState2D* space_state = nullptr;
    int currentRow = 1;
    int currentColumn = 1;

public:
    static void _bind_methods();

    Spawner();
    ~Spawner();

    //Custom functions, currently the last one is for debug purposes only
    void _physics_process(float delta);

    void _process(float delta);

    void _on_tree_exiting();

    void _ready();

    void _main(float delta);

    void start_node(int id);

    void spawn_bullet_self(Vector2 dir);

    void clear_all();

    void free_bullet_to_pool(int idx);

    int get_next_idx();

    void calc_vel(Ref<BulProps> bul, float delta);

    void _add_shape(Ref<BulProps>);

    void animate(Ref<BulProps>, int num, float delta);

    void set_bounding_box(Rect2 box);

    Array get_active_bullets() const;

    Ref<BulProps> get_bullet_from_index(int idx) const;
    
    //Setter and getter functions for the export variables
    void set_bullets(Array buls);
    Array get_bullets() const;

    void set_fire_rate(float rate);
    float get_fire_rate() const;

    void set_fire_radius_degrees(float degrees);
    float get_fire_radius_degrees() const;

    void set_bullets_per_radius(int count);
    int get_bullets_per_radius() const;

    void set_spin_rate(float sRate);
    float get_spin_rate() const;

    void set_max_spin(float max);
    float get_max_spin() const;

    void set_min_spin(float min);
    float get_min_spin() const;

    void set_start_rotation(float rot);
    float get_start_rotation() const;

    void set_homing(bool value);
    bool get_homing() const;

    void set_start_toward_player(bool value);
    bool get_start_toward_player() const;

    void set_gravity(float value);
    float get_gravity() const;

    void set_bullet_type(Ref<BulletType> type);
    Ref<BulletType> get_bullet_type() const;

    void set_tracked_node(Node2D* p);
    Node2D* get_tracked_node() const;

    void set_start(bool st);
    bool get_start() const;

    void set_pool_count(int count);
    int get_pool_count() const;

    void set_number_of_shots(int num);
    int get_number_of_shots() const;
    
    void set_texture_rotation(float rot);
    float get_texture_rotation() const;

    void set_random(bool val);
    bool get_random() const;

    void set_random_radius(float rad);
    float get_random_radius() const;

    void set_number_of_radii(int value);
    int get_number_of_radii() const;

    void set_degrees_between_radii(float value);
    float get_degrees_between_radii() const;

    void set_restart_at_spin(bool val);
    bool get_restart_at_spin() const;

    void set_spin_acceleration(float accel);
    float get_spin_acceleration() const;

    void set_homing_weight(float weight);
    float get_homing_weight() const;

    void set_offset_toward_player(float off);
    float get_offset_toward_player() const;

    void set_stays_toward_player(bool stay);
    bool get_stays_toward_player() const;

    void set_rows_in_atlas(int rows);
    int get_rows_in_atlas() const;

    void set_columns_in_atlas(int columns);
    int get_columns_in_atlas() const;

    void set_return_bullets_to_pool_automatically(bool b);
    bool get_return_bullets_to_pool_automatically() const;

    void set_id(int id);
    int get_id() const;

    void set_move_with_parent(bool move);
    bool get_move_with_parent() const;

    void set_start_mode(Spawner::StartMode mode);
    Spawner::StartMode get_start_mode() const;

    void set_spawner_mode(Spawner::Mode mode);
    Spawner::Mode get_spawner_mode() const;

    void set_manual_start(bool b);
    bool get_manual_start() const;
};

VARIANT_ENUM_CAST(Spawner::Mode);
VARIANT_ENUM_CAST(Spawner::StartMode);

#endif // SPAWNER_H