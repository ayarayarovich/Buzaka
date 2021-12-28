#pragma once

#include "pch/bzpch.h"
#include "Base.h"
#include "Assert.h"
#include "Window.h"
#include "Events.h"
#include "Layer.h"
#include "LayerStack.h"
#include "Input.h"

#include "Buzaka/ImGui/ImGuiLayer.h"

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

    inline static Application& Get() { return *s_Instance; }
    inline Window& GetWindow() { return *m_Window; }

  private:
      bool m_Running = true;
      std::unique_ptr<Window> m_Window;
      LayerStack m_LayerStack;
      ImGuiLayer* m_ImGuiLayer;

  private:
      static Application* s_Instance;
  };

  //to be defined in CLIENT
  Application* CreateApplication();
}
