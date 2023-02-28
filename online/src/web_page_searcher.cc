
#include "../include/WebPageSearcher/web_page_searcher.h"


/* #include "../include/WebPageSearcher/web_page_query.h" */
namespace search_engine {


/* WebPageSearcher::WebPageSearcher(string key, const TcpConnection & conn) */
/*     : _sought(key) */
/* { */
/*     /1* _conn = conn; *1/ */
/* } */
void WebPageSearcher::set_m_val(string sought, TcpConnectionPtr con) {
    _sought = sought;
    _conn = con;
}

WebPageSearcher::WebPageSearcher()
    : _pQuery(web_page_query::get_Web_Query_ptr()) {}

WebPageSearcher::WebPageSearcher(string key)
   : _sought(key)
{
    _pQuery = web_page_query::get_Web_Query_ptr();
    /* _conn = conn; */
}
vector<string> WebPageSearcher::doQuery() {
    cout<<"Web Query"<<_sought<<"\n";
    vector<string> result = _pQuery->doQuery(_sought);
    return result;
}



} // namespace search_engine
