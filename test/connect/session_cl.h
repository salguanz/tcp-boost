#include "tcp_boost.h"

using namespace tcp_boost;
using namespace boost::asio;
using namespace boost::asio::ip;

class session_cl : public session
{
    public:
        static int COUNT;

        session_cl(io_service &ios)
            : session(ios)
        {
            
        }

        void on_created() override
        {
            ++COUNT;
            std::cout << "Current : " + std::to_string(COUNT) + "\n";
        }

        void on_closed() override
        {
            --COUNT;
            std::cout << "Current : " + std::to_string(COUNT) + "\n";
        }
};

int session_cl::COUNT = 0;