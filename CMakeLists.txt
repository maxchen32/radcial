PROJECT(radical)
FILE(REMOVE_RECURSE build)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/cache)
ADD_SUBDIRECTORY(gc)
#ADD_SUBDIRECTORY(src)
INCLUDE_DIRECTORIES(include)
SET(SRC src/radical.c src/fraction.c)
ADD_LIBRARY(radical_nogc STATIC ${SRC})

# Merge library
if (APPLE)
    add_custom_command(OUTPUT libradical.a
    COMMAND libtool -static -o libradical.a $<TARGET_FILE:gc-lib> $<TARGET_FILE:radical_nogc>
    DEPENDS gc radical_nogc)
else()
    add_custom_command(OUTPUT libradical.a
    COMMAND ar crsT libradical.a $<TARGET_FILE:gc-lib> $<TARGET_FILE:radical_nogc>
    DEPENDS gc radical_nogc)
endif()
add_custom_target(_radical ALL DEPENDS libradical.a)

#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_library(radical STATIC IMPORTED GLOBAL)
set_target_properties(radical PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/libradical.a
)

add_executable(eyyc examples/eyyc.c)
TARGET_LINK_LIBRARIES(eyyc radical)

add_executable(sin-cos examples/sin-cos.c)
TARGET_LINK_LIBRARIES(sin-cos radical)

add_executable(xyline examples/xyline.c)
TARGET_LINK_LIBRARIES(xyline radical)