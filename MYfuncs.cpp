#include "MYfuncs.h"

size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    FILE* stream = (FILE*)userdata;
    if (!stream) return 0;
    //check if data is written into file
    size_t written = fwrite(ptr, size, nmemb, stream);
    //cout << "Wrote " << written << " bytes to file." << endl;
    return written;

}


//Takes string JSON as string input,parses it and returns the value of an object version
std::string funcs::ret_ver(const string&s)
{
    if (s.empty())
    {
        cerr << "input JSON is empty"<<std::endl;
        return "";
    }
    
    Poco::JSON::Parser parser;
    Poco::Dynamic::Var result = parser.parse(s);
    Poco::JSON::Object::Ptr object = result.extract<Object::Ptr>();
    Poco::Dynamic::Var test = object->get("results");
    if (test.isEmpty()) {
        std::cerr << "results not found in input JSON" << std::endl;
        return "";
    }
    std::string inarr = test.toString();
    if (inarr.empty()) {
        std::cerr << "results value is empty" << std::endl;
        return "";
    }
    Poco::Dynamic::Var rest = parser.parse(inarr);
    Poco::JSON::Array::Ptr arr = rest.extract<Poco::JSON::Array::Ptr>();
    if (arr->size() == 0) {
        std::cerr << "JSON array is empty" << std::endl;
        return "";
    }
    Poco::Dynamic::Var vers = arr->getObject(0);
    std::string version = vers.toString();
    Poco::Dynamic::Var final = parser.parse(version);
    Poco::JSON::Object::Ptr subobject = final.extract<Object::Ptr>();
    Poco::Dynamic::Var appver = subobject->get("version");
    if (appver.isEmpty()) {
        std::cerr << "version not found in subobject" << std::endl;
        return "";
    }
    
    return appver.toString();
    
}


std::int32_t funcs::ret_size(const string& s)
{
    if (s.empty())
    {
        cerr << "input JSON is empty" << std::endl;
        return 0;
    }

    Poco::JSON::Parser parser;
    Poco::Dynamic::Var result = parser.parse(s);
    Poco::JSON::Object::Ptr object = result.extract<Object::Ptr>();
    Poco::Dynamic::Var test = object->get("results");
    if (test.isEmpty()) {
        std::cerr << "results not found in input JSON" << std::endl;
        return 0;
    }
    std::string inarr = test.toString();
    if (inarr.empty()) {
        std::cerr << "results value is empty" << std::endl;
        return 0;
    }
    Poco::Dynamic::Var rest = parser.parse(inarr);
    Poco::JSON::Array::Ptr arr = rest.extract<Poco::JSON::Array::Ptr>();
    if (arr->size() == 0) {
        std::cerr << "JSON array is empty" << std::endl;
        return 0;
    }
    Poco::Dynamic::Var vers = arr->getObject(0);
    std::string version = vers.toString();
    Poco::Dynamic::Var final = parser.parse(version);
    Poco::JSON::Object::Ptr subobject = final.extract<Object::Ptr>();
    Poco::Dynamic::Var appsize = subobject->get("fileSizeBytes");
    if (appsize.isEmpty() ){
        std::cerr << "size not found in subobject" << std::endl;
        return 0;
    }

    std::string asize = appsize.toString();
    int size = stoi(asize);
    return size/1000000;


}





//Takes bundleId of a mac-app as string input and return is JSON(info.plist) using curl and saves it to a path
std::string funcs::get_app_info(const string& bundle_id, const char* filepath) {
    
    string url = "http://itunes.apple.com/lookup?bundleId=" + bundle_id;

    CURL* curl = curl_easy_init();
    if (!curl) {
        cerr <<"Failed to initialize cURL";
        return "";
    }

    char curl_errbuf[CURL_ERROR_SIZE];
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curl_errbuf);

    struct curl_slist* headers = curl_slist_append(NULL, "Accept: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    FILE* fp = nullptr;
    errno_t err = fopen_s(&fp, filepath, "wb");
    if (err != 0 || !fp) {
        cerr <<"Failed to create output file";
        return"";
    }
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        cerr <<curl_errbuf;
        curl_easy_cleanup(curl);
        fclose(fp);
        return "";
    }

    curl_easy_cleanup(curl);
    fclose(fp);
    fp = nullptr;

    //can take out of the function
    ifstream file(filepath);
    ostringstream tmp;
    tmp << file.rdbuf();
    return tmp.str();
}

