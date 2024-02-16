# Cesium for Godot

*100% WIP. Currently targeting Godot 4.1.*

Cesium for Godot brings the 3D geospatial ecosystem to Godot Engine. By combining a high-accuracy full-scale WGS84 globe, open APIs and open standards for spatial indexing such as 3D Tiles, and cloud-based real-world content from Cesium ion with Godot Engine, this project enables a new era of 3D geospatial software.

Other Cesium projects include:

- https://github.com/CesiumGS/cesium-unreal/
- https://github.com/CesiumGS/cesium-unity/

## Project Goals

The project will borrow heavily from the approach taken in the Cesium for Unreal plugin, adapting the concepts to Godot's scenes, nodes and resources.

## Feature Roadmap

### MVP

- Support Cesium3DTileset
  - Requires CesiumGltf conversion to Godot Mesh (derive from [cesium-unreal/CesiumGltfComponent](https://github.com/CesiumGS/cesium-unreal/blob/main/Source/CesiumRuntime/Private/CesiumGltfComponent.cpp) and [godot/GLTFDocument](https://github.com/godotengine/godot/blob/master/modules/gltf/gltf_document.h)), and all relevant dependencies like textures, materials, normal/tangent calculation, etc.
  - Requires tiles to be loaded, possibly inherited from MeshInstance node, with the converted CesiumGltf as Mesh data. Also requires editor behaviour to load tiles as hidden nodes to avoid polluting the scene node tree.
  - Include two resources for data source: CesiumTilesetUrlSource and CesiumTilesetIonSource. Provide bare minimum for Cesium Ion functionality, as any deeper integration into that platform could be provided by Cesium themselves.
- CesiumGeoreference to anchor Cesium3DTileset to a specific location. 
  - cesium-unreal relies heavily on a "Place origin here" button on the georef object to quickly align and reorient the center of the scene to the devs viewport. I assume this hammer is required for Godot too.
- Investigate the need for a custom cesium camera or other georeferenced node3d behaviour for MVP.

Also note, Godot uses 32-bit float by default, but the engine can be recompiled to use 64-bit doubles. The aim would be to use the pre-compiled engine if possible. We could use `real_t` and provide a single- and double-precision version of the GDExtension as [described in the docs](https://docs.godotengine.org/en/stable/tutorials/physics/large_world_coordinates.html).

It looks like Cesium acknowledge that the curvature of the earth affects the scene the further you travel from the origin (e.g. physics gravity direction becomes worse, environment horizon is incorrect), so they simply recommend staying within a hundred clicks of the origin.

### Stage 2

- If a custom camera and/or georeferenced node3d wasn't required for MVP, add it now.
- For environment lighting, we could do the same thing as Unreal where a custom component is provided to drive the environment (e.g. CesiumSkyMaterial that inherits from PhysicalSkyMaterial). Or we could expose the relevant properties and let the dev wire up the values to an existing WorldEnvironment + PhysicalSkyMaterial (or third-party env/sky system). e.g. expose a sun angle/azimuth that could be wired up to a PhysicalSkyMaterial (and NightSky material) + Directional Light rather than coding a separate Cesium Sun/Sky component like cesium-unreal.