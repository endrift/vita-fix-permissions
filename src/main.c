#include <psp2/io/dirent.h>
#include <psp2/io/stat.h>
#include <psp2/kernel/processmgr.h>
#include <stdio.h>

#include "debugScreen.h"

#define printf psvDebugScreenPrintf
#define PATH_MAX 2000

const char* base = "ux0:data";

static void fixDir(const char* path) {
	SceUID dir = sceIoDopen(path);
	SceIoDirent ent;
	while (sceIoDread(dir, &ent) > 0) {
		char subpath[PATH_MAX + 1] = "";
		snprintf(subpath, PATH_MAX, "%s/%s", path, ent.d_name);
		printf("Fixing permissions for %s...\n", subpath);
		ent.d_stat.st_mode |= 0606;
		sceIoChstat(subpath, &ent.d_stat, 1);
		if (SCE_S_ISDIR(ent.d_stat.st_mode)) {
			fixDir(subpath);
		}
	}
	sceIoDclose(dir);
}

int main() {
	psvDebugScreenInit();

	fixDir(base);

	printf("Done! Exiting in 10 seconds.");

	sceKernelDelayThread(10 * 1000 * 1000);
	sceKernelExitProcess(0);
	return 0;
}
