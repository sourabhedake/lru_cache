# LRU Cache Library

## Overview
This project implements an **LRU (Least Recently Used) Cache** in C++. It is a library that keeps track of recently accessed files and removes old entries when the cache is full. It also removes files that have been in the cache for too long.

## How the Algorithm Works
1. When a file is accessed, it is added to the cache.
2. If the file is already in the cache, it moves to the front (most recently used).
3. If the cache is full, the least recently used file (the oldest entry) is removed.
4. The cache also removes old entries based on a time limit.
5. The program uses a **linked list** for fast ordering and a **hash map** for quick lookup.

## How to Build and Run

### *1. Build the Project* **
```sh
mkdir build && cd build
cmake ..
cd
```

## *2. Run the Driver Program* **
```sh
./driver/driver
```

## Features 
- ***Stores file paths, timestamps, and metadata*** (size, inode, etc.)
- ***Automatically removes least recently used files*** when full.
- ***Removes very old files*** based on a time limit.
- ***Optimized using a linked list and hash map***
- **Multi-threading support.**
- **Persistent storage option.**
