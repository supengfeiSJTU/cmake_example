#include <iostream>
#include <input/read.h>
// #include "../input/read.h"

int main(int argc, char *argv[])
{
    input::reader reader;
    reader.save_url_data("url.txt");
    reader.post_url_json();
    return 0;
}