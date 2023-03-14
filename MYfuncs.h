#pragma once
#ifndef MYFUNCS_H
#define MYFUNCS_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>

#include <Poco/JSON/Array.h>
#include <curl/curl.h>

using namespace std;
using namespace Poco::JSON;
using namespace Poco::Dynamic;

class __declspec(dllexport) funcs {

public:
   std::string ret_ver(const string& s);
   std::int32_t ret_size(const string& s);
   std::string get_app_info(const string& bundle_id, const char* filepath);
};



//std::string ret_ver(std::string s)
//{
//Poco::JSON::Parser parser;
//Poco::Dynamic::Var result = parser.parse(s);
//Poco::JSON::Object::Ptr object = result.extract<Object::Ptr>();
////can take string instead of D-var
//Poco::Dynamic::Var test = object->get("results");
//std::string inarr = test.toString();
////cout << inarr<<"end";
//
//Poco::Dynamic::Var rest = parser.parse(inarr);
//Poco::JSON::Array::Ptr arr = rest.extract<Poco::JSON::Array::Ptr>();
//Poco::Dynamic::Var vers = arr->getObject(0);
////cout << vers.toString();
//std::string version = vers.toString();
//Poco::Dynamic::Var final = parser.parse(version);
//Poco::JSON::Object::Ptr subobject = final.extract<Object::Ptr>();
//Poco::Dynamic::Var appver = subobject->get("version");
////cout << '\n' << "LATEST VERSION :" << appver.toString();
//string ans = appver.toString();
//return ans;
//}
//
//std::string get_app_info(const string& bundle_id) {
//    string url = "http://itunes.apple.com/lookup?bundleId=" + bundle_id;
//
//    CURL* curl = curl_easy_init();
//    if (!curl) {
//        throw std::runtime_error("Failed to initialize cURL");
//    }
//
//    char curl_errbuf[CURL_ERROR_SIZE];
//    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curl_errbuf);
//
//    struct curl_slist* headers = curl_slist_append(NULL, "Accept: application/json");
//    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
//
//    FILE* fp = nullptr;
//    errno_t err = fopen_s(&fp, "info.json", "wb");
//    if (err != 0 || !fp) {
//        throw std::runtime_error("Failed to create output file");
//    }
//    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
//    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
//    CURLcode res = curl_easy_perform(curl);
//    if (res != CURLE_OK) {
//        throw std::runtime_error(curl_errbuf);
//    }
//
//    curl_easy_cleanup(curl);
//    fclose(fp);
//
//    ifstream file("info.json");
//    ostringstream tmp;
//    tmp << file.rdbuf();
//    string s = tmp.str();
//
//    return ret_ver(s);
//}



#endif 
