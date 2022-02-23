#pragma once

#include "../../macros.h"
#include "window.h"
#include "../events/event.h"

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#ifndef ALKAHEST_CURSOR_MODE
#define ALKAHEST_CURSOR_MODE GLFW_CURSOR_NORMAL
#endif

#ifndef ALKAHEST_RAW_MOTION
#define ALKAHEST_RAW_MOTION GLFW_TRUE
#endif

// Much of the early systems developed for AlkahestEngine were developed following
// along with the Game Engine series from The Cherno (Yan Chernikov) as he built
// the Hazel game engine. A future refactor of these systems is planned to
// eventually re-work this code to adapt it more closely to the direction the
// AlkahestEngine is heading. In the meantime, however, thank you to Yan for
// providing one of the most educational channels on YT when it comes to C++
// and OpenGL development.
//
// In compliance with the Hazel license, a copy of said license is available at
// {project_root}/.licenses/Hazel.LICENSE
//
// The code within this file has been modified from the original source, and
// this notice is provided in compliance with the above license terms.

namespace Alkahest
{
    class NOT_EXPORTED OpenGLWindow : public IWindow
    {
    public:
        OpenGLWindow(const WindowProps& props);
        virtual ~OpenGLWindow();

        void onUpdate() override;

        inline virtual unsigned int getWidth() const override { return m_data.width; };
        inline virtual unsigned int getHeight() const override { return m_data.height; };

        virtual void setVSync(bool vsync) override;
        virtual bool isVSync() const override;

        virtual inline void setEventCallback(std::function<void(Event*)> func) { m_data.eventCallback = func; };
    private:
        void init(const WindowProps& props);
        void shutdown();

        struct WindowData {
            std::string title;
            unsigned int width;
            unsigned int height;
            bool vsync;
            std::function<void(Event*)> eventCallback;
        };
        WindowData m_data;
        GLFWwindow *m_window;
    };
}