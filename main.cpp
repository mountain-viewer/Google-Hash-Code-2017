#include <iostream>
#include <vector>

#include "Structs.h"

void validate() {
  Data data;
  data.init();

  std::cout << data.num_videos << " " << data.num_endpoints << " " << data.num_requests
      << " " << data.cache_capacity << std::endl;

  for (const auto& elem : data.video_sizes) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  for (const auto& endpoint : data.endpoints) {
    std::cout << endpoint.latency_to_data_center << " " << endpoint.num_caches << std::endl;
    for (const auto& cache : endpoint.endpoint_caches) {
      std::cout << cache.cache_id << " " << cache.latency_to_cache << std::endl;
    }
  }

  for (const auto& request : data.requests) {
    std::cout << request.video_id << " " << request.endpoint_id << " " << request.queries << std::endl;
  }
}

void run() {
  Data data;
}

int main() {
  run();
}