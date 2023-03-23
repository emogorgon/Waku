#pragma once

#include "Waku/Core/Layer/Layer.h"

#include "Waku/Events/ApplicationEvent.h"
#include "Waku/Events/KeyEvent.h"
#include "Waku/Events/MouseEvent.h"

namespace Waku {

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnEvent(Event& e) override;

        void Begin();
        void End();

        void BlockEvents(bool block) { m_BlockEvents = block; }
		
        void SetDarkThemeColors();

        uint32_t GetActiveWidgetID() const;
    private:
        bool m_BlockEvents = true;
    };

}
