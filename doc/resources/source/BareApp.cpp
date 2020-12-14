#include <afxwin.h>

class CExampleApp : public CWinApp
{
public:
  BOOL InitInstance();
};

BOOL CExampleApp::InitInstance()
{
  return TRUE;
}

CExampleApp theApp;