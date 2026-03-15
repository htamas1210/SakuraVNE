#define SDL_MAIN_HANDLED 1

#include "Application.h"
#include "SDL3/SDL_main.h"
// #include "SakuraCore/src/Application.h"

int main(int argc, char *argv[]) {
    SDL_SetMainReady();

    Application app;

    bool success = app.Init();

    if (success)
        app.Run();

    return 0;
}
