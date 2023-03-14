#include<iostream>
#include "MYfuncs.h"

int main()
{
	funcs fun;
	string Myurl = "http://itunes.apple.com/lookup?bundleId=";
	    string BundleId = "com.yelp.yelpiphone";
	    //cin>>BundleId;
	    Myurl += BundleId;
		string v = fun.get_app_info(BundleId,"info.json");
		string ver = fun.ret_ver(v);
		int size = fun.ret_size(v);
		
		cout <<"LATEST APP VERSION :"<< ver << endl;
		cout << "APP SIZE :" << size <<" Mb";

}