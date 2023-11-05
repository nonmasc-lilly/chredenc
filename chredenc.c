#include "chredenc.h"

int iread_pallete_file(char *path, struct ipallete *pallete) {
    FILE *fp;
    int fsz, pathsz;
    char *fcontent, *_path;
    fp = fopen(path, "r");
    fsz = (fseek(fp, 0L, SEEK_END), ftell(fp));
    fcontent = malloc(fsz);
    fread(fcontent, 1, fsz, fp);
    
    if(*((int*)fcontent) != *((int*)"CEDT")) {
        free(fcontent);
        return -1;
    }
    _path = malloc(1);
    for(pathsz = 1; fcontent[pathsz + 3] != '\n'; pathsz++) {
        _path = realloc(_path, pathsz);
        _path[pathsz-1] = fcontent[pathsz + 3];
    }
    _path = realloc(_path, pathsz);
    _path[pathsz-1] = '\0';

    pallete->id = fcontent;
    pallete->size = fsz - pathsz - 4;
    pallete->chrpath = _path;
    pallete->pathsz = pathsz;
    pallete->content = fcontent + pathsz + 4;
}

int iwrite_pallete_file(char *path, struct ipallete *pallete) {
    FILE *fp;
    char *content;
    int i;
    fp = fopen(path, "w");
    content = malloc(4 + pallete->size + pallete->pathsz);
    content[0] = 'C';
    content[1] = 'E';
    content[2] = 'D';
    content[3] = 'T';
    for(i = 4; i < pallete->pathsz + 4; i++)
        content[i] = pallete->chrpath[i - 4];
    for(i = 4 + pallete->pathsz; i < pallete->size + 4 + pallete->pathsz; i++)
        content[i] = pallete->content[i - 4 - pallete->pathsz];
    fwrite(content, 1, pallete->size + pallete->pathsz + 4, fp);
    free(content);
}

int ipallete_setidx(struct ipallete *pallete, int index, char color[4]) {
    pallete->content[index * 4] = color[0];
    pallete->content[index * 4 + 1] = color[1];
    pallete->content[index * 4 + 2] = color[2];
    pallete->content[index * 4 + 3] = color[3];
}

int ipallete_getidx(struct ipallete *pallete, int index, char color[4]) {
    color[0] = pallete->content[index * 4];
    color[1] = pallete->content[index * 4 + 1];
    color[2] = pallete->content[index * 4 + 2];
    color[3] = pallete->content[index * 4 + 3];
}

int ipallete_delete(struct ipallete *pallete) {
    free(pallete->id);
    free(pallete->chrpath);
}









