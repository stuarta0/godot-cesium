init:
    cd extension && rm -rf build && cmake -B build -DCMAKE_BUILD_TYPE=Debug

build:
    cd extension && cmake --build build --parallel

run:
    cp extension/build/GDCesium/lib/Darwin-universal/libGDCesium-d.dylib project/bin/
    godot project/project.godot

checkout:
    git submodule update --recursive --remote