#ifndef READ_H
#define READ_H
#include <vector>
namespace input
{
    class reader
    {
    public:
        void read_age();
        void print_age();
        void gen_crc();
        void save_url_data(char *filename);
        void post_url_json();

    private:
        int32_t age_[11] = {};
        int count_ = 0;
    };
}

#endif