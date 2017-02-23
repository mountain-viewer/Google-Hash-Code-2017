#include <iostream>
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



void run() {
  Data data;
  data.init();

  
}

int main() {
  run();
}