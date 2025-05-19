cmake_minimum_required(VERSION 3.30)
project(mota)

set(CMAKE_CXX_STANDARD 23)
include_directories(include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /utf-8")
set(CMAKE_CXX_FLAGS "/utf-8")

set(MAPS_DIR "${CMAKE_SOURCE_DIR}/lib/maps")

set(PICS_DIR "${CMAKE_SOURCE_DIR}/lib/pic")

add_definitions(-DMAPS_DIR="${CMAKE_SOURCE_DIR}/lib/maps")

add_definitions(-DPICS_DIR="${CMAKE_SOURCE_DIR}/lib/pic")

set(EasyX_DIR "${CMAKE_SOURCE_DIR}/EasyX")  # EasyX 目录
include_directories(${EasyX_DIR}/include)  # 头文件路径
link_directories(${EasyX_DIR}/lib/VC2015/x64)  # 库文件路径
link_libraries(EasyXa EasyXw)  # 连接 EasyX 库



add_executable(my_executable scr/main.cpp
        scr/map/Map.cpp
        include/Map.h
        scr/Block/Block.cpp
        include/Block.h
        scr/map/MapLoader.cpp
        include/MapLoader.h
        include/allblocks.h
        scr/Block/terrain/terrain.cpp
        include/terrain.h
        scr/Block/enemy/enemy.cpp
        include/enemy.h
        scr/Player/Player.cpp
        include/Player.h
        scr/canvas/canvas.cpp
        include/Canvas.h
        scr/Game/Game.cpp
        include/Game.h
        scr/Block/item/item.cpp
        include/item.h
        scr/Block/terrain/upstair.cpp
        include/upstair.h
        scr/Block/terrain/downstair.cpp
        include/downstair.h)
