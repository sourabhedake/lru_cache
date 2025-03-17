#include <iostream>
#include <string>
#include <fstream>

#include "LRUCache.h"

void createFile(std::string filename) {
    std::ofstream tempFile(filename);
    if (tempFile.is_open()) {
        tempFile << "Temporary file for testing LRU Cache";
        tempFile.close();
    }
}

int main() {

    createFile("/tmp/test1.txt");
    createFile("/tmp/test2.txt");
    createFile("/tmp/test3.txt");
    createFile("/tmp/test4.txt");

    LRUCacheManager manager(3, 60);

    manager.addEntry("/tmp/test1.txt");
    manager.addEntry("/tmp/test2.txt");
    manager.addEntry("/tmp/test3.txt");

    FileMetadata* meta = manager.searchEntry("/tmp/test1.txt");
    if (meta) std::cout << "Found: " << meta->filepath << std::endl;

    manager.addEntry("/tmp/test4.txt");
    meta = manager.searchEntry("/tmp/test1.txt");
    if (!meta) std::cout << "Not Found: /tmp/test1.txt" << std::endl;
    
    manager.cleanOldEntries();

    return 0;
}
