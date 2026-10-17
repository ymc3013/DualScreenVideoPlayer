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
    printf("---------------------\n\n");
    printf("Initialisation...\n");

    bool video_found = Video_init("sdmc:/Movies/test.avi");
    Audio_init();

    printf("\n");

    if (video_found)
    {
        printf("Fichier video trouve !\n");
        printf("SD:/Movies/test.avi\n\n");
        printf("La lecture sera ajoutee\n");
        printf("dans une prochaine etape.\n");
    }
    else
    {
        printf("ERREUR : video introuvable.\n");
        printf("Verifie le dossier Movies.\n");
    }

    printf("\nSTART pour quitter.");

    while (aptMainLoop())
    {
        hidScanInput();

        if (hidKeysDown() & KEY_START)
            break;

        gspWaitForVBlank();
    }

    Audio_exit();
    Video_exit();
    gfxExit();

    return 0;
}