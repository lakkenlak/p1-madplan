**Compile on windows with winGW**

`gcc .\recipes.c -I".\json-c_x64-mingw-dynamic\include\json-c" -L".\json-c_x64-mingw-dynamic\lib" -ljson-c`

**Compile on unix with**

`gcc ./recipes.c -I./json-unix/include/json-c -L./json-unix/lib64 -ljson-c`