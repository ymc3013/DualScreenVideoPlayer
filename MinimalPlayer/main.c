
#include <3ds.h>
#include <stdio.h>

int main(void)
{
    gfxInitDefault();

    consoleInit(GFX_TOP, NULL);

    printf("DualScreenVideoPlayer\n\n");
    printf("Test de la carte SD...\n\n");

    FILE *video = fopen("sdmc:/Movies/test.avi", "rb");

    if (video != NULL)
    {
        printf("OK : test.avi est accessible.\n");
        fclose(video);
    }
    else
    {
        printf("ERREUR : video introuvable.\n");
        printf("Verifie SD:/Movies/test.avi\n");
    }

    printf("\nSTART pour quitter.");

    while (aptMainLoop())
    {
        hidScanInput();

        if (hidKeysDown() & KEY_START)
            break;

        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
