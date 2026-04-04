#include "AppLayer.h"
#include "Application.h"
#include "Overlay.h"

int main(int argc, char *argv[]) {
    AppData appData;
    appData.name = "Sakura Visual Novel Creator";
    appData.windowdata.title = appData.name;
    appData.windowdata.width = 1280;
    appData.windowdata.height = 720;

    Application app(appData);
    app.PushLayer<AppLayer>();
    app.PushOverlay<Overlay>();
    app.Run();

    return 0;
}
