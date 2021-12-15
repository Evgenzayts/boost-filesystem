// Copyright 2021 Evgenzayts evgenzaytsev2002@yandex.ru

#include <boost/regex.hpp>
#include <boost/filesystem.hpp>
#include <list>
#include <string>
#include <source.hpp>

void my_func(char* path_to_ftp){
  auto *my_info = new Information;
  my_info->path = path_to_ftp;
  if (my_info->path.empty()) {
    my_info->path = "home/ubuntu/CLionProjects/LABA4/demo";
  }

  const boost::filesystem::path this_path(my_info->path);
  const boost::regex check("balance_(\\d{8})_(\\d{8}).txt");

  boost::filesystem::directory_iterator iter_dir;
  for (boost::filesystem::directory_iterator j( my_info->path);
       j != iter_dir;
       ++j)
  {
    boost::filesystem::directory_iterator iter;
    if (!boost::filesystem::is_regular_file(j->status()))
    {
      for (boost::filesystem::directory_iterator i(j->path());
           i != iter;
           ++i)
      {
        boost::smatch results;
        if ( boost::regex_match(i->path().filename().string(),
                               results,
                               check) ) {
          std::cout << j->path().filename().string()
                    << " "
                    << i->path().filename().string()
                    << std::endl;

          boost::filesystem::ifstream fileHandler(i->path().string());
          std::string line;
          getline(fileHandler, line);
          std::string id = line.substr(2, 8);
          int date = std::stoi(line.substr(11, 8));
          bool flag = true;
          int count = 0;
          for (auto & l : my_info->id) {
            if (l == id) {
              flag = false;
              if (date > my_info->dates[count])
                my_info->dates[count] = date;
              ++my_info->files[count];
            }
            ++count;
          }
          if (flag)
          {
            my_info->id.push_back(id);
            my_info->dates.push_back(date);
            my_info->files.push_back(1);
            my_info->folder.push_back(j->path().filename().string());
          }
        }
      }
    }
  }

  for (size_t i = 0; i < my_info->id.size(); ++i){
    std::cout << "-> broker: " << my_info->folder[i]
              << " account: " << my_info->id[i]
              << " last update: " << my_info->dates[i]
              << " files: " << my_info->files[i] << std::endl;
  }
}
