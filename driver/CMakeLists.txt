cmake_minimum_required(VERSION 3.10)
project(LRUCacheDriver)

set(CMAKE_CXX_STANDARD 17)

add_executable(driver program.cpp)
target_link_libraries(driver PRIVATE lru_cache)
target_include_directories(driver PRIVATE ${CMAKE_SOURCE_DIR}/lru_cache_lib)
