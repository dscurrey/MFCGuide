#include "stdafx.h"

#include "UtilityFunctions.h"
#include <fstream>

void readLinesFromFile(std::vector<std::string>& lines, const std::string& filename, bool clearVector)
{
  std::ifstream file;
  file.open(filename);
  if (clearVector) lines.clear();
  if (file)
  {
    std::string line;
    while (std::getline(file, line))
    {
      lines.push_back(line);
    }
  }
}
