# chredenc
chredenc is an implementation of my CHRN.EDIT specification that I came up with in 10 minutes

## chredenc documentation
CHRN.EDIT is stored in the following struct by chredenc
```C
struct ipallete {
  void *id;
  int size, pathsz;
  char *chrpath;
  char *content;
};
```
where `id` is the beginning of the malloced file pointer, can be freed with `ipallete_delete(struct ipallete *pallete)`
- `size` is the size of the content `char*`
- `pathsz` is the size of the `chrpath` string
- `chrpath` is the path to the CHRN file that the CHRN.EDIT file edits
- `content` is the r,g,b,a of the pallete stored in a `char*`

you can read a CHRN.EDIT file with `iread_pallete_file(char *path, struct ipallete *pallete)`
where `path` is the path to the CHRN.EDIT file and `pallete` is the return struct

you can write to a CHRN.EDIT file with `iwrite_pallete_file(char *path, struct ipallete *pallete)`
where `path` is the path to the CHRN.EDIT file to write to and `pallete` is the pallete to write

you can get a pallete from index with `ipallete_getidx(struct ipallete *pallete, int index, char color[4])`
where `pallete` is the pallete to check, `index` is the place in the pallete to check, and `color` is the
return buffer

you can set a pallete with index via `ipallete_setidx(struct ipallete *pallete, int index, char color[4])`
where `pallete` is the pallete to write to, `index` is the place in the pallete to write to, and `color`
is the value to write.

## CHRN.EDIT specification
The CHRN.EDIT file is designed to store palletes for the use of editing CHRN files. The file
begins with `CEDT` then a path to the CHRN file it is editing and finally a char array defining
the palletes in the form (r,g,b,a)
