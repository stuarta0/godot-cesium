#ifndef CESIUM_3D_TILESET_SOURCE_H
#define CESIUM_3D_TILESET_SOURCE_H

#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/classes/resource.hpp>

namespace godot {

/*
 * Base class for tileset sources.
 */
class GDCesium3DTilesetSource : public Resource {
	GDCLASS(GDCesium3DTilesetSource, Resource)

protected:
    static void _bind_methods();

public:
	GDCesium3DTilesetSource();
	virtual ~GDCesium3DTilesetSource();

    virtual String get_uri() const;
};


/*
 * A tileset source that fetches data from the Cesium Ion platform.
 */
class GDCesium3DTilesetIonSource : public GDCesium3DTilesetSource {
    GDCLASS(GDCesium3DTilesetIonSource, GDCesium3DTilesetSource)

private:
    int asset_id;
    String access_token;
    String asset_endpoint_uri;

protected:
    static void _bind_methods();

public:
    GDCesium3DTilesetIonSource();
    ~GDCesium3DTilesetIonSource();

    virtual String get_uri() const override;

    void set_asset_id(const int p_asset_id);
    int get_asset_id() const;
    void set_access_token(const String p_access_token);
    String get_access_token() const;
    void set_asset_endpoint_uri(const String p_asset_endpoint_uri);
    String get_asset_endpoint_uri() const;
};


/*
 * A tileset source that loads from a custom uri or file: scheme.
 */
class GDCesium3DTilesetUriSource : public GDCesium3DTilesetSource {
    GDCLASS(GDCesium3DTilesetUriSource, GDCesium3DTilesetSource)

private:
    String custom_uri;

protected:
    static void _bind_methods();

public:
    GDCesium3DTilesetUriSource();
    ~GDCesium3DTilesetUriSource();

    virtual String get_uri() const override;

    void set_custom_uri(const String p_custom_uri);
    String get_custom_uri() const;
};

}

#endif