#include <fcntl.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

#include <fstream>
#include <iostream>

#include "proto/message.pb.h"

int main(int argc, char const* argv[]) {
  aikido::planner::proto::RRT p;
  google::protobuf::TextFormat::Parser parser;

  if (argc != 2) {
    std::cout << "Please specify a file to load" << std::endl;
    return -1;
  }

  // Method 1: Use TextFormat::Parser directly.
  int fd = open(argv[1], O_RDONLY);
  if (fd < 0) {
    std::cout << "Could not read the file" << std::endl;
    return -1;
  }
  google::protobuf::io::FileInputStream fileInput(fd);

  // The following line errors with system_error.
  std::cout << __LINE__ << std::endl;
  parser.Parse(&fileInput, &p);

  // Print the values read.
  std::cout << p.has_range() << std::endl;
  std::cout << p.range() << std::endl;

  // Method 2: Use via the message. Again system_error.
  std::cout << __LINE__ << std::endl;
  p.ParseFromFileDescriptor(fd);
  std::cout << p.range() << std::endl;
}
