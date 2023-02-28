
#ifndef __SE_WEB_PAGE_SEARCHER_H__
#define __SE_WEB_PAGE_SEARCHER_H__

/* #include <string> */
#include "web_page_query.h"
#include "../Reactor/tcp_connection.h"

/* using std::string; */

namespace search_engine {

using TcpConnectionPtr = shared_ptr<TcpConnection>;

class WebPageSearcher {
    friend class CalculateTask;
public:
    /* WebPageSearcher(string keys, const TcpConnection & conn); */
    WebPageSearcher(string keys);
    WebPageSearcher();
    vector<string> doQuery();

    void set_m_val(string sought, TcpConnectionPtr con);

private:
    string             _sought; //查询关键字
    web_page_query *   _pQuery;
    TcpConnectionPtr   _conn;
};

} // namespace search_engine

#endif // __SE_WEB_PAGE_SEARCHER_H__
