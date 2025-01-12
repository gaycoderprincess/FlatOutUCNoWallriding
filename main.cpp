#include <windows.h>
#include "nya_commonhooklib.h"
#include "fo2versioncheck.h"

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {
	switch( fdwReason ) {
		case DLL_PROCESS_ATTACH: {
			DoFlatOutVersionCheck(FO2Version::FOUC_GFWL);
			NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x42CBDC, 0x42D19B);
		} break;
		default:
			break;
	}
	return TRUE;
}