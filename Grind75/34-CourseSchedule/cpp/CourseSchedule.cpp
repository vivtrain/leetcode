#include "CourseSchedule.h"
#include "colors.h"
#include "prettyPrint.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

bool CourseSchedule::canFinish(int numCourses, vector<vector<int>>& prerequisites) {

  const size_t N = numCourses;
  vector<vector<int>> adjacency(N, vector<int>());
  vector<int> inDegree(N, 0);
  for (vector<int> &edge : prerequisites) {
    adjacency[edge[1]].push_back(edge[0]);
    inDegree[edge[0]]++;
  }

  stack<int> dfs;
  for (size_t course = 0; course < N; course++)
    if (inDegree[course] == 0)
      dfs.push(course);

  vector<int> topoSort;

  while (!dfs.empty()) {
    const int prereq = dfs.top();
    topoSort.push_back(prereq);
    dfs.pop();
    for (int course : adjacency[prereq]) {
      inDegree[course]--;
      if (inDegree[course] == 0)
        dfs.push(course);
    }
  }
  prettyPrint(topoSort);
  return topoSort.size() == N;
}
