
#include <3ds.h>
#include <stdio.h>

int main(void)
{
    gfxInitDefault();

    PrintConsole topConsole;
    PrintConsole bottomConsole;

    consoleInit(GFX_TOP, &topConsole);
    consoleInit(GFX_BOTTOM, &bottomConsole);

    consoleSelect(&topConsole);
    printf("\x1b[14;12H ECRAN DU HAUT");

    consoleSelect(&bottomConsole);
    printf("\x1b[14;9H ECRAN DU BAS");

    while (aptMainLoop())
    {
        hidScanInput();

        if (hidKeysDown() & KEY_START)
            break;

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
