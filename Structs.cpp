//
// Created by whoami on 2/23/17.
//

#include <iostream>
#include "Structs.h"

void Data::init() {

  // Reading initial numbers
  std::cin >> num_videos >> num_endpoints >> num_requests >> num_caches >> cache_capacity;

  // Initialization video_sizes
  video_sizes.reserve(num_videos);

  for (int i = 0; i < num_videos; ++i) {
    int size = 0;
    std::cin >> size;

    // There is no need to add video with size greater than cache_capacity
    if (size > cache_capacity) {
      video_sizes.push_back(size);
    }

  }

  // Initialization endpoints
  endpoints.reserve(num_endpoints);
  for (int i = 0; i < num_endpoints; ++i) {
    int latency_to_data_center = 0, num_caches = 0;
    std::cin >> latency_to_data_center >> num_caches;

    Endpoint endpoint(latency_to_data_center, num_caches);
    endpoint.endpoint_caches.reserve(num_caches);

    for (int j = 0; j < num_caches; ++j) {
      int cache_id = 0, latency_to_cache = 0;
      std::cin >> cache_id >> latency_to_cache;

      Cache cache(cache_id, latency_to_cache);
      endpoint.endpoint_caches.push_back(cache);
    }

  }

  // Initialization requests
  requests.reserve(num_requests);

  for (int i = 0; i < num_requests; ++i) {
    int video_id = 0, endpoint_id = 0, queries = 0;
    std::cin >> video_id >> endpoint_id >> queries;

    requests.push_back(Request(video_id, endpoint_id, queries));
  }

}