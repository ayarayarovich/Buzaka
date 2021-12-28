#include "LayerStack.h"

namespace Buzaka {

    LayerStack::~LayerStack() {
        for (Layer* layer : m_LayerStack)
            delete layer;
    }

    void LayerStack::PushLayer(Layer* layer) {
        m_LayerStack.emplace(m_LayerStack.begin() + m_LayerInsertToIndex, layer);
        m_LayerInsertToIndex += 1;
    }

    void LayerStack::PushOverlay(Layer* overlay) {
        m_LayerStack.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer) {
        auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), layer);
        if (it != m_LayerStack.end()) {
            m_LayerStack.erase(it);
            m_LayerInsertToIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer *overlay) {
        auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), overlay);
        if (it != m_LayerStack.end()) {
            m_LayerStack.erase(it);
        }
    }

}
