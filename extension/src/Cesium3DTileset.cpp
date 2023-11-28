#include "Cesium3DTileset.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void GDCesium3DTileset::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_source"), &GDCesium3DTileset::get_source);
	ClassDB::bind_method(D_METHOD("set_source", "p_source"), &GDCesium3DTileset::set_source);
	ClassDB::add_property("GDCesium3DTileset", PropertyInfo(Variant::OBJECT, "source", PROPERTY_HINT_RESOURCE_TYPE, "GDCesium3DTilesetIonSource,GDCesium3DTilesetUriSource"), "set_source", "get_source");

	ClassDB::bind_method(D_METHOD("destroy_tileset"), &GDCesium3DTileset::destroy_tileset);
}

GDCesium3DTileset::GDCesium3DTileset() {
	// Initialize any variables here.
}

GDCesium3DTileset::~GDCesium3DTileset() {
	// Add your cleanup here.
}

void GDCesium3DTileset::destroy_tileset() {
	godot::UtilityFunctions::print( "Destory tileset: ", source->call("get_uri") );
}

void GDCesium3DTileset::_process(double delta) {
	//time_passed += delta;
}

void GDCesium3DTileset::set_source(const Ref<Resource> p_source) {
	if (source != p_source) {
		if (source != nullptr) {
			source->disconnect("invalidated", Callable(this, "destroy_tileset"));
		}
		source = p_source;
		p_source->connect("invalidated", Callable(this, "destroy_tileset"));
	}
}

Ref<Resource> GDCesium3DTileset::get_source() const {
    return source;
}
