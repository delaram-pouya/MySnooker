cmake_minimum_required(VERSION 3.2)
project(SFMLPong)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp headers/game.h sources/game.cpp headers/ball.h sources/ball.cpp headers/renderer.h sources/resource.cpp headers/resource.h sources/network.cpp headers/network.h sources/udp.cpp headers/udp.h)
add_executable(SFMLPong ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFMLPong ${SFML_LIBRARIES} -lpthread)
endif()
