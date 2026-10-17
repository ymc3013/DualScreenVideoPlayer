#include <3ds.h>
#include <stdio.h>
#include <stdbool.h>

#include "video.h"
#include "audio.h"

int main(void)
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    printf("DualScreenVideoPlayer\n");
    printf("=====================\n\n");

    printf("Initialisation...\n");

    bool video_found = Video_init("sdmc:/Movies/test.avi");

    Audio_init();

    printf("\n");

    if (video_found)
    {
        printf("Video trouve !\n");
        printf("SD:/Movies/test.avi\n");
        printf("\n");
        printf("La lecture n'est pas encore\n");
        printf("implementee.\n");
    }
    else
    {
        printf("Video introuvable.\n\n");
        printf("Verifie que le fichier existe :\n");
        printf("SD:/Movies/test.avi\n");
    }

    printf("\nSTART : quitter");

    while (aptMainLoop())
    {
        hidScanInput();

        u32 keys = hidKeysDown();

        if (keys & KEY_START)
            break;

        gspWaitForVBlank();
    }

    Audio_exit();
    Video_exit();

    gfxExit();

    return 0;
}