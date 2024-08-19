#include <chrono>

namespace Time {

  inline std::chrono::time_point<std::chrono::steady_clock> now() {
    return std::chrono::steady_clock::now();
  }

  inline double elapsed(
      std::chrono::time_point<std::chrono::steady_clock> since) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(now() - since).count() / 1000.0;
  }

}


