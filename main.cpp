#include <iostream>
#include <string>
#include <goosepp/goosepp.h>
#include <cpr/cpr.h>


using namespace std;
using scivey::goosepp::GooseExtractor;

int main(){
  string url = "http://https://chrome.googleblog.com/2016/05/the-google-play-store-coming-to.html";

  auto r = cpr::Get(cpr::Url{url},
      cpr::Authentication{"user", "pass"},
      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
  r.header["content-type"]; 


  cout << r.status_code << endl;
}
