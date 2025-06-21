#include "TimeBasedKeyValueStore.h"
#include <string>
#include <utility>

using namespace std;

void TimeMap::set(string key, string value, int timestamp) {
  if (tm.find(key) == tm.end())
    tm[key] = vector<pair<string, int>>();
  tm[key].push_back({value, timestamp});
}

string TimeMap::get(string key, int timestamp) {
  if (tm.find(key) == tm.end())
    return "";
  vector<pair<string, int>> &timestamps = tm[key];
  if (timestamp < timestamps.front().second)
    return "";
  else if (timestamp > timestamps.back().second)
    return timestamps.back().first;
  int left = 0, right = timestamps.size() - 1;
  while (left <= right) {
    int center = (left + right) / 2;
    if (timestamp < timestamps[center].second)
      right = center - 1;
    else if (timestamp > timestamps[center].second)
      left = center + 1;
    else
      return timestamps[center].first;
  }
  return timestamps[right].first;
}

void TimeMap::set2(string key, string value, int timestamp) {
  if (timeMap.find(key) == timeMap.end())
    timeMap[key] = map<int, string>();
  timeMap[key][timestamp] = value;
}

string TimeMap::get2(string key, int timestamp) {
  if (timeMap.find(key) == timeMap.end())
    return "";
  map<int, string>::iterator found = timeMap[key].upper_bound(timestamp);
  if (found == timeMap[key].begin() && timestamp < found->first)
    return "";
  return (--found)->second;
}

