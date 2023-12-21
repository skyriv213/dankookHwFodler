#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define MAX_LINE_LENGTH 100

typedef struct {
    int valid;
    int dirty;
    int tag;
    int access_counter;
} CacheBlock;

typedef struct {
    int num_sets;
    int num_blocks_per_set;
    int block_size;
    int write_allocate;
    int write_back;
    char* eviction_policy;
    CacheBlock** cache;
    int access_counter;
    int total_loads;
    int total_stores;
    int load_hits;
    int load_misses;
    int store_hits;
    int store_misses;
    int total_cycles;
} CacheSimulator;

void initializeCache(CacheSimulator* cacheSimulator);
void freeCache(CacheSimulator* cacheSimulator);
int accessMemory(CacheSimulator* cacheSimulator, char operation, char* address) ;
void updateCacheBlock(CacheSimulator* cacheSimulator, int set_index, int block_index, int tag, int valid);
int anyValidBlock(CacheSimulator* cacheSimulator, int set_index);
int findEmptyBlock(CacheSimulator* cacheSimulator, int set_index);
int findLRUBlock(CacheSimulator* cacheSimulator, int set_index);
void printSummary(CacheSimulator* cacheSimulator);
int cacheLookup(CacheSimulator* cacheSimulator, int set_index, int tag);
void handleCacheMiss(CacheSimulator* cacheSimulator, int set_index, int tag);




int main(int argc, char* argv[]) {
    
    if (argc != 7) {
        printf("Usage: ./csim <num_sets> <num_blocks_per_set> <block_size> <write_allocate> <write_back> <eviction_policy>\n");
        exit(1);
    }

    CacheSimulator cacheSimulator;
    cacheSimulator.num_sets = atoi(argv[1]);
    cacheSimulator.num_blocks_per_set = atoi(argv[2]);

    cacheSimulator.block_size = atoi(argv[3]);
    cacheSimulator.write_allocate = strcmp(argv[4], "write-allocate") == 0 ? 1 : 0;
    cacheSimulator.write_back = strcmp(argv[5], "write-back") == 0 ? 1 : 0;
    cacheSimulator.eviction_policy = argv[6];

    initializeCache(&cacheSimulator);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        char operation, address[10];
        sscanf(line, "%c %s", &operation, address);
        accessMemory(&cacheSimulator, operation, address);
    }

    printSummary(&cacheSimulator);

    freeCache(&cacheSimulator);

    return 0;
}


void initializeCache(CacheSimulator* cacheSimulator) {
    cacheSimulator->cache = (CacheBlock**)malloc(cacheSimulator->num_sets * sizeof(CacheBlock*));
    for (int i = 0; i < cacheSimulator->num_sets; i++) {
        cacheSimulator->cache[i] = (CacheBlock*)malloc(cacheSimulator->num_blocks_per_set * sizeof(CacheBlock));
        for (int j = 0; j < cacheSimulator->num_blocks_per_set; j++) {
            cacheSimulator->cache[i][j].valid = 0;
            cacheSimulator->cache[i][j].dirty = 0;
            cacheSimulator->cache[i][j].tag = 0;
            cacheSimulator->cache[i][j].access_counter = 0;
        }
    }
    cacheSimulator->access_counter = 0;
    cacheSimulator->total_loads = 0;
    cacheSimulator->total_stores = 0;
    cacheSimulator->load_hits = 0;
    cacheSimulator->load_misses = 0;
    cacheSimulator->store_hits = 0;
    cacheSimulator->store_misses = 0;
    cacheSimulator->total_cycles = 0;
}

void freeCache(CacheSimulator* cacheSimulator) {
    for (int i = 0; i < cacheSimulator->num_sets; i++) {
        free(cacheSimulator->cache[i]);
    }
    free(cacheSimulator->cache);
}

int accessMemory(CacheSimulator* cacheSimulator, char operation, char* address) {
    cacheSimulator->access_counter++;
    int set_index, tag;
    sscanf(address, "%x", &set_index);
    set_index = (set_index / cacheSimulator->block_size) % cacheSimulator->num_sets;
    sscanf(address, "%x", &tag);

    if (operation == 'l') {
        cacheSimulator->total_loads++;
        int hit, block_index;
        sscanf(address, "%x", &block_index);
        hit = cacheLookup(cacheSimulator, set_index, tag);

        if (hit) {
            cacheSimulator->load_hits++;
            cacheSimulator->total_cycles += 1;
        } else {
            cacheSimulator->total_cycles += 100; // Add 100 cycles for cache miss (memory access)
            cacheSimulator->load_misses++;
            if (cacheSimulator->write_allocate) {
                handleCacheMiss(cacheSimulator, set_index, tag);
            }
        }

        return hit;  // Return 1 for hit, 0 for miss
    } else if (operation == 's') {
        cacheSimulator->total_stores++;
        int hit, block_index;
        sscanf(address, "%x", &block_index);
        hit = cacheLookup(cacheSimulator, set_index, tag);

        if (hit) {
            cacheSimulator->store_hits++;
            cacheSimulator->total_cycles += 1;
        } else {
            cacheSimulator->store_misses++;
            cacheSimulator->total_cycles += 100; // 100 cycles for a cache miss
            if (cacheSimulator->write_allocate) {
                handleCacheMiss(cacheSimulator, set_index, tag);
                cacheSimulator->total_cycles += 1; // Additional cycle for writing to the cache
            }
        }

        return hit;  // Return 1 for hit, 0 for miss
    }

    // If neither 'l' nor 's', you might want to handle this case as well.
    return -1;  // Indicate an error or undefined case
}


void handleCacheMiss(CacheSimulator* cacheSimulator, int set_index, int tag) {
    int block_index = -1;

    // Find a block to evict based on the eviction policy
    if (strcmp(cacheSimulator->eviction_policy, "lru") == 0) {
        block_index = findLRUBlock(cacheSimulator, set_index);
    } else if (strcmp(cacheSimulator->eviction_policy, "fifo") == 0) {
        // Implement FIFO logic
        int oldest_access_counter = INT_MAX;
        for (int i = 0; i < cacheSimulator->num_blocks_per_set; i++) {
            if (cacheSimulator->cache[set_index][i].valid && 
                cacheSimulator->cache[set_index][i].access_counter < oldest_access_counter) {
                oldest_access_counter = cacheSimulator->cache[set_index][i].access_counter;
                block_index = i;
            }
    }
        
    }

    // Handle the eviction
    if (block_index != -1) {
        CacheBlock* block = &cacheSimulator->cache[set_index][block_index];
        if (block->dirty && cacheSimulator->write_back) {
            cacheSimulator->total_cycles += 100; // Add 100 cycles for writing back to memory
            // Write back if necessary
        }
        block->valid = 1;
        block->dirty = (cacheSimulator->write_back && cacheSimulator->write_allocate);
        block->tag = tag;
        block->access_counter = cacheSimulator->access_counter;
    }
}

int cacheLookup(CacheSimulator* cacheSimulator, int set_index, int tag) {
    for (int i = 0; i < cacheSimulator->num_blocks_per_set; i++) {
        CacheBlock* block = &cacheSimulator->cache[set_index][i];
        if (block->valid && block->tag == tag) {
            block->access_counter = cacheSimulator->access_counter; // Update for LRU
            return 1; // Cache hit
        }
    }
    return 0; // Cache miss
}

void updateCacheBlock(CacheSimulator* cacheSimulator, int set_index, int block_index, int tag, int valid) {
    cacheSimulator->cache[set_index][block_index].valid = valid;
    cacheSimulator->cache[set_index][block_index].dirty = 0;
    cacheSimulator->cache[set_index][block_index].tag = tag;
    cacheSimulator->cache[set_index][block_index].access_counter = cacheSimulator->access_counter;
}

int anyValidBlock(CacheSimulator* cacheSimulator, int set_index) {
    for (int i = 0; i < cacheSimulator->num_blocks_per_set; i++) {
        if (cacheSimulator->cache[set_index][i].valid) {
            return 1;
        }
    }
    return 0;
}

int findEmptyBlock(CacheSimulator* cacheSimulator, int set_index) {
    for (int i = 0; i < cacheSimulator->num_blocks_per_set; i++) {
        if (!cacheSimulator->cache[set_index][i].valid) {
            return i;
        }
    }
    return -1;  // Should not happen if anyValidBlock is checked before calling this function
}

int findLRUBlock(CacheSimulator* cacheSimulator, int set_index) {
    int min_access_counter = cacheSimulator->cache[set_index][0].access_counter;
    int min_index = 0;

    for (int i = 1; i < cacheSimulator->num_blocks_per_set; i++) {
        if (cacheSimulator->cache[set_index][i].access_counter < min_access_counter) {
            min_access_counter = cacheSimulator->cache[set_index][i].access_counter;
            min_index = i;
        }
    }

    return min_index;
}

void printSummary(CacheSimulator* cacheSimulator) {
    printf("Total loads: %d\n", cacheSimulator->total_loads);
    printf("Total stores: %d\n", cacheSimulator->total_stores);
    printf("Load hits: %d\n", cacheSimulator->load_hits);
    printf("Load misses: %d\n", cacheSimulator->load_misses);
    printf("Store hits: %d\n", cacheSimulator->store_hits);
    printf("Store misses: %d\n", cacheSimulator->store_misses);
    printf("Total cycles: %d\n", cacheSimulator->total_cycles);
}