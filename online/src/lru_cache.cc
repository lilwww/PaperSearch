
#include "../include/LRUCache/lru_cache.h"


namespace search_engine {

int LRUCache::get(string key, vector<string>& value) {
    auto it = _cache.find(key);
    if(it == _cache.end()) {
        return -1;
    } else {
        _nodes.splice(_nodes.begin(), _nodes, it->second);
        value = it->second->value;
        return 0;
    }
}

void LRUCache::put(string key, vector<string> value) {
       auto it = _cache.find(key);
       if (it != _cache.end()) {
            _nodes.splice(_nodes.begin(), _nodes, it->second);
            it->second->value = value;
            return;
       }
        _nodes.emplace_front(CacheNode(key, value));
        _cache[key] = _nodes.begin();
        if (_cache.size() > _capacity){
            _cache.erase(_nodes.back().key);
            _nodes.pop_back();
        }
}

void LRUCache::addRecord(string key, vector<string> val) {
    CacheNode tmp(key, val);
    _pendingUpdateList.push_back(tmp);
}

void LRUCache::mergePending(const LRUCache& lrucache) {
    for(auto& it : lrucache._pendingUpdateList) {
          put(it.key, it.value);
    }
}

void LRUCache::update(const LRUCache& lrucache) {
    for(auto& it : lrucache._cache) {
        string key = it.first;
        vector<string> val = it.second->value;
        put(key, val);
    }
}


} // namespace search_engine
