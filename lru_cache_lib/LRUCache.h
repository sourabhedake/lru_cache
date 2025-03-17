#include <iostream>
#include <unordered_map>
#include <list>
#include <sys/stat.h>
#include <ctime>

struct FileMetadata {
    std::string filepath;
    time_t access_time;
    struct stat file_stat;
};

class LRUCache {
private:
    size_t capacity;
    std::list<FileMetadata> lru_list;
    std::unordered_map<std::string, std::list<FileMetadata>::iterator> cache_map;
    time_t expiry_time;

public:
    LRUCache(size_t cap, time_t expiry);
    
    void put(const std::string &filepath);
    FileMetadata* get(const std::string &filepath);
    void remove(const std::string &filepath);
    void cleanup();
};

class LRUCacheManager {
private:
    LRUCache cache;
public:
    LRUCacheManager(size_t cap, time_t expiry) : cache(cap, expiry) {}
    void addEntry(const std::string &filepath) { cache.put(filepath); }
    FileMetadata* searchEntry(const std::string &filepath) { return cache.get(filepath); }
    void removeEntry(const std::string &filepath) { cache.remove(filepath); }
    void cleanOldEntries() { cache.cleanup(); }
};