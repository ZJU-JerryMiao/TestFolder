cmake_minimum_required(VERSION 3.15)
project(lineditor C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES
        acllib.h						//*号对应具体的文件名
        acllib.c
        linkedlist.c
        linkedlist.h
        )

link_directories(C:\\Program Files\\mingw-w64\\x86_64-8.1.0-win32-seh-rt_v6-rev0\\mingw64\\x86_64-w64-mingw32\\lib)

link_libraries(libwinmm.a)
link_libraries(libmsimg32.a)
link_libraries(libkernel32.a)
link_libraries(libuser32.a)
link_libraries(libgdi32.a)
link_libraries(libole32.a)
link_libraries(liboleaut32.a)
link_libraries(libuuid.a)

add_executable(lineditor main.c ${SOURCE_FILES} ${SOURCES})

target_link_libraries(lineditor libwinmm.a)
target_link_libraries(lineditor libmsimg32.a)
target_link_libraries(lineditor libkernel32.a)
target_link_libraries(lineditor libuser32.a)
target_link_libraries(lineditor libgdi32.a)
target_link_libraries(lineditor libole32.a)
target_link_libraries(lineditor liboleaut32.a)
target_link_libraries(lineditor libuuid.a)