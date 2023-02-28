
#ifndef __SE_PROTOCOL_PARSER__
#define __SE_PROTOCOL_PARSER__

#include <sstream>

/* #include "KeyRecommander/key_recommander.h" */
/* #include "WebPageSearcher/web_page_searcher.h" */

using std::string;
using std::istringstream;

namespace search_engine {

class ProtocolParser {
public:
    ProtocolParser(string msg)
        :_msg(msg) {
            doParser();
        }

    void doParser();

public:
    int    _id;
    string _sought;

private:
    string _msg;
};

void ProtocolParser::doParser() {
    istringstream is(_msg.c_str());
    string s;
    is >> s;
    _id = atoi(s.c_str());
    is >> s;
    _sought = s;
}





} // namespace search_engine

#endif // __SE_PROTOCOL_PARSER__
