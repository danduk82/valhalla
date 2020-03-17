#include <iostream>

#include "baldr/graphreader.h"
#include "baldr/rapidjson_utils.h"
#include <boost/property_tree/ptree.hpp>

#include "loki/worker.h"

int main(int argc, char** argv) {

  if (argc < 2) {
    std::cerr << "Usage: " << std::string(argv[0]) << " conf/valhalla.json" << std::endl;
    return 1;
  }

  // config file
  std::string config_file(argv[1]);
  boost::property_tree::ptree config;
  rapidjson::read_json(config_file, config);

  valhalla::baldr::GraphReader reader(config.get_child("mjolnir"));

  // run the service worker
  valhalla::loki::run_service(config, reader);

  return 0;
}
