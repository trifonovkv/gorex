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

G_DEFINE_TYPE (GorexApplication, gorex_application, GTK_TYPE_APPLICATION);

static void
gorex_application_init (GorexApplication *app)
{
}

static void
open_file_activated (GSimpleAction *action,
                     GVariant      *parameter,
                     gpointer       app)
{
}

static void
quit_activated (GSimpleAction *action,
                GVariant      *parameter,
                gpointer       app)
{
    g_application_quit (G_APPLICATION (app));
}

static GActionEntry app_entries[] =
{
    { "open_file", open_file_activated, NULL, NULL, NULL },
    { "quit", quit_activated, NULL, NULL, NULL }
};

static void
gorex_application_startup (GApplication *app)
{
    GtkBuilder *builder;
    GMenuModel *app_menu;
    const gchar *open_accels[2] = { "<Ctrl>O", NULL };
    const gchar *quit_accels[2] = { "<Ctrl>Q", NULL };

    G_APPLICATION_CLASS (gorex_application_parent_class)->startup (app);

    g_action_map_add_action_entries (G_ACTION_MAP (app),
                                     app_entries, G_N_ELEMENTS (app_entries),
                                     app);
    gtk_application_set_accels_for_action (GTK_APPLICATION (app),
                                           "app.quit",
                                           quit_accels);
    gtk_application_set_accels_for_action (GTK_APPLICATION (app),
                                           "app.open_file",
                                           open_accels);


    builder = gtk_builder_new_from_resource (
                                        "/org/gnome/gorex/gorex-app-menu.ui");
    app_menu = G_MENU_MODEL (gtk_builder_get_object (builder, "appmenu"));
    gtk_application_set_app_menu (GTK_APPLICATION (app), app_menu);
    g_object_unref (builder);
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
    G_APPLICATION_CLASS (class)->startup = gorex_application_startup;
}

GorexApplication *
gorex_application_new (void)
{
    return g_object_new (GOREX_TYPE_APPLICATION,
                         "application-id", "org.gtk.gorex-application",
                         "flags", G_APPLICATION_HANDLES_OPEN,
                         NULL);
}
