#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>



class MemBuf {
public:
    MemBuf(size_t n = 10) :
        buff_(n),
        pos_(0),
        n_(0),
        size_(n)
    {}


    int
    read(int8_t * buff, size_t len)
    {
        int n = n_;
        if (n_ <= 0) {
            pos_ = 0;
            n = ::read(0, &buff_[0], size_);

            if (n < 0) {
                std::cout<<"error\n";
                return -1;
            }
            else if (n == 0) {
                std::cout<<"eof\n";
                return 0;
            }

            n_ = n;
        }

        len = (int)len > n ? n : len;

        memcpy(buff, &buff_[pos_], len);
        n_ -= len;
        pos_ += len;

        return len;
    }


private:
    std::vector<int8_t> buff_;
    size_t pos_;
    size_t n_;
    size_t size_;
}; // class MemBuf;


MemBuf m;


std::string
readline()
{
    char c;
    std::string res;
    int n;
    for (;;) {
        n = m.read((int8_t *)&c, 1);
        if (n == 1) {
            res.push_back(c);
            if (c == ';') {
                break;
            }
        }
        else {
            std::cout<<n<<std::endl;
            break;
        }
    }

    return res;
}



int
main(int argc, char *argv[])
{
    for (;;) {
        std::string res = readline();
        if (res == "exit;") {
            break;
        }
        std::cout<<"[ from write: ]"<<res<<std::endl;
    }

    exit(EXIT_SUCCESS);
}
