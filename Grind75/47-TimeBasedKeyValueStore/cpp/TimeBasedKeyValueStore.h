#ifndef TIME_BASED_KEY_VALUE_STORE
#define TIME_BASED_KEY_VALUE_STORE

#include <string>
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>

class TimeMap {
  public:
    TimeMap() {}
    void set(std::string key, std::string value, int timestamp);
    std::string get(std::string key, int timestamp);
    void set2(std::string key, std::string value, int timestamp);
    std::string get2(std::string key, int timestamp);
  private:
    std::unordered_map<std::string, std::map<int, std::string>> timeMap;
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> tm;
};

#endif

