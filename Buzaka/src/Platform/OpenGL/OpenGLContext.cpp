#include "pch/bzpch.h"
#include "OpenGLContext.h"

#include "Buzaka/Core/Log.h"
#include "Buzaka/Core/Assert.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace Buzaka {

    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_WindowHandle(windowHandle) {
        BZ_CORE_ASSERT(windowHandle, "Window handle is null!");
    }

    void OpenGLContext::Init() {
        glfwMakeContextCurrent(m_WindowHandle);
        int gladInitSuccess = gladLoadGL((GLADloadfunc)glfwGetProcAddress);
        BZ_CORE_ASSERT(gladInitSuccess, "Failed to initialize Glad!")
        BZ_CORE_INFO("OpenGL version: {0}", glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers() {
        glfwSwapBuffers(m_WindowHandle);
    }
}