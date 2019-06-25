#include <windows.h>

#pragma comment(lib, "mscms.lib")

extern int WINAPI InternalRefreshCalibration(int, int);

int main()
{
	InternalRefreshCalibration(0, 0);
	return 0;
}
