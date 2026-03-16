#include "Application.h"

int main(int argc, char *argv[]) {
    Application app;

    bool success = app.Init();

    if (success)
        app.Run();

    return 0;
}
