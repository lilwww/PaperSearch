
#ifndef __SE_CACHE_MANAGER_H__
#define __SE_CACHE_MANAGER_H__

#include "lru_cache.h"
#include "../disallow_copy_assign.h"

#include <iostream>

namespace search_engine {

//单例
class CacheManager {
public:
    ~CacheManager() {
        if (pInstance) {
            delete pInstance;
            pInstance = nullptr;
        }
    }
    static CacheManager* getInstance();

    void init(const string& filename);   
    LRUCache& getCache(string);
    LRUCache& getCache2(string);

    void updateCache(); 
    void updateCache2(); 


private:
    explicit CacheManager();

private:
    DISALLOW_COPY_AND_ASSIGN(CacheManager);

    static CacheManager*   pInstance;
    vector<LRUCache>       _caches;
    vector<LRUCache>       _caches2;
};

} // namespace search_engine

#endif // __SE_CACHE_MANAGER_H__
