#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    // direktori utama
    char baseDir[] = "project";
    // subdirektori utama
    char mainSubDirs[][20]= {"src", "include", "lib", "bin"};
    // subdirektori src
    char srcSubDirs[][20] = {"main", "utils"};
    // subdirektori include
    char includeSubDirs[][20] = {"common", "config"};
    // subdirektori lib
    char libSubDirs[][20] = {"external", "internal"};
    // membuat direktori utama
    if (mkdir(baseDir, 0777) == -1){
        perror("gagal membuat direktori utama");
        exit(1);
    }

    // membuat subdirektori utama didalam "project"
    for (int i = 0; i< sizeof(mainSubDirs)/sizeof(mainSubDirs[0]); i++){
        char path [100];
        sprintf(path,sizeof(path), "%s/%s", baseDir, mainSubDirs[i]);
        if (mkdir(path, 0777) == -1){
            perror("gagal membuat subdirektori utama");
            exit(1);
        }
    }
    // membuat subdirektori didalam "src"
    for (int i = 0; i< sizeof(srcSubDirs)/sizeof(srcSubDirs[0]); i++){
        char path [100];
        sprintf(path,sizeof(path), "%s/%s/%s", baseDir, mainSubDirs[0], srcSubDirs[i]);
        if (mkdir(path, 0777) == -1){
            perror("gagal membuat subdirektori src");
            exit(1);
        }
    }
    // membuat subdirektori didalam "include"
    for (int i = 0; i< sizeof(includeSubDirs)/sizeof(includeSubDirs[0]); i++){
        char path [100];
        sprintf(path,sizeof(path), "%s/%s/%s", baseDir, mainSubDirs[1], includeSubDirs[i]);
        if (mkdir(path, 0777) == -1){
            perror("gagal membuat subdirektori include");
            exit(1);
        }
    }
    // membuat subdirektori didalam "lib"
    for (int i = 0; i< sizeof(libSubDirs)/sizeof(libSubDirs[0]); i++){
        char path [100];
        sprintf(path,sizeof(path), "%s/%s/%s", baseDir, mainSubDirs[2], libSubDirs[i]);
        if (mkdir(path, 0777) == -1){
            perror("gagal membuat subdirektori lib");
            exit(1);
        }
    }
    printf("Struktur direktori berhasil dibuat\n");
    return 0;
}