#ifndef CESIUM_3D_TILESET_H
#define CESIUM_3D_TILESET_H

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/resource.hpp>

//#include <Cesium3DTilesSelection/Tileset.h>


namespace godot {


class GDCesium3DTileset : public Node3D {
	GDCLASS(GDCesium3DTileset, Node3D)

private:
    Ref<Resource> source;
    //Cesium3DTilesSelection::Tileset tileset;

    void destroy_tileset();

protected:
	static void _bind_methods();

public:
	GDCesium3DTileset();
	~GDCesium3DTileset();

	void _process(double delta) override;

    void set_source(const Ref<Resource> p_source);
    Ref<Resource> get_source() const;
};

}

#endif
