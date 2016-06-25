#ifndef INDEX_PAGER_H
#define INDEX_PAGER_H
#include "pager.h"
#include <map>
using namespace std;

class IndexPager : public Pager
{
  map<string, int> WordKey;
  multimap<int, int> fileWords;
public:
  IndexPager();
  void read(istream &is);
  void textString();
};

#endif
