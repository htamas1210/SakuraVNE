#include "AppLayer.h"
#include "Application.h"
#include "Overlay.h"
#include "SDL3/SDL_main.h"
#include "SDL3/SDL_video.h"

int main(int argc, char *argv[]) {
    SakuraVNE::AppData appData;
    appData.name = "Sakura Visual Novel Creator";
    appData.windowdata.windowFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY;
    appData.windowdata.title = appData.name;
    appData.windowdata.width = 1280;
    appData.windowdata.height = 720;

    SakuraVNE::Application app(appData);
    app.PushLayer<AppLayer>();
    app.PushOverlay<Overlay>();
    app.Run();

    return 0;
}
