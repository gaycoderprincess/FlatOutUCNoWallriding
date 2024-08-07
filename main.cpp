#include <windows.h>
#include "nya_commonhooklib.h"

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {
	switch( fdwReason ) {
		case DLL_PROCESS_ATTACH: {
			if (NyaHookLib::GetEntryPoint() != 0x24CEF7) {
				MessageBoxA(nullptr, "Unsupported game version! Make sure you're using the Steam GFWL version (.exe size of 4242504 bytes)", "nya?!~", MB_ICONERROR);
				exit(0);
				return TRUE;
			}

			NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x42CBDC, 0x42D19B);
		} break;
		default:
			break;
	}
	return TRUE;
}