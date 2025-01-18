/*** Template file for Custom Classes ***/

/* Replace the keywords below
 *
 * Libary: liblib.h
 * Object: Cstm, Clss, cstm, clss, CSTM, CLSS
 * Parent: Parpar, Namnam, parpar, namnam, PARPAR, NAMNAM */

#include "cstm-clss.h"

/*** Class Struct and Enums ***/
struct _CstmClss
{
    ParparNamnam parent;
    char* salute_message;
};
G_DEFINE_FINAL_TYPE(CstmClss, cstm_clss, PARPAR_TYPE_NAMNAM);

enum CstmClssSignals
{
    SIG_0,
    SIG_SALUTE,
    SIG_N,
};
static guint signals[SIG_N];

enum CstmClssProperties
{
    PROP_0,
    PROP_SALUTE_MESSAGE,
    PROP_N,
};
static GParamSpec* properties[PROP_N];
/*** Class Struct and Enums ***/

/*** Getter - Setter ***/
static void cstm_clss_set_property(GObject* object, guint property_id, const GValue* value, GParamSpec* pspec)
{
    CstmClss* self = CSTM_CLSS(object);
    switch (property_id)
    {
        case PROP_SALUTE_MESSAGE: {
            g_free(self->salute_message);
            self->salute_message = g_strdup(g_value_get_string(value));
        }
        break;
    }
}
static void cstm_clss_get_property(GObject* object, guint property_id, GValue* value, GParamSpec* pspec)
{
    CstmClss* self = CSTM_CLSS(object);
    switch (property_id)
    {
        case PROP_SALUTE_MESSAGE: {
            g_value_set_string(value, self->salute_message);
        }
        break;
    }
}
/*** Getter - Setter ***/

/*** Disposal ***/
static void cstm_clss_dispose(GObject* object)
{
    CstmClss* self = CSTM_CLSS(object);
    g_clear_pointer(&self->salute_message, g_free);
    G_OBJECT_CLASS(cstm_clss_parent_class)->dispose(object);
}
static void cstm_clss_finalize(GObject* object)
{
    CstmClss* self = CSTM_CLSS(object);
    G_OBJECT_CLASS(cstm_clss_parent_class)->finalize(object);
}
/*** Disposal ***/

/*** Init ***/
static void cstm_clss_init(CstmClss* self)
{
    self->salute_message = g_strdup("Hello!");
}

static void cstm_clss_class_init(CstmClssClass* klass)
{
    G_OBJECT_CLASS(klass)->set_property = cstm_clss_set_property;
    G_OBJECT_CLASS(klass)->get_property = cstm_clss_get_property;
    G_OBJECT_CLASS(klass)->dispose = cstm_clss_dispose;
    G_OBJECT_CLASS(klass)->finalize = cstm_clss_finalize;

    properties[PROP_SALUTE_MESSAGE] = g_param_spec_string("salute-message",
                                                          "salute-message",
                                                          "salute-message",
                                                          "Hello!",
                                                          G_PARAM_READWRITE);
    g_object_class_install_properties(G_OBJECT_CLASS(klass), PROP_N, properties);

    signals[SIG_SALUTE] = g_signal_new("salute",
                                       G_TYPE_FROM_CLASS(klass),
                                       G_SIGNAL_RUN_LAST,
                                       0,
                                       NULL,
                                       NULL,
                                       NULL,
                                       G_TYPE_NONE,
                                       0);
}
/*** Init ***/

/*** Public Functions ***/
CstmClss* cstm_clss_new()
{
    return g_object_new(CSTM_TYPE_CLSS, NULL);
}

void cstm_clss_salute(CstmClss* cstw)
{
    g_print("%s\n", cstw->salute_message);
    g_signal_emit(cstw, signals[SIG_SALUTE], 0, NULL);
}
/*** Public Functions ***/
