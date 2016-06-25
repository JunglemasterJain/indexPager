#include "indexpager.h"
#include <sstream>
#include <algorithm>

IndexPager::IndexPager() : Pager()
{
}

void IndexPager::read(istream &is)
{
  string s,i; int key = 0, line = 0;
  stringstream ss;
  ss  << is.rdbuf();
  s = ss.str();
  
  for(string::iterator it = s.begin(); it != s.end(); it++)
  {
    if(isalpha(*it))
      i += *it;
    else
    {
      WordKey.insert(pair<string, int>(i, key));
      fileWords.insert(pair<int, int>(key, line));
      key++;
      if(*it == '\n')
        line++;
      i = "";
    }
  }

  textString(); 
}

// NEXT STEP: SORT THE MULTIMAP ACCORDING TO THE STRINGS IN MAP

void IndexPager::textString()
{
  string s; int consec = 0;
  multimap<int, int>::iterator mmit;
  for(map<string, int >::iterator it = WordKey.begin(); it != WordKey.end(); it++)
  {
    s = it->first;
    for(mmit = fileWords.find(it->second); mmit->first == it->second; mmit++)
    {
      s += " ";
      s += intToString(mmit->second);
      s += ",";
    } 
    s += " ";
    s += intToString(mmit->second);
    s += ".";
    text.push_back(s);
  } 
}
