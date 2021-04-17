#ifndef _OS_WIN_WINDOW_H
#define _OS_WIN_WINDOW_H
#include "os/window.h"
#include "os/event_queue.h"
#include "os/surface.h"

#include <memory>
#include <windows.h>

#ifdef max
   #undef max
#endif

#ifdef min
   #undef min
#endif

namespace os
{
   class WinWindow : public Window
   {
   public:
      WinWindow(int width, int height);
      ~WinWindow();

      virtual void setTitle(const std::string& title) override;
      virtual void setVisible(bool visible) override;
      virtual void setMouseCursor(MouseCursor cursor) override;

      virtual void invalidate() override;
      virtual void captureMouse() override;
      virtual void releaseMouse() override;

      virtual Surface* surface() override;
      virtual NativeHandle handle() override;
   private:
      class WindowClass;

      void mouseEvent(Event& ev, LPARAM lParam);
      void queueEvent(Event& ev);
      static LRESULT CALLBACK GlobalWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
      LRESULT wndProc(UINT msg, WPARAM wParam, LPARAM lParam);

      HWND m_hwnd;
      HCURSOR m_hcursor;
      bool m_mouseHover;
      std::unique_ptr<Surface> m_surface;
   };
} // namespace os

#endif