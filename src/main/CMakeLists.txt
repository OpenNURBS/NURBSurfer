# OpenNURBS CMake Build system
# see GNU GENERAL PUBLIC LICENSE, version 2, attached

set(name NURBSurfer)

SET (OPENNURBS_DIR ${PROJECT_SOURCE_DIR}/OpenNURBS/src)

set(sources
  ${OPENNURBS_DIR}/geom_defs/gCurve.hpp
  ${OPENNURBS_DIR}/geom_defs/gPoint.hpp
  NURBSurfer.cpp
)

INCLUDE(FindPkgConfig)

find_package(GLUT REQUIRED)
if (GLUT_FOUND)
   MESSAGE("Glut Found")
   MESSAGE("Glut Include Dir: ${GLUT_INCLUDE_DIR}")
else (GLUT_FOUND)
   MESSAGE("Glut package missing")
endif (GLUT_FOUND)

find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
   MESSAGE("OpenGL Found")
   MESSAGE("OpenGL Include Dir: ${OPENGL_INCLUDE_DIR}")
else (OPENGL_FOUND)
   MESSAGE("OpenGL environment missing")
endif (OPENGL_FOUND)


PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

add_executable(${name} ${sources})

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${name} LINK_PUBLIC ${SDL2_LIBRARIES} ${SDL2MAIN_LIBRARY} ${OPENGL_LIBRARY} ${GLUT_LIBRARIES} ${SDL2IMAGE_LIBRARIES} 
                      OpenNURBS dl m)

install(TARGETS ${name} DESTINATION bin)

