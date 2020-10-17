#include <stdio.h>

#ifdef WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

#include "load.h"

int LoadRun(const char * const s, int i, int *mas, int size) {
    int count_m;
    void * lib;
    int (*fun)(int *el, int size);

    #ifdef WIN32
        lib = LoadLibrary(s);
    #else
        lib = dlopen(s, RTLD_LAZY);
    #endif

    if (!lib) {
        printf("cannot open library '%s'\n", s);
        return;
    }

    if (i==1){
        #ifdef WIN32
            fun = (void (*)(int *mas, int size))GetProcAddress((HINSTANCE)lib, "get_mas_count");
        #else
            fun = (void (*)(int *mas, int size))dlsym(lib, "get_mas_count");
        #endif

        if (fun == NULL) {
            printf("cannot load function \n");
        }
    } else if (i==2){
        #ifdef WIN32
            fun = (void (*)(int *matr, int size))GetProcAddress((HINSTANCE)lib, "get_matr_count");
        #else
            fun = (void (*)(int *matr, int size))dlsym(lib, "get_matr_count");
        #endif

        if (fun == NULL) {
            printf("cannot load function \n");
        }
    }
    count_m = fun(mas, size);
    #ifdef WIN32
        FreeLibrary((HINSTANCE)lib);
    #else
        dlclose(lib);
    #endif

    return count_m;

}
