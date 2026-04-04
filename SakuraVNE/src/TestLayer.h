#pragma once

#include "Layer.h"

class TestLayer : public SakuraVNE::Layer {
public:
    TestLayer();
    virtual ~TestLayer() = default;

    virtual void OnImGuiRender() override;
};
