#include <stdio.h>
#include <stdlib.h>

struct ipallete {
    void *id;
    int size, pathsz;
    char *chrpath;
    char *content;
};

int iread_pallete_file(char *path, struct ipallete *pallete);
int iwrite_pallete_file(char *path, struct ipallete *pallete);
int ipallete_setidx(struct ipallete *pallete, int index, char color[4]);
int ipallete_getidx(struct ipallete *pallete, int index, char color[4]);
int ipallete_delete(struct ipallete *pallete);
