#pragma once

#include <string>
#include <vector>
#include <atlstr.h>

inline std::string toStdString(const CString& str)
{
  CT2CA pszConvertedString(str);
  return std::string{pszConvertedString};
}

void readLinesFromFile(std::vector<std::string>& lines, const std::string& filename, bool clearVector = true);