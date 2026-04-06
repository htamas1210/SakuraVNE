#include "Event.h"
#include "InputEvents.h"
#include "Layer.h"
#include "WindowEvents.h"

class AppLayer : public SakuraVNE::Layer {
public:
    AppLayer();
    virtual ~AppLayer() = default;
    virtual void OnImGuiRender() override;
    virtual void OnEvent(SakuraVNE::Event &event) override;

private:
    bool OnMouseButtonPressed(SakuraVNE::MouseButtonPressedEvent &event);
    bool OnMouseMoved(SakuraVNE::MouseMovedEvent &event);
    bool OnWindowClosed(SakuraVNE::WindowClosedEvent &event);
    int m_ClickCounter = 0;
};
