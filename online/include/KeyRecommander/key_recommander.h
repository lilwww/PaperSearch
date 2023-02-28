
#ifndef __SE_KEY_RECOMMANDER_H__
#define __SE_KEY_RECOMMANDER_H__

#include <string>
#include <queue>
#include <memory>

using std::string;
using std::priority_queue;
using std::shared_ptr;

#include "dictionary.h"
#include "../Reactor/tcp_connection.h"

namespace search_engine {
 

class KeyRecommander {
    using TcpConnectionPtr  = shared_ptr<TcpConnection>;
    friend class CalculateTask;

typedef struct CandidateResult {
     string _word;
     int    _freq;
     int    _dist;
} Res;

struct myCompare
{
    bool operator()(const Res& lhs, 
                    const Res& rhs) const;
}; 

public:
    /* KeyRecommander(string word, TcpConnectionPtr conn); */
    KeyRecommander() 
        : _pdict(Dictionary::getInstance()) { }
    
    void set_kr_value(const string& sought, TcpConnectionPtr conn) {
           _sought = sought;
           _conn   = conn;
    }

    vector<string> doQuery();

private:
    void insertPrique(std::pair<string,int> & elem ,Res & myResult);
    void initFinalResult(vector<string> & finalResult);
    void eraseFinalResult(vector<string> & finalResult);
private:
    string                                        _sought;
    priority_queue<Res, vector<Res>, myCompare>   _prique;
    TcpConnectionPtr                              _conn;
    Dictionary*                                   _pdict;
};




} // namespace search_engine

#endif // __SE_KEY_RECOMMANDER_H__
