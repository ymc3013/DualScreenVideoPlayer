#include <stdio.h>
#include "video.h"

static FILE *video_file = NULL;

bool Video_init(const char *filename)
{
    if (filename == NULL)
        return false;

    video_file = fopen(filename, "rb");

    if (video_file == NULL)
        return false;

    return true;
}

void Video_exit(void)
{
    if (video_file != NULL)
    {
        fclose(video_file);
        video_file = NULL;
    }
}