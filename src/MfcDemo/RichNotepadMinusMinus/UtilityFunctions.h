#pragma once

#include <string>
#include <atlstr.h>
#include <vector>

inline std::string ToStdString(const CString& str)
{
  CT2CA pszConvertedString(str);
  return std::string{pszConvertedString};
}

inline CString ToCString(const std::string& str) 
{
  return CString{str.c_str()};
}

void ReadLinesFromFile(std::vector<std::string>& lines, const std::string& filename, bool clearVector = true);
void SaveToFile(std::vector<std::string>& lines, const std::string& filename);
