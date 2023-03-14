#include "pch.h"
#include <gtest/gtest.h>
#include "MockClass.h"
#include "SPCurl.h"
#include "MYfuncs.h"

//MockClass mockClass;

//using ::testing::Return;
//using ::testing::AtLeast;

//class MockSPCURL : public SPCurl {
//public:
//	//CURL* curl = curl_easy_init();
//	MOCK_METHOD0(curl_easy_init, CURL* ());
//};

//TEST(MASAPPtest, GetAppInfoTest) {
//	EXPECT_CALL(mockClass, curl_easy_init())
//		.WillOnce(Return(nullptr));
//
//	//MockSPCURL mock_curl;
//	funcs fun;
//	////CURL* curl = curl_easy_init();
//	//EXPECT_CALL(mock_curl, curl_easy_init())
//	//	.WillOnce(Return(nullptr)); // Set the mock's behavior
//
//	//// Call the function being tested
//	std::string app_info = fun.get_app_info("com.yelp.yelpiphone", "output.json");
//
//	//// Check the result of the function
//	EXPECT_EQ(app_info, "");
//}

TEST(MASAPPtest, RetVerEC1) {
	funcs fun;
	std::string ret_val = fun.ret_ver("");
	
	EXPECT_EQ(ret_val,"");
	 
}

TEST(MASAPPtest, RetVerEC2) {
	funcs fun;
	std::string ret_val = fun.ret_ver("{}");

	EXPECT_EQ(ret_val, "");

}

TEST(MASAPPtest, RetVerEC3) {
	funcs fun;
	const char* fp = "try.json";
	ifstream file(fp);
	ostringstream tmp;
	tmp << file.rdbuf();
	std::string ret_val = fun.ret_ver(tmp.str());

	EXPECT_EQ(ret_val, "");

}

TEST(MASAPPtest, RetVerEC4) {
	funcs fun;
	const char* fp = "try2.json";
	ifstream file(fp);
	ostringstream tmp;
	tmp << file.rdbuf();
	std::string ret_val = fun.ret_ver(tmp.str());

	EXPECT_EQ(ret_val, "");

}

TEST(MASAPPtest, RetVerEC5) {
	funcs fun;
	const char* fp = "try3.json";
	ifstream file(fp);
	ostringstream tmp;
	tmp << file.rdbuf();
	std::string ret_val = fun.ret_ver(tmp.str());

	EXPECT_EQ(ret_val, "");

}

TEST(MASAPPtest, RetVerEC6) {
	funcs fun;
	const char* fp = "test.json";
	ifstream file(fp);
	ostringstream tmp;
	tmp << file.rdbuf();
	std::string ret_val = fun.ret_ver(tmp.str());

	EXPECT_EQ(ret_val, "");

}

TEST(MASAPPtest, correct) {
	funcs fun;
	const char* fp = "correct.json";
	ifstream file(fp);
	ostringstream tmp;
	tmp << file.rdbuf();
	std::string ret_val = fun.ret_ver(tmp.str());

	EXPECT_EQ(ret_val, "23.9.1");
}

TEST(MASAPPtest, GetAppInfoEC1) {
	funcs fun;
	const char* fp = "Downloads/doesnotexist";
	std::string ret_val = fun.get_app_info(" ", fp);

	EXPECT_EQ(ret_val, "");
}

TEST(MASAPPtest, GetAppInfoEC2) {
	funcs fun;
	const char* fp = "MASAPP/try.json";
	std::string ret_val = fun.get_app_info(" ", fp);

	EXPECT_EQ(ret_val, "");
}

TEST(MASAPPtest, GetAppInfoEC3) {
	funcs fun;
	const char* fp = "correct.json";
	std::string bid = "com.yelp.yelpiphone";
	std::string ret_val = fun.get_app_info(bid,fp);

	EXPECT_EQ(ret_val, "23.9.1");
}

TEST(MASAPPtest, RetSizeEC1) {
	funcs fun;
	std::int32_t ret_val = fun.ret_size("");

	EXPECT_EQ(ret_val, 0);

}

TEST(MASAPPtest, RetSizeEC2) {
	funcs fun;
	std::int32_t ret_val = fun.ret_size("{}");

	EXPECT_EQ(ret_val, 0);

}

TEST(MASAPPtest, RetSizeEC3) {
	funcs fun;
	const char* fp = "try.json";
	ifstream file(fp);
	ostringstream tmp;
	tmp << file.rdbuf();
	std::int32_t ret_val = fun.ret_size(tmp.str());

	EXPECT_EQ(ret_val, 0);

}

TEST(MASAPPtest, RetSizeEC4) {
	funcs fun;
	const char* fp = "try2.json";
	ifstream file(fp);
	ostringstream tmp;
	tmp << file.rdbuf();
	std::int32_t ret_val = fun.ret_size(tmp.str());

	EXPECT_EQ(ret_val, 0);

}

TEST(MASAPPtest, RetSizeEC5) {
	funcs fun;
	const char* fp = "try3.json";
	ifstream file(fp);
	ostringstream tmp;
	tmp << file.rdbuf();
	std::int32_t ret_val = fun.ret_size(tmp.str());

	EXPECT_EQ(ret_val, 0);

}

TEST(MASAPPtest, RetSizeEC6) {
	funcs fun;
	const char* fp = "test.json";
	ifstream file(fp);
	ostringstream tmp;
	tmp << file.rdbuf();
	std::int32_t ret_val = fun.ret_size(tmp.str());

	EXPECT_EQ(ret_val, 0);

}


TEST(MASAPPtest, corrects) {
	funcs fun;
	const char* fp = "correct.json";
	ifstream file(fp);
	ostringstream tmp;
	tmp << file.rdbuf();
	std::int32_t ret_val = fun.ret_size(tmp.str());

	EXPECT_EQ(ret_val, 296);
}


int main(int argc, char **argv)
{
	return RUN_ALL_TESTS();
}



