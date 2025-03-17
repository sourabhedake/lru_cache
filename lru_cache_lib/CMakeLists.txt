cmake_minimum_required(VERSION 3.10)
project(LRUCacheLibrary)

set(CMAKE_CXX_STANDARD 17)

add_library(lru_cache SHARED LRUCache.cpp)
target_include_directories(lru_cache PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(DEBUG)
    target_compile_definitions(lru_cache PRIVATE DEBUG_MODE)
endif()