// Copyright 2021 Evgenzayts evgenzaytsev2002@yandex.ru

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <vector>

struct Information {
  std::vector<std::string> id;
  std::vector<int> dates;
  std::vector<int> files;
  std::vector<std::string> folder;
  std::string path;
};

void my_func(char* path_to_ftp);

#endif // INCLUDE_HEADER_HPP_
