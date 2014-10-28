# OpenNURBS CMake Build system
# see GNU GENERAL PUBLIC LICENSE, version 2, attached

set(name NURBSurfer)

set(sources
  NURBSurfer.cpp
)

add_executable(${name} ${sources})

install(TARGETS NURBSurfer DESTINATION bin)

