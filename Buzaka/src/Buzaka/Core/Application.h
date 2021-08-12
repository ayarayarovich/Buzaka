#pragma once

#include "pch/bzpch.h"
#include "Base.h"
#include "Window.h"

namespace Buzaka {
  class Application
  {
  public:
    Application();
    virtual ~Application();

      [[noreturn]] void Run();

  private:
      std::unique_ptr<Window> m_Window;
      bool m_Running = true;
  };

  //to be defined in CLIENT
  Application* CreateApplication();
}