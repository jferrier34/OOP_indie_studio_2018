cmake_minimum_required (VERSION 3.0)

project (cpp_indie_studio)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g")

include_directories (./lib/include
  include)

link_directories (./lib/)

set (IRRLICHT_LIBRARY
  -L./lib/
  -lIrrlicht
  -lGL
  -lXext
  -lX11
  -lXxf86vm
  -lIrrKlang
  )

file (GLOB SRCS src/*.cpp)
file (GLOB HDRS inc/*.hpp)
file (GLOB LIBHDRS lib/include/*)

add_executable (bomberman
  ${SRCS}
  ${HDRS})

target_link_libraries (bomberman
  ${IRRLICHT_LIBRARY})

install (TARGETS bomberman DESTINATION bin/)
install (FILES ${LIBHDRS} DESTINATION include/)
install (FILES ./lib/libIrrlicht.a DESTINATION lib/)
install (FILES ./lib/libGL.so DESTINATION lib64/)
install (FILES ./lib/libXext.so DESTINATION lib64/)
install (FILES ./lib/libX11.so DESTINATION lib64/)
install (FILES ./lib/libXxf86vm.so DESTINATION lib64/)
install (FILES ./lib/libIrrKlang.so DESTINATION lib64/)
install (FILES ./lib/ikpFlac.so DESTINATION lib64/)
install (FILES ./lib/ikpMP3.so DESTINATION lib64/)