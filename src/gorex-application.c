#include <gtk/gtk.h>

#include "gorex-application.h"
#include "gorex-window.h"

struct _GorexApplication
{
  GtkApplication parent;
};

struct _GorexApplicationClass
{
  GtkApplicationClass parent_class;
};

G_DEFINE_TYPE(GorexApplication, gorex_application, GTK_TYPE_APPLICATION);

static void
gorex_application_init (GorexApplication *app)
{
}

static void
gorex_application_activate (GApplication *app)
{
  GorexWindow *win;

  win = gorex_window_new (GOREX_APPLICATION (app));
  gtk_window_present (GTK_WINDOW (win));
}

static void
gorex_application_open (GApplication  *app,
			                  GFile        **files,
                  			gint           n_files,
                 			  const gchar   *hint)
{
  GList *windows;
  GorexWindow *win;
  int i;

  windows = gtk_application_get_windows (GTK_APPLICATION (app));
  if (windows)
    win = GOREX_WINDOW (windows->data);
  else
    win = gorex_window_new (GOREX_APPLICATION (app));

  for (i = 0; i < n_files; i++)
    gorex_window_open (win, files[i]);

  gtk_window_present (GTK_WINDOW (win));
}

static void
gorex_application_class_init (GorexApplicationClass *class)
{
  G_APPLICATION_CLASS (class)->activate = gorex_application_activate;
  G_APPLICATION_CLASS (class)->open = gorex_application_open;
}

GorexApplication *
gorex_application_new (void)
{
  return g_object_new (GOREX_TYPE_APPLICATION,
                       "application-id", "org.gtk.gorex-application",
                       "flags", G_APPLICATION_HANDLES_OPEN,
                       NULL);
}
