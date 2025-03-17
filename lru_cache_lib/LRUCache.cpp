#include "LRUCache.h"

LRUCache::LRUCache(size_t cap, time_t expiry) : capacity(cap), expiry_time(expiry) {
#ifdef DEBUG_MODE
    std::cout << "LRUCache initialized with capacity of " << cap << " and expiry: " << expiry << std::endl;
#endif
}

// This function adds the entry in the cache
void LRUCache::put(const std::string &filepath) {
    struct stat file_stat;
    if (stat(filepath.c_str(), &file_stat) != 0) return;
    if (cache_map.find(filepath) != cache_map.end()) {
        lru_list.erase(cache_map[filepath]);
    } else if (lru_list.size() >= capacity) {
        cache_map.erase(lru_list.back().filepath);
#ifdef DEBUG_MODE
        std::cout << "Removed " << lru_list.back().filepath << " from the cache." << std::endl;
#endif
        lru_list.pop_back();
    }
    lru_list.push_front({filepath, std::time(nullptr), file_stat});
    cache_map[filepath] = lru_list.begin();
#ifdef DEBUG_MODE
    std::cout << "Added " << filepath << " to the cache." << std::endl;
#endif
}

// This function gets the entry from the cache
FileMetadata* LRUCache::get(const std::string &filepath) {
    if (cache_map.find(filepath) == cache_map.end()) return nullptr;
    lru_list.splice(lru_list.begin(), lru_list, cache_map[filepath]);
    cache_map[filepath] = lru_list.begin();
    return &(*lru_list.begin());
}

void LRUCache::remove(const std::string &filepath) {
    if (cache_map.find(filepath) == cache_map.end()) return;
    lru_list.erase(cache_map[filepath]);
    cache_map.erase(filepath);
#ifdef DEBUG_MODE
        std::cout << "Removed " << filepath << " from the cache." << std::endl;
#endif
}

// This function cleans the stale entries from the cache
void LRUCache::cleanup() {
    time_t now = std::time(nullptr);
    while (!lru_list.empty() && (now - lru_list.back().access_time) > expiry_time) {
        cache_map.erase(lru_list.back().filepath);
        lru_list.pop_back();
    }
#ifdef DEBUG_MODE
    std::cout << "Cache Cleared." << std::endl;
#endif
}