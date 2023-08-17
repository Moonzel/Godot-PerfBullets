#include "register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "spawner.h"
#include "bullet_type.h"
#include "bulProps.h"

using namespace godot;

void initialize_spawner_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	
	ClassDB::register_class<Spawner>();
	ClassDB::register_class<BulletType>();
	ClassDB::register_class<BulProps>();
}

void uninitialize_spawner_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT spawner_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_spawner_module);
	init_obj.register_terminator(uninitialize_spawner_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}