#include <gtk/gtk.h>

#include "gorex-application.h"
#include "gorex-window.h"

struct _GorexWindow
{
  GtkApplicationWindow parent;
};

struct _GorexWindowClass
{
  GtkApplicationWindowClass parent_class;
};

G_DEFINE_TYPE (GorexWindow, gorex_window, GTK_TYPE_APPLICATION_WINDOW);

static void
gorex_window_init (GorexWindow *app)
{
}

static void
gorex_window_class_init (GorexWindowClass *class)
{
}

GorexWindow *
gorex_window_new (GorexApplication *app)
{
  return g_object_new (GOREX_TYPE_WINDOW, "application", app, NULL);
}

void
gorex_window_open (GorexWindow *win,
                   GFile       *file)
{
}
