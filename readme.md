**Compile on windows with winGW**

`gcc main.c -I".\json-c_x64-mingw-dynamic\include" -L".\json-c_x64-mingw-dynamic\lib" -ljson-c`

**Compile on unix/linux gcc**

`gcc ./main.c -Ijson-c/include -Ljson-c/lib64 -ljson-c`