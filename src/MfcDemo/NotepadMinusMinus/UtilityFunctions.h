#pragma once

#include <string>
#include <vector>
#include <atlstr.h>

inline std::string toStdString(const CString& str)
{
  CT2CA pszConvertedString(str);
  return std::string{pszConvertedString};
}

inline CString toCString(const std::string& str)
{
  return CString{str.c_str()};
}

void readLinesFromFile(std::vector<std::string>& lines, const std::string& filename, bool clearVector = true);
void saveToFile(std::vector<std::string>& lines, const std::string& filename);
void saveToFile(CString lines, const std::string& filename);
