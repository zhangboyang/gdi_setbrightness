#include <windows.h>

/*
	you should set registry before using this program
	see
		http://jonls.dk/2010/09/windows-gamma-adjustments/
		https://photo.stackexchange.com/questions/3436/how-to-apply-color-management-to-the-windows-7-mouse-cursor
	for details

	[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\ICM]
	"GdiIcmGammaRange"=dword:00000100

	[HKEY_CURRENT_USER\Control Panel\Mouse]
	"MouseTrails"="-1"
*/

int main(int argc, char *argv[])
{
	WORD GammaArray[3][256];
	WORD wBrightness = 256;

	if (argc > 1) {
		wBrightness = atoi(argv[1]);
	}

	/*
		copied from:
		https://stackoverflow.com/questions/8359607/correct-usage-of-setdevicegammaramp
		http://www.nirsoft.net/vc/change_screen_brightness.html
	*/
	for (int ik = 0; ik < 256; ik++) {
		int iArrayValue = ik * wBrightness;
		if (iArrayValue > 0xffff) iArrayValue = 0xffff;
		GammaArray[0][ik] = (WORD)iArrayValue;
		GammaArray[1][ik] = (WORD)iArrayValue;
		GammaArray[2][ik] = (WORD)iArrayValue;
	}

	HDC hDC = GetDC(NULL);
	SetDeviceGammaRamp(hDC, GammaArray);
	ReleaseDC(NULL, hDC);
	return 0;
}