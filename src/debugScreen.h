#ifndef DEBUG_SCREEN_H
#define DEBUG_SCREEN_H

#define SCREEN_WIDTH    (960)
#define SCREEN_HEIGHT   (544)
#define SCREEN_FB_WIDTH (960)
#define SCREEN_FB_SIZE  (2 * 1024 * 1024)
#define SCREEN_FB_ALIGN (256 * 1024)
#define SCREEN_GLYPH_W  (8)
#define SCREEN_GLYPH_H  (8)

#define COLOR_BLACK      0xFF000000
#define COLOR_RED        0xFF0000FF
#define COLOR_BLUE       0xFF00FF00
#define COLOR_YELLOW     0xFF00FFFF
#define COLOR_GREEN      0xFFFF0000
#define COLOR_MAGENTA    0xFFFF00FF
#define COLOR_CYAN       0xFFFFFF00
#define COLOR_WHITE      0xFFFFFFFF
#define COLOR_GREY       0xFF808080
#define COLOR_DEFAULT_FG COLOR_WHITE
#define COLOR_DEFAULT_BG COLOR_BLACK

uint32_t psvDebugScreenSetFgColor(uint32_t color);
uint32_t psvDebugScreenSetBgColor(uint32_t color);
int psvDebugScreenInit();
void psvDebugScreenClear(int bg_color);
int psvDebugScreenPuts(const char * text);
int psvDebugScreenPrintf(const char *format, ...);

#endif
