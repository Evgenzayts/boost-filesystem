// Copyright 2021 Evgenzayts evgenzaytsev2002@yandex.ru

#ifndef INCLUDE_SOURCE_HPP_
#define INCLUDE_SOURCE_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>

struct Information {
  std::vector<std::string> id;
  std::vector<int> dates;
  std::vector<int> files;
  std::vector<std::string> folder;
  boost::filesystem::path path;
};

void my_func(char* path_to_ftp);

#endif // INCLUDE_SOURCE_HPP_
