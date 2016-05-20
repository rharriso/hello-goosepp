#include <iostream>
#include <string>
#include <goosepp/goosepp.h>
#include <cpr/cpr.h>


using namespace std;
using scivey::goosepp::GooseExtractor;

int main(int argc, char** argv){
  string url = argv[1];
  cout << url << endl;

  auto r = cpr::Get(cpr::Url{url},
                    cpr::Authentication{"user", "pass"},
                    cpr::Parameters{{"anon", "true"}, {"key", "value"}});

  cout << r.status_code << endl;
  cout << r.text << endl;
  cout << r.error.message << endl;

  GooseExtractor extractor{url, r.text};
  cout << extractor.getTitle() << endl;
  cout << extractor.getPublishDate() << endl;
}
