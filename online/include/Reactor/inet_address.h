
#ifndef __SE_INET_ADDRESS_H__
#define __SE_INET_ADDRESS_H__

#include <arpa/inet.h>

#include <string>

using std::string;

namespace search_engine {

class InetAddress {
public:
    InetAddress(const string& ip, unsigned short port);
    InetAddress(const struct sockaddr_in &);
    ~InetAddress() = default;

    // 网络地址 -> "."隔字符串格式
    string ip() const {        
        return string(inet_ntoa(_servAddr.sin_addr)); 
    }

    unsigned short port() const {
        return _servAddr.sin_port;
    }

    struct sockaddr_in* get_inet_address_ptr() {
        return &_servAddr;
    }

private:
    struct sockaddr_in   _servAddr; 
};

} // namespace search_engine

#endif // __INET_ADDRESS_H__
