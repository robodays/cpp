#include <iostream>
//C:\Users\Zver>cd C:\boost_1_77_0
//C:\boost_1_77_0>bootstrap.bat gcc
#include <boost/asio.hpp>


int main() {
    std::cout << "Hello,";
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
    t.wait();
    std::cout << " World!" << std::endl;



    return 0;
}
