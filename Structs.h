//
// Created by whoami on 2/23/17.
//

#ifndef HASH_CODE_2017_STRUCTS_H
#define HASH_CODE_2017_STRUCTS_H

#include <vector>

struct Cache {
  Cache(int _cache_id, int _latency_to_cache)
      : cache_id(_cache_id),
        latency_to_cache(_latency_to_cache) { }
  int cache_id;
  int latency_to_cache;
};

struct Endpoint {
  Endpoint(int _latency_to_data_center, int _num_caches)
      : latency_to_data_center(_latency_to_data_center),
        num_caches(_num_caches) { }

  int latency_to_data_center;
  int num_caches;
  std::vector<Cache> endpoint_caches;
};

struct Request {

  Request(int _video_id, int _endpoint_id, int _queries)
      : video_id(_video_id),
        endpoint_id(_endpoint_id),
        queries(_queries) { }


  // The id of a requested video
  int video_id;

  // The id of an endpoint where request is coming from
  int endpoint_id;

  // The number of queries for the video from the endpoint
  int queries;
};

// Provided data
struct Data {

  // Initialization method
  void init();

  // Data stores
  std::vector<int> video_sizes;
  std::vector<Endpoint> endpoints;
  std::vector<Request> requests;

  // Sizes of the data stores
  int num_videos;
  int num_endpoints;
  int num_requests;
  int num_caches;
  int cache_capacity;
};

#endif //HASH_CODE_2017_STRUCTS_H
