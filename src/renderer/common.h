#pragma once

#include "../macros.h"
#include "../sys/render/camera.h"
#include "../sys/render/shader.h"

namespace Alkahest
{

#define POSITION_LOCATION   0
#define TEXTURE_LOCATION    1
#define NORMAL_LOCATION     2

    enum BufferType {
        Index       = 0,    // Index / Element Buffer
        VPos        = 1,    // Vertex Position Buffer
        VTex        = 2,    // Vertex TexCoord Buffer
        VNorm       = 3,    // Vertex Normal Buffer
        VMVP        = 4,    // Vertex Model-View-Projection Matrix Buffer
        VWM         = 5,    // Vertex World Matrix Buffer
        NumBuffers  = 6
    };

    struct Material {};

    class NOT_EXPORTED IRenderable
    {
    public:
        IRenderable() {};
        virtual ~IRenderable() {};

        virtual void draw() = 0;
        virtual void setShader(Ref<Shader> shader) = 0;
        virtual void setCamera(Ref<Camera> cam) = 0;
    };
}