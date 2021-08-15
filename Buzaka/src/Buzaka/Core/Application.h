#pragma once

#include "pch/bzpch.h"
#include "Base.h"
#include "Window.h"
#include "Events.h"
#include "Layer.h"
#include "LayerStack.h"

namespace Buzaka {
  class Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();

    bool OnWindowClose(WindowCloseEvent& event);

    void OnEvent(Event& event);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);

  private:
      std::unique_ptr<Window> m_Window;
      bool m_Running = true;
      LayerStack m_LayerStack;
  };

  //to be defined in CLIENT
  Application* CreateApplication();
}
