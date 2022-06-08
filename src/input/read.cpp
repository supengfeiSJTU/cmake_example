#include <iostream>
#include <fstream>
#include <boost/crc.hpp>
#include <boost/uuid/random_generator.hpp>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "read.h"
namespace input
{
    void reader::read_age()
    {
        std::ifstream ifs;
        ifs.open("age.txt", std::ios::in);

        if (!ifs.is_open())
        {
            std::cout << "read fail." << std::endl;
        }
        int age = 0;
        while (ifs >> age && count_ < 10)
        {
            age_[count_] = age;
            count_++;
        }
        ifs.close();
        return;
    }
    void reader::print_age()
    {
        for (int i = 0; i < 11; i++)
        {
            std::cout << age_[i] << std::endl;
        }
    }
    void reader::gen_crc()
    {
        boost::crc_32_type crc;
        crc.process_bytes(age_, count_ * 4);
        age_[count_] = crc.checksum();
        auto uuid = boost::uuids::random_generator();
        return;
    }
    void reader::save_url_data(char *filename)
    {
        FILE *fp;
        if ((fp = fopen(filename, "w")) == NULL)
        {
            std::cout << "open file fail" << std::endl;
            return;
        }
        CURL *curl;
        curl = curl_easy_init();
        if (curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_easy_setopt(curl, CURLOPT_HEADERDATA, fp);
            res = curl_easy_perform(curl);
            if (res != 0)
            {
                std::cout << "get url fail" << std::endl;
            }
            curl_easy_cleanup(curl);
        }
        fclose(fp);
    }
    void reader::post_url_json()
    {
        CURL *curl;
        CURLcode res;
        curl = curl_easy_init();
        Json::Value root;
        root["post_json"] = "json";
        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, root.toStyledString().c_str());
            curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
    }
}
