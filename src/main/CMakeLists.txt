# OpenNURBS CMake Build system
# see GNU GENERAL PUBLIC LICENSE, version 2, attached

set(name NURBSurfer)

SET (OPENNURBS_DIR ${PROJECT_SOURCE_DIR}/OpenNURBS/src)

set(sources
  ${OPENNURBS_DIR}/geom_defs/gCurve.hpp
  ${OPENNURBS_DIR}/geom_defs/gPoint.hpp
  NURBSurfer.cpp
)

add_executable(${name} ${sources})

target_link_libraries (${name} LINK_PUBLIC OpenNURBS)
install(TARGETS NURBSurfer DESTINATION bin)

