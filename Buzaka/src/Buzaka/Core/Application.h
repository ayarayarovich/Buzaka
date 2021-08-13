#pragma once

#include "pch/bzpch.h"
#include "Base.h"
#include "Window.h"
#include "Events.h"

namespace Buzaka {
  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();

    bool OnWindowClose(WindowCloseEvent& event);

    void OnEvent(Event& event);

  private:
      std::unique_ptr<Window> m_Window;
      bool m_Running = true;
  };

  //to be defined in CLIENT
  Application* CreateApplication();
}