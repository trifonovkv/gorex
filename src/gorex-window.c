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
gorex_window_init (GorexWindow *window)
{
    gtk_widget_init_template (GTK_WIDGET (window));
}

static void
gorex_window_class_init (GorexWindowClass *class)
{
    gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                            "/org/gnome/gorex/gorex-window.ui");
}

GorexWindow *
gorex_window_new (GorexApplication *application)
{
    return g_object_new (GOREX_TYPE_WINDOW, "application", application, NULL);
}

void
gorex_window_open (GorexWindow *win,
                   GFile       *file)
{
}
