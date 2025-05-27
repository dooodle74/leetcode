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
        CacheBlock* leftLimit; // two dummy nodes - older than oldest
        CacheBlock* rightLimit; // and newer than newest
    
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            this->currentItems = 0;
            cache.clear();
            this->leftLimit = new CacheBlock(-1, 0);
            this->rightLimit = new CacheBlock(-1, 0);
            leftLimit->newer = rightLimit;
            rightLimit->older = leftLimit;
        }
        
        int get(int key) {
            if (cache.find(key) == cache.end()) return -1; // DNE
            CacheBlock* ans = cache[key];
    
            // this becomes most recently accessed - remove from current LL position
            CacheBlock* olderBlock = ans->older;
            CacheBlock* newerBlock = ans->newer;
            olderBlock->newer = newerBlock;
            newerBlock->older = olderBlock;
    
            // after remove, place at current newest
            CacheBlock* prevNewest = rightLimit->older;
            prevNewest->newer = ans;
            ans->older = prevNewest;
            ans->newer = rightLimit;
            rightLimit->older = ans;
    
            // return value
            return ans->value;
        }
        
        void put(int key, int value) {
            if (cache.find(key) != cache.end()){
                CacheBlock* currCache = cache[key];
                // already exists, remove from linked list
                CacheBlock* olderCache = currCache->older;
                CacheBlock* newerCache = currCache->newer;
                olderCache->newer = newerCache;
                newerCache->older = olderCache;
    
                // remove from map
                cache.erase(key);
    
                // free memory
                currentItems--;
                delete currCache;
            }
    
            // init a new cache with the provided values
            CacheBlock* newCache = new CacheBlock(key, value);
    
            // slot into linked list
            CacheBlock* prevNewest = rightLimit->older;
            prevNewest->newer = newCache;
            newCache->older = prevNewest;
            newCache->newer = rightLimit;
            rightLimit-> older = newCache;
    
            // update hashmap for key
            cache[key] = newCache;
            currentItems++;
            
            if (currentItems > capacity) {
                // remove LRU from linked list
                CacheBlock* prevOldest = leftLimit->newer;
                CacheBlock* newOldest = prevOldest->newer;
                leftLimit->newer = newOldest;
                newOldest->older = leftLimit;
    
                // erase from hashmap
                cache.erase(prevOldest->key);
    
                // free memory
                currentItems--;
                delete prevOldest;
            }
        }
    };
    
