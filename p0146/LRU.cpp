// LeetCode 146 - LRU Cache
using namespace std;
#include <unordered_map>

// represents one "block" of cache, as bidirectional linked list
class CacheBlock {
    public:
        int key;
        int value;
        CacheBlock* older; // ptr to backward in list
        CacheBlock* newer; // ptr to forward in list
    
        // init a cache item
        CacheBlock(int key, int value){
            this->key = key;
            this->value = value;
            this->older = nullptr;
            this->newer = nullptr;
        }
};
    
class LRUCache {
    private:
        int capacity;
        int currentItems; // count
        unordered_map<int, CacheBlock*> cache; // map for constant access
        CacheBlock* oldDummy; // two dummy nodes - older than oldest
        CacheBlock* newDummy; // and newer than newest

        // remove a block from the linked list
        void removeFromLinkedList(CacheBlock* block) {
            CacheBlock* olderBlock = block->older;
            CacheBlock* newerBlock = block->newer;
            olderBlock->newer = newerBlock;
            newerBlock->older = olderBlock;
        }

        // insert a block at the end of the linked list (newest)
        void insertInLinkedList(CacheBlock* block) {
            CacheBlock* prevNewest = newDummy->older;
            prevNewest->newer = block;
            block->older = prevNewest;
            block->newer = newDummy;
            newDummy->older = block;
        }
        
        // move a block to the end of the linked list (remove and insert)
        void moveToNewest(CacheBlock* block) {
            removeFromLinkedList(block);
            insertInLinkedList(block);
        }

        // completely remove a block: from the linked list, hashmap and free memory
        void removeBlock(CacheBlock* block) {
            removeFromLinkedList(block);
            cache.erase(block->key);
            delete block;
            currentItems--;
        }

        // add a completedly new block to the cache (insert in linked list and hashmap)
        void addNewBlock(int key, int value) {
            CacheBlock* newCache = new CacheBlock(key, value);
            insertInLinkedList(newCache);
            cache[key] = newCache;
            currentItems++;
        }
    
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            this->currentItems = 0;
            cache.clear();
            this->oldDummy = new CacheBlock(-1, 0);
            this->newDummy = new CacheBlock(-1, 0);
            oldDummy->newer = newDummy;
            newDummy->older = oldDummy;
        }
        
        int get(int key) {
            if (cache.find(key) == cache.end()) return -1; // DNE
            CacheBlock* ansBlock = cache[key];
            moveToNewest(ansBlock);
            return ansBlock->value;
        }
        
        void put(int key, int value) {
            // if the key already exists, update it and move to newest
            if (cache.find(key) != cache.end()){
                CacheBlock* currBlock = cache[key];
                currBlock->value = value; // update value
                moveToNewest(currBlock);
                return;
            }
    
            // check if need evicting, then init new block 
            if (currentItems >= capacity) {
                CacheBlock* prevOldest = oldDummy->newer;
                removeBlock(prevOldest);
            }
            addNewBlock(key, value);
        }
};
    
