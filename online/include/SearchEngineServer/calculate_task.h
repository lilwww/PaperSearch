
#ifndef __SE_TASK_H__
#define __SE_TASK_H__

#include "../Reactor/tcp_server.hpp"
#include "../KeyRecommander/key_recommander.h"
#include "../WebPageSearcher/web_page_searcher.h"

namespace search_engine {

using MYMAP = unordered_map<std::pair<string, unsigned short>, std::pair<int, vector<string>>>;

class CalculateTask {
public:
    CalculateTask(const string& msg, 
                  const TcpConnectionPtr& con,
                  KeyRecommander& key,
                  WebPageSearcher& web,
                  MYMAP& store)
    : _msg(msg),
      _con(con),
      _key(key),
      _web(web), 
      _Store(store) { }

    void wordSearcher();
    void pageSearcher();
    void nextPageSearcher();
    void process();

private:
    string             _msg;
    TcpConnectionPtr   _con;
    KeyRecommander&    _key;
    WebPageSearcher&   _web;
    MYMAP&             _Store;
};

} // namespace search_engine

#endif // __SE_TASK_H__
