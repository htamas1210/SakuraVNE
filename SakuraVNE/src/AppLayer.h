#include "Layer.h"

class AppLayer : public SakuraVNE::Layer {
public:
    AppLayer();
    virtual ~AppLayer() = default;
    virtual void OnImGuiRender() override;

private:
    // bool OnMouseButtonPressed(Core::MouseButtonPressedEvent &event);
    // bool OnMouseMoved(Core::MouseMovedEvent &event);
    // bool OnWindowClosed(Core::WindowClosedEvent &event);
};
