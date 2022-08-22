PROJECT(radical)
FILE(REMOVE_RECURSE build)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/cache)
ADD_SUBDIRECTORY(gc)
#ADD_SUBDIRECTORY(src)
INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(gc/include)
SET(SRC src/radical.c src/fraction.c)
ADD_LIBRARY(radical_nogc STATIC ${SRC})

# Merge library
add_custom_target(combine ALL)
if (APPLE)
	add_custom_command(TARGET combine
	BYPRODUCTS libradical.a
    COMMAND libtool -static -o libradical.a $<TARGET_FILE:gc-lib> $<TARGET_FILE:radical_nogc>
    DEPENDS gc radical_nogc)
else()
	add_custom_command(TARGET combine
	BYPRODUCTS libradical.a
    COMMAND ar crsT libradical.a $<TARGET_FILE:gc-lib> $<TARGET_FILE:radical_nogc>
    DEPENDS gc radical_nogc)
endif()
#add_custom_target(combine ALL DEPENDS libradical.a)

#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_library(radical STATIC IMPORTED GLOBAL)
add_dependencies(radical combine)
set_target_properties(radical PROPERTIES
    IMPORTED_LOCATION libradical.a
)

add_executable(eyyc examples/eyyc.c)
TARGET_LINK_LIBRARIES(eyyc radical)

add_executable(sin-cos examples/sin-cos.c)
TARGET_LINK_LIBRARIES(sin-cos radical)

add_executable(xyline examples/xyline.c)
TARGET_LINK_LIBRARIES(xyline radical)

if(NOT WIN32)
FIND_LIBRARY(sys_math m /usr/lib/)
TARGET_LINK_LIBRARIES(eyyc ${sys_math})
TARGET_LINK_LIBRARIES(sin-cos ${sys_math})
TARGET_LINK_LIBRARIES(xyline ${sys_math})
endif()


