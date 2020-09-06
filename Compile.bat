gcc src/inttoRad.c -c -I include
ar rcs lib/libradical.a inttoRad.o
gcc main.c -L lib -lradical -I include -o exec.exe
@pause