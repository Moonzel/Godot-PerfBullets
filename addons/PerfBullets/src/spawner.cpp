#include "spawner.h"
#include <godot_cpp/core/class_db.hpp>
using namespace godot;

void Spawner::_bind_methods() {
    //Binding the custom functions
    ClassDB::bind_method(D_METHOD("_main", "delta"), &Spawner::_main);
    ClassDB::bind_method(D_METHOD("set_bounding_box", "box"), &Spawner::set_bounding_box);
    ClassDB::bind_method(D_METHOD("free_bullet_to_pool", "idx"), &Spawner::free_bullet_to_pool);
    ClassDB::bind_method(D_METHOD("clear_all"), &Spawner::clear_all);
    ClassDB::bind_method(D_METHOD("start_node", "nme"), &Spawner::start_node);
    ClassDB::bind_method(D_METHOD("spawn_bullet_self", "vel"), &Spawner::spawn_bullet_self);
    ClassDB::bind_method(D_METHOD("get_next_idx"), &Spawner::get_next_idx);
    ClassDB::bind_method(D_METHOD("calc_vel", "bul", "delta"), &Spawner::calc_vel);
    ClassDB::bind_method(D_METHOD("animate", "bul", "num", "delta"), &Spawner::animate);
    ClassDB::bind_method(D_METHOD("get_bullet_from_index", "idx"), &Spawner::get_bullet_from_index);

    ClassDB::bind_method(D_METHOD("_on_tree_exiting"), &Spawner::_on_tree_exiting);

    //Setter and getter functions for the export variables
    ClassDB::bind_method(D_METHOD("set_homing_weight", "weight"), &Spawner::set_homing_weight);
    ClassDB::bind_method(D_METHOD("get_homing_weight"), &Spawner::get_homing_weight);

    ClassDB::bind_method(D_METHOD("set_bullets", "buls"), &Spawner::set_bullets);
    ClassDB::bind_method(D_METHOD("get_bullets"), &Spawner::get_bullets);

    ClassDB::bind_method(D_METHOD("set_fire_rate", "rate"), &Spawner::set_fire_rate);
    ClassDB::bind_method(D_METHOD("get_fire_rate"), &Spawner::get_fire_rate);

    ClassDB::bind_method(D_METHOD("set_fire_radius_degrees", "degrees"), &Spawner::set_fire_radius_degrees);
    ClassDB::bind_method(D_METHOD("get_fire_radius_degrees"), &Spawner::get_fire_radius_degrees);

    ClassDB::bind_method(D_METHOD("set_bullets_per_radius", "count"), &Spawner::set_bullets_per_radius);
    ClassDB::bind_method(D_METHOD("get_bullets_per_radius"), &Spawner::get_bullets_per_radius);

    ClassDB::bind_method(D_METHOD("set_spin_rate", "sRate"), &Spawner::set_spin_rate);
    ClassDB::bind_method(D_METHOD("get_spin_rate"), &Spawner::get_spin_rate);

    ClassDB::bind_method(D_METHOD("set_bullet_type", "type"), &Spawner::set_bullet_type);
    ClassDB::bind_method(D_METHOD("get_bullet_type"), &Spawner::get_bullet_type);

    ClassDB::bind_method(D_METHOD("set_start", "st"), &Spawner::set_start);
    ClassDB::bind_method(D_METHOD("get_start"), &Spawner::get_start);

    ClassDB::bind_method(D_METHOD("set_tracked_node", "p"), &Spawner::set_tracked_node);
    ClassDB::bind_method(D_METHOD("get_tracked_node"), &Spawner::get_tracked_node);

    ClassDB::bind_method(D_METHOD("set_pool_count", "count"), &Spawner::set_pool_count);
    ClassDB::bind_method(D_METHOD("get_pool_count"), &Spawner::get_pool_count);

    ClassDB::bind_method(D_METHOD("set_number_of_shots", "num"), &Spawner::set_number_of_shots);
    ClassDB::bind_method(D_METHOD("get_number_of_shots"), &Spawner::get_number_of_shots);

    ClassDB::bind_method(D_METHOD("set_texture_rotation", "rot"), &Spawner::set_texture_rotation);
    ClassDB::bind_method(D_METHOD("get_texture_rotation"), &Spawner::get_texture_rotation);

    ClassDB::bind_method(D_METHOD("set_start_rotation", "rot"), &Spawner::set_start_rotation);
    ClassDB::bind_method(D_METHOD("get_start_rotation"), &Spawner::get_start_rotation);

    ClassDB::bind_method(D_METHOD("set_random", "val"), &Spawner::set_random);
    ClassDB::bind_method(D_METHOD("get_random"), &Spawner::get_random);

    ClassDB::bind_method(D_METHOD("set_random_radius", "rad"), &Spawner::set_random_radius);
    ClassDB::bind_method(D_METHOD("get_random_radius"), &Spawner::get_random_radius);

    ClassDB::bind_method(D_METHOD("set_number_of_radii", "rad"), &Spawner::set_number_of_radii);
    ClassDB::bind_method(D_METHOD("get_number_of_radii"), &Spawner::get_number_of_radii);

    ClassDB::bind_method(D_METHOD("set_max_spin", "max"), &Spawner::set_max_spin);
    ClassDB::bind_method(D_METHOD("get_max_spin"), &Spawner::get_max_spin);

    ClassDB::bind_method(D_METHOD("set_min_spin", "min"), &Spawner::set_min_spin);
    ClassDB::bind_method(D_METHOD("get_min_spin"), &Spawner::get_min_spin);

    ClassDB::bind_method(D_METHOD("set_degrees_between_radii", "deg"), &Spawner::set_degrees_between_radii);
    ClassDB::bind_method(D_METHOD("get_degrees_between_radii"), &Spawner::get_degrees_between_radii);

    ClassDB::bind_method(D_METHOD("set_restart_at_spin", "val"), &Spawner::set_restart_at_spin);
    ClassDB::bind_method(D_METHOD("get_restart_at_spin"), &Spawner::get_restart_at_spin);

    ClassDB::bind_method(D_METHOD("set_spin_acceleration", "accel"), &Spawner::set_spin_acceleration);
    ClassDB::bind_method(D_METHOD("get_spin_acceleration"), &Spawner::get_spin_acceleration);

    ClassDB::bind_method(D_METHOD("set_homing", "value"), &Spawner::set_homing);
    ClassDB::bind_method(D_METHOD("get_homing"), &Spawner::get_homing);

    ClassDB::bind_method(D_METHOD("set_start_toward_player", "value"), &Spawner::set_start_toward_player);
    ClassDB::bind_method(D_METHOD("get_start_toward_player"), &Spawner::get_start_toward_player);

    ClassDB::bind_method(D_METHOD("set_gravity", "value"), &Spawner::set_gravity);
    ClassDB::bind_method(D_METHOD("get_gravity"), &Spawner::get_gravity);

    ClassDB::bind_method(D_METHOD("set_offset_toward_player", "off"), &Spawner::set_offset_toward_player);
    ClassDB::bind_method(D_METHOD("get_offset_toward_player"), &Spawner::get_offset_toward_player);

    ClassDB::bind_method(D_METHOD("set_stays_toward_player", "stay"), &Spawner::set_stays_toward_player);
    ClassDB::bind_method(D_METHOD("get_stays_toward_player"), &Spawner::get_stays_toward_player);

    ClassDB::bind_method(D_METHOD("set_rows_in_atlas", "rows"), &Spawner::set_rows_in_atlas);
    ClassDB::bind_method(D_METHOD("get_rows_in_atlas"), &Spawner::get_rows_in_atlas);

    ClassDB::bind_method(D_METHOD("set_columns_in_atlas", "columns"), &Spawner::set_columns_in_atlas);
    ClassDB::bind_method(D_METHOD("get_columns_in_atlas"), &Spawner::get_columns_in_atlas);

    ClassDB::bind_method(D_METHOD("set_id", "id"), &Spawner::set_id);
    ClassDB::bind_method(D_METHOD("get_id"), &Spawner::get_id);

    ClassDB::bind_method(D_METHOD("set_return_bullets_to_pool_automatically", "b"), &Spawner::set_return_bullets_to_pool_automatically);
    ClassDB::bind_method(D_METHOD("get_return_bullets_to_pool_automatically"), &Spawner::get_return_bullets_to_pool_automatically);

    ClassDB::bind_method(D_METHOD("set_start_mode", "mode"), &Spawner::set_start_mode);
    ClassDB::bind_method(D_METHOD("get_start_mode"), &Spawner::get_start_mode);

    ClassDB::bind_method(D_METHOD("set_move_with_parent", "move"), &Spawner::set_move_with_parent);
    ClassDB::bind_method(D_METHOD("get_move_with_parent"), &Spawner::get_move_with_parent);

    ClassDB::bind_method(D_METHOD("set_spawner_mode", "mode"), &Spawner::set_spawner_mode);
    ClassDB::bind_method(D_METHOD("get_spawner_mode"), &Spawner::get_spawner_mode);

    ClassDB::bind_method(D_METHOD("set_manual_start", "b"), &Spawner::set_manual_start);
    ClassDB::bind_method(D_METHOD("get_manual_start"), &Spawner::get_manual_start);

    ClassDB::bind_method(D_METHOD("get_active_bullets"), &Spawner::get_active_bullets);

    //Properties that the user will see as export variables
    //These properties are in the order that is displayed in the node
    ClassDB::add_property("Spawner", PropertyInfo(Variant::INT, "startMode", PROPERTY_HINT_ENUM, "ONSTART, PATTERNMANAGER, MANUAL"), "set_start_mode", "get_start_mode");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::INT, "spawnerMode", PROPERTY_HINT_ENUM, "PROCESS, PHYSICS"), "set_spawner_mode", "get_spawner_mode");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::OBJECT, "bulletType", PROPERTY_HINT_RESOURCE_TYPE, "BulletType"), "set_bullet_type", "get_bullet_type");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::INT, "ID"), "set_id", "get_id");

    ClassDB::add_property("Spawner", PropertyInfo(Variant::INT, "numberOfShots"), "set_number_of_shots", "get_number_of_shots");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::INT, "poolCount"), "set_pool_count", "get_pool_count");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "fireRate"), "set_fire_rate", "get_fire_rate");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "fireRadiusDegrees"), "set_fire_radius_degrees", "get_fire_radius_degrees");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::INT, "bulletsPerRadius"), "set_bullets_per_radius", "get_bullets_per_radius");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::INT, "numberOfRadii"), "set_number_of_radii", "get_number_of_radii");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "degreesBetweenRadii"), "set_degrees_between_radii", "get_degrees_between_radii");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "startRotation"), "set_start_rotation", "get_start_rotation");

    ClassDB::add_property_group("Spawner", "Spin", "");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "spinRate"), "set_spin_rate", "get_spin_rate");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "maxSpin"), "set_max_spin", "get_max_spin");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "minSpin"), "set_min_spin", "get_min_spin");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "spinAcceleration"), "set_spin_acceleration", "get_spin_acceleration");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::BOOL, "restartAtSpin"), "set_restart_at_spin", "get_restart_at_spin");
    
    ClassDB::add_property_group("Spawner", "Player Tracking", "");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::OBJECT, "trackedNode", PROPERTY_HINT_NODE_TYPE, "Node2D"), "set_tracked_node", "get_tracked_node");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::BOOL, "homing"), "set_homing", "get_homing");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "homingWeight"), "set_homing_weight", "get_homing_weight");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::BOOL, "startTowardPlayer"), "set_start_toward_player", "get_start_toward_player");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::BOOL, "staysTowardPlayer"), "set_stays_toward_player", "get_stays_toward_player");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "offsetTowardPlayer"), "set_offset_toward_player", "get_offset_toward_player");

    ClassDB::add_property_group("Spawner", "Animation", "");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::INT, "rowsInAtlas"), "set_rows_in_atlas", "get_rows_in_atlas");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::INT, "columnsInAtlas"), "set_columns_in_atlas", "get_columns_in_atlas");
    
    ClassDB::add_property_group("Spawner", "Random", "");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::BOOL, "randomStart"), "set_random", "get_random");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "randomRadius"), "set_random_radius", "get_random_radius");

    ClassDB::add_property_group("Spawner", "Misc.", "");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::BOOL, "moveWithParent"), "set_move_with_parent", "get_move_with_parent");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::BOOL, "returnBulletsToPoolAutomatically"), "set_return_bullets_to_pool_automatically", "get_return_bullets_to_pool_automatically");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "textureRotation"), "set_texture_rotation", "get_texture_rotation");
    ClassDB::add_property("Spawner", PropertyInfo(Variant::FLOAT, "gravity"), "set_gravity", "get_gravity");
    
    //Binding signals
    ADD_SIGNAL(MethodInfo("bullet_hit", PropertyInfo(Variant::ARRAY, "result"), PropertyInfo(Variant::INT, "bulletIndex"), PropertyInfo(Variant::OBJECT, "spawner")));
}

void Spawner::_ready()
{
    //This runs in the editor as well, so this check SHOULD only allow the main code to run after runtime
    if (!Engine::get_singleton()->is_editor_hint()){

        if (get_multimesh() != nullptr){
            multi = get_multimesh();
        }
        else {
            UtilityFunctions::print("Multimesh not found, creating one based off of texture");
            Ref<MultiMesh> newMultiMesh = memnew(MultiMesh);
            set_multimesh(newMultiMesh);
            multi = get_multimesh();

            //Create a quadmesh based off of the size of the texture
            Vector2 textSize = get_texture()->get_size();
            Ref<QuadMesh> customMesh = memnew(QuadMesh);
            customMesh.instantiate();
            customMesh->set_size(Vector2(textSize.x / columnsInAtlas, textSize.y / rowsInAtlas) * bulletType->get_scale());
            multi->set_mesh(customMesh);
        }

        if (get_material() == nullptr){
            //If the shader has not been set in the ediotr, it will attmept to set it here
            UtilityFunctions::print("Shader not set in editor, setting automatically");
            Ref<ShaderMaterial> mat = memnew(ShaderMaterial);
            Ref<Shader> shader = ResourceLoader::get_singleton()->load("res://addons/PerfBullets/PerfBulletsAnimation.gdshader");
            mat->set_shader(shader);
            set_material(mat);
        }
        else{
            UtilityFunctions::printerr("Shader could not be found, set the PerfBulletsAnimaiton shader to the Spawner");
        }

        if (startMode != PATTERNMANAGER){
            start_node(ID);
        }
    }
}

Spawner::Spawner()
{
    connect("tree_exiting", Callable(this, "_on_tree_exiting"));
}

void Spawner::start_node(int id){
    //Runs when the node has been added to the scene if mode is ONSTART, otherwse runs when the timer in PatternManager times out
    //Checks if the argument is the name of the node (for PatternManager)
    if (id == get_id()) {
        if (bulletType->get_scale() != 1.0) {
            Vector2 textSize = get_texture()->get_size();
            Ref<QuadMesh> customMesh = memnew(QuadMesh);
            customMesh.instantiate();
            customMesh->set_size(Vector2(textSize.x / columnsInAtlas, textSize.y / rowsInAtlas) * bulletType->get_scale());
            multi->set_mesh(customMesh);
        }

        fRotation = Math::deg_to_rad(startRotation);

        if (startTowardPlayer == true) {
            fRotation = get_global_position().direction_to(trackedNode->get_global_position()).angle() + Math::deg_to_rad(offsetTowardPlayer);
        }

        set_start(true);

        //Sets all of the properties of the multimesh
        multi = get_multimesh();

        multi->set_instance_count(0);
        multi->set_use_custom_data(true);
        multi->set_instance_count(poolCount);
        multi->set_visible_instance_count(-1);


        //Creates a BulProps resource in the bullets array for the amount in the poolCount
        for (int c = 0; c < poolCount; c++){
            Ref<BulProps> bul;
            bul.instantiate();
            bul->get_query()->set_collide_with_areas(bulletType->get_collide_with_areas());
            bul->get_query()->set_collide_with_bodies(bulletType->get_collide_with_bodies());
            bul->get_query()->set_collision_mask(bulletType->get_mask());
            bullets.append(bul);
        }

        space_state = get_world_2d()->get_direct_space_state();

        Ref<ShaderMaterial> mat = get_material();
        mat->set_shader_parameter("row", float(rowsInAtlas));
        mat->set_shader_parameter("col", float(columnsInAtlas));

        //Automatically sets a timer as a child of Spawner to deal with when the bullets shoot
        auto t = memnew(Timer);
        t->set_name(get_name());
        t->set_one_shot(true);
        t->set_wait_time(fireRate);
        t->set_timer_process_callback(Timer::TimerProcessCallback::TIMER_PROCESS_PHYSICS);
        add_child(t);
        timer = get_node<Timer>(String(get_name()));
    }
}

void Spawner::_on_tree_exiting()
{
	bullets.clear();
}

Spawner::~Spawner()
{
}

//Spawns a bullet from the pool
void Spawner::spawn_bullet_self(Vector2 dir) {
    if (get_start() == true) {
        if ((get_bullet_type() != nullptr) && (get_multimesh() != nullptr)) {
            if (multi->get_mesh() != nullptr) {
                //Gets the next index in the pool that is "turned off" or invisible
                int num = get_next_idx();
                //Reset the custom data
                multi->set_instance_custom_data(num, Color(1.0, 0.0, 0.0, 0.0));

                if (randomStart == true) {
                    float angToUse = Math::deg_to_rad(randItem->randf_range(0.0, randomRadius));
                    dir = Vector2(cos(angToUse), sin(angToUse)).normalized();
                }

                Ref<BulProps> bul = bullets[num];
                //The position is local so 0,0 is always right
                bul->set_position(Vector2(0,0));
                bul->set_last_increment(get_global_position());
                bul->set_direction(dir * bulletType->get_initial_speed());
                bul->set_speed(bulletType->get_initial_speed());

                if (bul->get_shape_rid() == RID()) {
                    _add_shape(bul);
                    bul->get_query()->set_shape_rid(bul->get_shape_rid());
                }

                //Get the angle of that velocity to set as the rotation
                float ang = bul->get_direction().angle();

                Transform2D transO;
                transO.rotate(Math::deg_to_rad(textureRotation));
                transO.rotate(ang);
                transO.set_origin(Vector2(0,0));
                multi->set_instance_transform_2d(num, transO);

                vis.append(num);
            }
        }
    }
}

//Gets the next avaiable index of a inactive bullet in the pool
int Spawner::get_next_idx(){
    while (currentIdx < multi->get_instance_count()){
        if (multi->get_instance_custom_data(currentIdx).r == 0.0){
            currentIdx += 1;
            return currentIdx - 1;
        }
        else{
            currentIdx += 1;
        }
    }
    currentIdx = 0;
    UtilityFunctions::print("Gone through every bullet, starting over at 0");
    while (currentIdx < multi->get_instance_count()){
        if (multi->get_instance_custom_data(currentIdx).r == 0.0){
            currentIdx += 1;
            return currentIdx - 1;
        }
        else{
            currentIdx += 1;
        }
    }

    UtilityFunctions::printerr("Error: Ran out of Bullets to reuse");
    return -2;
}

//Adds the shape to the BulProps of the bullet passed in. Does it here so there is not a huge clog at runtime
void Spawner::_add_shape(Ref<BulProps> bul){
    Ref<Shape2D> baseShape = get_bullet_type()->get_shape();
    String string_class = baseShape->get_class();

    //Checks for each possible class that a CollisionShape2D can be, and returns that as a NEW shape (has a unique RID).
    if (string_class == "CircleShape2D") {
        RID shapeToUse = PhysicsServer2D::get_singleton()->circle_shape_create();
        auto data = PhysicsServer2D::get_singleton()->shape_get_data(baseShape->get_rid());
        PhysicsServer2D::get_singleton()->shape_set_data(shapeToUse, data);
        bul->set_shape_rid(shapeToUse);
    } 
    else if (string_class == "RectangleShape2D") {
        RID shapeToUse = PhysicsServer2D::get_singleton()->rectangle_shape_create();
        auto data = PhysicsServer2D::get_singleton()->shape_get_data(baseShape->get_rid());
        PhysicsServer2D::get_singleton()->shape_set_data(shapeToUse, data);
        bul->set_shape_rid(shapeToUse);
    } 
    else if (string_class == "ConvexPolygonShape2D") {
        RID shapeToUse = PhysicsServer2D::get_singleton()->convex_polygon_shape_create();
        auto data = PhysicsServer2D::get_singleton()->shape_get_data(baseShape->get_rid());
        PhysicsServer2D::get_singleton()->shape_set_data(shapeToUse, data);
        bul->set_shape_rid(shapeToUse);
    }
    else if (string_class == "ConcavePolygonShape2D") {
        RID shapeToUse = PhysicsServer2D::get_singleton()->concave_polygon_shape_create();
        auto data = PhysicsServer2D::get_singleton()->shape_get_data(baseShape->get_rid());
        PhysicsServer2D::get_singleton()->shape_set_data(shapeToUse, data);
        bul->set_shape_rid(shapeToUse);
    }
    else if (string_class == "WorldBoundaryShape2D") {
        RID shapeToUse = PhysicsServer2D::get_singleton()->world_boundary_shape_create();
        auto data = PhysicsServer2D::get_singleton()->shape_get_data(baseShape->get_rid());
        PhysicsServer2D::get_singleton()->shape_set_data(shapeToUse, data);
        bul->set_shape_rid(shapeToUse);
    }
    else if (string_class == "SegmentShape2D") {
        RID shapeToUse = PhysicsServer2D::get_singleton()->segment_shape_create();
        auto data = PhysicsServer2D::get_singleton()->shape_get_data(baseShape->get_rid());
        PhysicsServer2D::get_singleton()->shape_set_data(shapeToUse, data);
        bul->set_shape_rid(shapeToUse);
    }
    else if (string_class == "SeparationRayShape2D") {
        RID shapeToUse = PhysicsServer2D::get_singleton()->separation_ray_shape_create();
        auto data = PhysicsServer2D::get_singleton()->shape_get_data(baseShape->get_rid());
        PhysicsServer2D::get_singleton()->shape_set_data(shapeToUse, data);
        bul->set_shape_rid(shapeToUse);
    }
    else if (string_class == "CapsuleShape2D") {
        RID shapeToUse = PhysicsServer2D::get_singleton()->capsule_shape_create();
        auto data = PhysicsServer2D::get_singleton()->shape_get_data(baseShape->get_rid());
        PhysicsServer2D::get_singleton()->shape_set_data(shapeToUse, data);
        bul->set_shape_rid(shapeToUse);
    }
}

//Chooses physics_process or process depending on the mode
void Spawner::_physics_process(float delta)
{   
    if (spawnerMode == PHYSICS){
        _main(delta);
    }
}

void Spawner::_process(float delta){
    if (spawnerMode == PROCESS){
        _main(delta);
    }
}

//The main function where all of the bullets are updated, and collision is checked for. It is the most important part of the plugin. 
void Spawner::_main(float delta)
{   
    if (get_start() == true) {
    //If the timer has timed out, a new is spawned, based on all of the settings
          if ((timer->is_stopped() == true && startMode != StartMode::MANUAL) || (manualStart == true)){
            manualStart = false;
            if (count <= numberOfShots || numberOfShots == -1){
                float step;
                if (fireRadiusDegrees != 360) {
                    if (bulletsPerRadius != 1) {
                        step = Math::deg_to_rad(fireRadiusDegrees) / (bulletsPerRadius-1);
                    }
                    else {
                        step = 0;
                    }
                }
                else{
                    step = Math::deg_to_rad(fireRadiusDegrees) / (bulletsPerRadius);
                }
                

                if (staysTowardPlayer == true) {
                    fRotation = get_global_position().direction_to(trackedNode->get_global_position()).angle() + Math::deg_to_rad(offsetTowardPlayer);
                }

                //Spawning of individual bullets in the pattern
                for (int radii = 0; radii <= numberOfRadii-1; radii++){
                    for (int iter = 0; iter < bulletsPerRadius; iter++){
                        spawn_bullet_self((((Vector2(1,0).rotated((iter * (step)))).rotated(fRotation)).rotated(radii * Math::deg_to_rad(degreesBetweenRadii))).normalized());//rotates by the step to get the correct placement, then the rotation of the spawner, then factors in the radius
                    }
                }
                timer->start();
                count++;
             }
            else {//If the node has run out of shots, it makes sure that all of the bullets have been disabled before automatically leaving the tree.
                bool stay = false;
                for (int bul = 0; bul < bullets.size(); bul++){
                    if (multi->get_instance_custom_data(bul).r != 0.0){
                        stay = true;
                        break;
                    }
                }
                if (stay == false){
                    queue_free();
                }
            }
        }

        //Setting rotation (NOT DIRECTLY)
        if (get_spin_rate() > maxSpin || get_spin_rate() < minSpin){
            if (restartAtSpin == true){
                spinSign *= -1.0;
            }
            else{
                set_spin_rate(UtilityFunctions::clampf(get_spin_rate(), minSpin, maxSpin));
            }
        }

        float newRotation;
        if (spinRate != 0) {
            set_spin_rate(get_spin_rate() + (spinAcceleration*spinSign) * delta);
        }
        else{
            set_spin_rate(spinAcceleration);
        }
        newRotation = fRotation + get_spin_rate() * delta;
        
        fRotation = fmod(newRotation, 2*Math_PI);

        //The actual movement and collision detection code
        for (int i_internal = 0; i_internal < vis.size(); i_internal++) {
            int i = vis[i_internal];
            Vector2 upos = multi->get_instance_transform_2d(i).get_origin();
            Ref<BulProps> bul = bullets[i];
            float ang;
            Vector2 velocity;

            //Checks if the bullets move indpendently of the player
            if (moveWithParent == false){
                upos += (bul->get_last_increment()-get_global_position());
                bul->set_last_increment(get_global_position());
            }

            if (homing == false) {
                ang = bul->get_direction().angle() + Math::deg_to_rad(textureRotation);
                velocity =  bul->get_direction() * bul->get_speed() * delta;
            }

            else{
                Vector2 homingVector = upos.direction_to(trackedNode->get_global_position()-get_global_position());
                bul->set_direction(bul->get_direction() + (homingVector * (homingWeight/delta))/10);
                velocity =  bul->get_direction() * bul->get_speed() * delta;
                ang = velocity.angle() + Math::deg_to_rad(textureRotation);
            }

            bul->set_direction(Vector2(bul->get_direction().x, bul->get_direction().y + gravity));

            //Multiplying the velocity by 100 so settings can contain less decimals (User experience)
            multi->set_instance_transform_2d(i, Transform2D(ang, (upos + velocity/100)));

            bul->set_position(upos + velocity/100);
            bul->set_lifetime(bul->get_lifetime()+delta);
            bul->set_animation_lifetime(bul->get_animation_lifetime()+delta);
            calc_vel(bul, delta);

            animate(bul, i, delta);

            bul->get_query()->set_transform(Transform2D(ang, to_global((upos + velocity/100))));
            auto result = space_state->intersect_shape(bul->get_query(), bulletType->get_number_of_queries());
            if (!result.is_empty()){
                emit_signal("bullet_hit", result, i, this);
                if (returnBulletsToPoolAutomatically == true){
                    free_bullet_to_pool(i);
                }
            }

            Vector2 toUse = to_global(upos);

            //If the bullet has gone past the killbox or the lifetime is up, make the bullet inactive
            if (boundBox != Rect2()){
                if (!boundBox.has_point(toUse)) {
                    free_bullet_to_pool(i);
                }
            }

            if (bul->get_lifetime() >= bulletType->get_max_lifetime()){
                free_bullet_to_pool(i);
            }
        }
    }
}

//Every frame, calculates the updated velocity of the bullet
void Spawner::calc_vel(Ref<BulProps> bul, float delta){
    if (bul->get_speed() == 0){
        bul->set_speed(bulletType->get_acceleration()*delta);
    }
    float calculated_speed = bul->get_speed() + bulletType->get_acceleration() *delta;
    float clamped = UtilityFunctions::clampf(calculated_speed, bulletType->get_min_speed(), bulletType->get_max_speed());
    bul->set_speed(clamped);
}

//Every frame, moves the custom data around to adjust what the shader reads, moving the UVs to produce aniamtion based on spritesheets
void Spawner::animate(Ref<BulProps> bul, int num, float delta){
    if (bul->get_animation_lifetime() >= bulletType->get_animation_speed()) {
        bul->set_animation_lifetime(0.0);

        Color custom = multi->get_instance_custom_data(num);

        //Checks if there is more to go in the row, and if there is not, move down a column, and if neither, reset to the origional values
        if (custom.g + 1.0 < rowsInAtlas){
            multi->set_instance_custom_data(num, Color(custom.r, custom.g + 1.0, custom.b, custom.a));
        }
        else {
            if (custom.b + 1.0 < columnsInAtlas) {
                multi->set_instance_custom_data(num, Color(custom.r, 0.0, custom.b + 1.0, custom.a));
            }
            else {
                multi->set_instance_custom_data(num, Color(custom.r, 0.0, 0.0, custom.a));
            }
        }
    }
}

//Resets the BulProps and makes it invisible, also erases it from the visible Array
void Spawner::free_bullet_to_pool(int idx){
    multi->set_instance_custom_data(idx, Color(0.0, 0.0, 0.0, 0.0));//Custom data = Color(visible, offsetx, offsety, unused)
    vis.erase(idx);
    Ref<BulProps> bul = bullets[idx];
    bul->set_position(Vector2());
    bul->set_lifetime(0.0);
    bul->set_animation_lifetime(0.0);
    bul->set_direction(Vector2());
    bul->set_speed(0.0);
}

//Clears the Array of visible bullets, then iterates over all of the bullets to turn them all off
void Spawner::clear_all()
{
    vis.clear();
    for (int idx = 0; idx < bullets.size(); idx++) {
        multi->set_instance_custom_data(idx, Color(0.0, 0.0, 0.0, 0.0));//Custom data = Color(visible, offsetx, offsety, unused)
        Ref<BulProps> bul = bullets[idx];
        bul->set_position(Vector2());
        bul->set_lifetime(0.0);
        bul->set_animation_lifetime(0.0);
        bul->set_direction(Vector2());
        bul->set_speed(0.0);
    }
}

Array Spawner::get_active_bullets() const{
    Array exportArr;
    for (int idx = 0; idx < vis.size(); idx++) {
        int i = vis[idx];
        exportArr.append(bullets[i]);
    }
    return exportArr;
}

Ref<BulProps> Spawner::get_bullet_from_index(int idx) const{
    return bullets[idx];
}

//Setter and getter functions for the script
void Spawner::set_bounding_box(Rect2 box)
{
    boundBox = box;
}

void Spawner::set_bullets(Array buls) {
    bullets = buls;
}

Array Spawner::get_bullets() const {
    return bullets;
}

void Spawner::set_fire_rate(float rate) {
    fireRate = rate;
    if (timer != nullptr){
        timer->set_wait_time(fireRate);
    }
}

float Spawner::get_fire_rate() const {
    return fireRate;
}

void Spawner::set_fire_radius_degrees(float degrees) {
    fireRadiusDegrees = degrees;
}

float Spawner::get_fire_radius_degrees() const {
    return fireRadiusDegrees;
}

void Spawner::set_bullets_per_radius(int count) {
    bulletsPerRadius = count;
}

int Spawner::get_bullets_per_radius() const {
    return bulletsPerRadius;
}

void Spawner::set_spin_rate(float sRate) {
    spinRate = sRate;
}

float Spawner::get_spin_rate() const {
    return spinRate;
}

void Spawner::set_bullet_type(Ref<BulletType> type) {
    bulletType = type;
}

Ref<BulletType> Spawner::get_bullet_type() const {
    return bulletType; 
}

void Spawner::set_tracked_node(Node2D* p){
    trackedNode = p;
}
Node2D* Spawner::get_tracked_node() const {
    return trackedNode;
}

void Spawner::set_start(bool st){
    start = st;
}
bool Spawner::get_start() const {
    return start;
}

void Spawner::set_pool_count(int count){
    poolCount = count;
}
int Spawner::get_pool_count() const {
    return poolCount;
}

void Spawner::set_number_of_shots(int num){
    numberOfShots = num;
}
int Spawner::get_number_of_shots() const {
    return numberOfShots;
}

void Spawner::set_texture_rotation(float rot){
    textureRotation = rot;
}
float Spawner::get_texture_rotation() const {
    return textureRotation;
}

void Spawner::set_start_rotation(float rot){
    startRotation = rot;
}
float Spawner::get_start_rotation() const {
    return startRotation;
}

void Spawner::set_random(bool val){
    randomStart = val;
}
bool Spawner::get_random() const {
    return randomStart;
}

void Spawner::set_random_radius(float rad){
    randomRadius = rad;
}
float Spawner::get_random_radius() const {
    return randomRadius;
}

void Spawner::set_number_of_radii(int rad) {
    numberOfRadii = rad;
}

int Spawner::get_number_of_radii() const {
    return numberOfRadii;
}

void Spawner::set_degrees_between_radii(float deg) {
    degreesBetweenRadii = deg;
}

float Spawner::get_degrees_between_radii() const {
    return degreesBetweenRadii;
}

void Spawner::set_max_spin(float max) {
    maxSpin = max;
}

float Spawner::get_max_spin() const {
    return maxSpin;
}

void Spawner::set_min_spin(float min) {
    minSpin = min;
}

float Spawner::get_min_spin() const {
    return minSpin;
}

void Spawner::set_restart_at_spin(bool val) {
    restartAtSpin = val;
}

bool Spawner::get_restart_at_spin() const {
    return restartAtSpin;
}

void Spawner::set_spin_acceleration(float accel) {
    spinAcceleration = accel;
}

float Spawner::get_spin_acceleration() const {
    return spinAcceleration;
}

void Spawner::set_homing(bool value) {
    homing = value;
}

bool Spawner::get_homing() const {
    return homing;
}

void Spawner::set_start_toward_player(bool value) {
    startTowardPlayer = value;
}

bool Spawner::get_start_toward_player() const {
    return startTowardPlayer;
}

void Spawner::set_gravity(float value) {
    gravity = value;
}

float Spawner::get_gravity() const {
    return gravity;
}

void Spawner::set_homing_weight(float weight) {
    homingWeight = weight;
}

float Spawner::get_homing_weight() const {
    return homingWeight;
}

void Spawner::set_offset_toward_player(float off) {
    offsetTowardPlayer = off;
}

float Spawner::get_offset_toward_player() const {
    return offsetTowardPlayer;
}

void Spawner::set_stays_toward_player(bool stay) {
    staysTowardPlayer = stay;
}

bool Spawner::get_stays_toward_player() const {
    return staysTowardPlayer;
}

void Spawner::set_rows_in_atlas(int rows) {
    rowsInAtlas = rows;
}

int Spawner::get_rows_in_atlas() const {
    return rowsInAtlas;
}

void Spawner::set_columns_in_atlas(int columns) {
    columnsInAtlas = columns;
}

int Spawner::get_columns_in_atlas() const {
    return columnsInAtlas;
}

void Spawner::set_return_bullets_to_pool_automatically(bool b) {
    returnBulletsToPoolAutomatically = b;
}

bool Spawner::get_return_bullets_to_pool_automatically() const {
    return returnBulletsToPoolAutomatically;
}

void Spawner::set_id(int id) {
    ID = id;
}

int Spawner::get_id() const {
    return ID;
}

void Spawner::set_move_with_parent(bool move) {
    moveWithParent = move;
}

bool Spawner::get_move_with_parent() const {
    return moveWithParent;
}

void Spawner::set_start_mode(Spawner::StartMode mode) {
    startMode = mode;
}

Spawner::StartMode Spawner::get_start_mode() const {
    return startMode;
}

void Spawner::set_spawner_mode(Spawner::Mode mode) {
    spawnerMode = mode;
}

Spawner::Mode Spawner::get_spawner_mode() const {
    return spawnerMode;
}

void Spawner::set_manual_start(bool b) {
    manualStart = b;
}

bool Spawner::get_manual_start() const {
    return manualStart;
}