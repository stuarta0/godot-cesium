# SPDX-License-Identifier: Unlicense

target_sources( ${PROJECT_NAME}
    PRIVATE
        Cesium3DTileset.h
        Cesium3DTileset.cpp
        Cesium3DTilesetSource.h
        Cesium3DTilesetSource.cpp
        #Example.h
        #Example.cpp
        #GDExtensionTemplate.h
        #GDExtensionTemplate.cpp
        RegisterExtension.cpp
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src"
)
