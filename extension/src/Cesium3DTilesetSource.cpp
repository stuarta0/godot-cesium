#include "Cesium3DTilesetSource.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

void GDCesium3DTilesetSource::_bind_methods() {
    ADD_SIGNAL(MethodInfo("invalidated")); //, PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::STRING, "uri")));
}

GDCesium3DTilesetSource::GDCesium3DTilesetSource() {
    // Noop
}

GDCesium3DTilesetSource::~GDCesium3DTilesetSource() {
	// Add your cleanup here.
}

godot::String GDCesium3DTilesetSource::get_uri() const {
    return "";
}


void GDCesium3DTilesetIonSource::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_asset_id"), &GDCesium3DTilesetIonSource::get_asset_id);
	ClassDB::bind_method(D_METHOD("set_asset_id", "p_asset_id"), &GDCesium3DTilesetIonSource::set_asset_id);
	ClassDB::add_property("GDCesium3DTilesetIonSource", PropertyInfo(Variant::INT, "asset_id"), "set_asset_id", "get_asset_id");

    ClassDB::bind_method(D_METHOD("get_access_token"), &GDCesium3DTilesetIonSource::get_access_token);
	ClassDB::bind_method(D_METHOD("set_access_token", "p_access_token"), &GDCesium3DTilesetIonSource::set_access_token);
	ClassDB::add_property("GDCesium3DTilesetIonSource", PropertyInfo(Variant::STRING, "access_token"), "set_access_token", "get_access_token");

    ClassDB::bind_method(D_METHOD("get_asset_endpoint_uri"), &GDCesium3DTilesetIonSource::get_asset_endpoint_uri);
	ClassDB::bind_method(D_METHOD("set_asset_endpoint_uri", "p_asset_endpoint_uri"), &GDCesium3DTilesetIonSource::set_asset_endpoint_uri);
	ClassDB::add_property("GDCesium3DTilesetIonSource", PropertyInfo(Variant::STRING, "asset_endpoint_uri"), "set_asset_endpoint_uri", "get_asset_endpoint_uri");
}

GDCesium3DTilesetIonSource::GDCesium3DTilesetIonSource() {
	asset_id = 0;
    access_token = "";
    asset_endpoint_uri = "";
}

GDCesium3DTilesetIonSource::~GDCesium3DTilesetIonSource() {
	// Add your cleanup here.
}

String GDCesium3DTilesetIonSource::get_uri() const {
    return asset_endpoint_uri;
}

void GDCesium3DTilesetIonSource::set_asset_id(const int p_asset_id) {
    if (p_asset_id > 0 && p_asset_id != asset_id) {
        asset_id = p_asset_id;
        emit_signal("invalidated"); //, this, get_uri());
    }
}
int GDCesium3DTilesetIonSource::get_asset_id() const {
    return asset_id;
}

void GDCesium3DTilesetIonSource::set_access_token(const String p_access_token) {
    if (access_token != p_access_token) {
        access_token = p_access_token;
        emit_signal("invalidated"); //, this, get_uri());
    }
}
String GDCesium3DTilesetIonSource::get_access_token() const {
    return access_token;
}

void GDCesium3DTilesetIonSource::set_asset_endpoint_uri(const String p_asset_endpoint_uri) {
    if (asset_endpoint_uri != p_asset_endpoint_uri) {
        asset_endpoint_uri = p_asset_endpoint_uri;
        emit_signal("invalidated"); //, this, get_uri());
    }
}
String GDCesium3DTilesetIonSource::get_asset_endpoint_uri() const {
    return asset_endpoint_uri;
}


void GDCesium3DTilesetUriSource::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_custom_uri"), &GDCesium3DTilesetUriSource::get_custom_uri);
	ClassDB::bind_method(D_METHOD("set_custom_uri", "p_custom_uri"), &GDCesium3DTilesetUriSource::set_custom_uri);
	ClassDB::add_property("GDCesium3DTilesetUriSource", PropertyInfo(Variant::STRING, "custom_uri"), "set_custom_uri", "get_custom_uri");
}

GDCesium3DTilesetUriSource::GDCesium3DTilesetUriSource() {
    custom_uri = "";
}

GDCesium3DTilesetUriSource::~GDCesium3DTilesetUriSource() {
	// Add your cleanup here.
}

String GDCesium3DTilesetUriSource::get_uri() const {
    return custom_uri;
}

void GDCesium3DTilesetUriSource::set_custom_uri(const String p_custom_uri) {
    if (custom_uri != p_custom_uri) {
        custom_uri = p_custom_uri;
        emit_signal("invalidated"); //, this, get_uri());
    }
}
String GDCesium3DTilesetUriSource::get_custom_uri() const {
    return custom_uri;
}