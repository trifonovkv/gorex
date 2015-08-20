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

typedef struct _GorexWindowPrivate GorexWindowPrivate;

struct _GorexWindowPrivate
{
    GtkWidget *drawing_area;
};

G_DEFINE_TYPE_WITH_PRIVATE (GorexWindow, gorex_window, 
                            GTK_TYPE_APPLICATION_WINDOW);

gboolean
drawing_area_draw_callback (GtkWidget    *widget,
                            cairo_t      *cr,
                            gpointer      user_data)
{
    cairo_set_antialias (cr, CAIRO_ANTIALIAS_NONE);
    cairo_set_source_rgb (cr, 1, 1, 1);
    cairo_paint (cr);

    return TRUE;
}

static void
gorex_window_init (GorexWindow *window)
{
    GorexWindowPrivate *priv;

    priv = gorex_window_get_instance_private (window);

    gtk_widget_init_template (GTK_WIDGET (window));

    g_signal_connect (priv->drawing_area, "draw",
                      G_CALLBACK (drawing_area_draw_callback), NULL);
}

static void
gorex_window_class_init (GorexWindowClass *class)
{
    gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                            "/org/gnome/gorex/gorex-window.ui");

    gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), 
                                                  GorexWindow, drawing_area);
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
