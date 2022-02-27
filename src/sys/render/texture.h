#pragma once

#include "../../macros.h"
#include "shader.h"

namespace Alkahest
{
    class API Texture
    {
    public:
        Texture() {};
        virtual ~Texture() {};

        virtual void setUniformTexture(Ref<Shader> shader, const char* uniform, unsigned int unit) = 0;

        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual void destroy() = 0;

        static Ref<Texture> create(const char* image, uint32_t texType, uint32_t slot, uint32_t format, uint32_t pixelType);
    };
}