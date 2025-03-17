cmake_minimum_required(VERSION 3.10)
project(LRUCacheProject)

option(DEBUG "Enable debug mode" OFF)

add_subdirectory(lru_cache_lib)
add_subdirectory(driver)