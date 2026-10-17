#include <stdbool.h>
#include "3ds.h"
#include "system/menu.h"
#include "video_player.h"

int main(void)
{
    Menu_init();
    Vid_init(false);

    if (!Vid_play_file("sdmc:/Movies/", "test.avi"))
    {
        Vid_exit(false);
        Menu_exit();
        return 1;
    }

    while (aptMainLoop())
    {
        Menu_main();
    }

    Vid_exit(false);
    Menu_exit();
    return 0;
}
