#include <iostream>
#include <vector>
using namespace std;

template<class K, class V>
class map {
private:
   vector<pair<K, V>> m_data;
public:
   map(vector<pair<K, V>> mp): m_data(mp) {};
   
   void operator=(vector<pair<K, V>> mp) {
      m_data = mp;
   };

   V& operator[](K& k) {
      for (auto& pr : m_data)
         if (pr.first == k) return pr.second;
   };
};

int main() {
   map<string, int> mp = (vector<pair<string, int>>){make_pair("hello", 1)};
   // unfinished
}
