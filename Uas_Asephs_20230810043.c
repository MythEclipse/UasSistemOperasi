#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // Direktori utama
    char baseDir[] = "Project";

    // Subdirektori utama
    char mainSubDirs[][20] = {"src", "include", "lib", "bin"};

    // Subdirektori di dalam 'src'
    char srcSubDirs[][20] = {"main", "utils"};

    // Subdirektori di dalam 'include'
    char includeSubDirs[][20] = {"common", "config"};

    // Subdirektori di dalam 'lib'
    char libSubDirs[][20] = {"external", "internal"};

    // Membuat direktori utama
    if (mkdir(baseDir, 0777) == -1) {
        perror("Gagal membuat direktori utama");
        exit(1);
    }

    // Membuat subdirektori utama di dalam "Project"
    for (int i = 0; i < sizeof(mainSubDirs) / sizeof(mainSubDirs[0]); i++) {
        char path[50];
        snprintf(path, sizeof(path), "%s/%s", baseDir, mainSubDirs[i]);
        if (mkdir(path, 0777) == -1) {
            perror("Gagal membuat subdirektori utama");
            exit(1);
        }
    }

    // Membuat subdirektori di dalam 'src'
    for (int i = 0; i < sizeof(srcSubDirs) / sizeof(srcSubDirs[0]); i++) {
        char path[50];
        snprintf(path, sizeof(path), "%s/src/%s", baseDir, srcSubDirs[i]);
        if (mkdir(path, 0777) == -1) {
            perror("Gagal membuat subdirektori di dalam 'src'");
            exit(1);
        }
    }

    // Membuat subdirektori di dalam 'include'
    for (int i = 0; i < sizeof(includeSubDirs) / sizeof(includeSubDirs[0]); i++) {
        char path[50];
        snprintf(path, sizeof(path), "%s/include/%s", baseDir, includeSubDirs[i]);
        if (mkdir(path, 0777) == -1) {
            perror("Gagal membuat subdirektori di dalam 'include'");
            exit(1);
        }
    }

    // Membuat subdirektori di dalam 'lib'
    for (int i = 0; i < sizeof(libSubDirs) / sizeof(libSubDirs[0]); i++) {
        char path[50];
        snprintf(path, sizeof(path), "%s/lib/%s", baseDir, libSubDirs[i]);
        if (mkdir(path, 0777) == -1) {
            perror("Gagal membuat subdirektori di dalam 'lib'");
            exit(1);
        }
    }

    // Pesan sukses
    printf("Struktur direktori berhasil dibuat!\n");
    return 0;
}