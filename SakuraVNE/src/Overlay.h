#pragma once

#include "Layer.h"

class Overlay : public SakuraVNE::Layer {
public:
    Overlay();
    virtual ~Overlay() = default;

    virtual void OnImGuiRender() override;
};
