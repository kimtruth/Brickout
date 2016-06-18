#define WIDTH 44
#define HEIGHT 25

void ScreenInit();
void ScreenFlipping();
void ScreenRelease();
void SetSize(int cols, int lines);
void RemoveCursor();
void ScreenPrint( int x, int y, char *string );
void gotoxy(int x, int y);