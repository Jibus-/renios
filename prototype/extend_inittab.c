// Automatically generated by generate_extend_inittab.py
#include "Python.h"

PyMODINIT_FUNC init_renpy(void);
PyMODINIT_FUNC initpyobjus(void);
PyMODINIT_FUNC initfont(void);
PyMODINIT_FUNC initdisplay(void);
PyMODINIT_FUNC initmouse(void);
PyMODINIT_FUNC initkey(void);
PyMODINIT_FUNC initscrap(void);
PyMODINIT_FUNC inittransform(void);
PyMODINIT_FUNC initdraw(void);
PyMODINIT_FUNC initcontroller(void);
PyMODINIT_FUNC initcolor(void);
PyMODINIT_FUNC initsurface(void);
PyMODINIT_FUNC initrect(void);
PyMODINIT_FUNC initjoystick(void);
PyMODINIT_FUNC initimage(void);
PyMODINIT_FUNC initgfxdraw(void);
PyMODINIT_FUNC initlocals(void);
PyMODINIT_FUNC initrwobject(void);
PyMODINIT_FUNC initerror(void);
PyMODINIT_FUNC initpygame_time(void);
PyMODINIT_FUNC initrender(void);
PyMODINIT_FUNC initevent(void);
PyMODINIT_FUNC initstyle(void);
PyMODINIT_FUNC initgldraw(void);
PyMODINIT_FUNC initglenviron_shader(void);
PyMODINIT_FUNC initgl(void);
PyMODINIT_FUNC initglrtt_fbo(void);
PyMODINIT_FUNC initgltexture(void);
PyMODINIT_FUNC initglrtt_copy(void);
PyMODINIT_FUNC initaccelerator(void);
PyMODINIT_FUNC initrender(void);
PyMODINIT_FUNC initstylesets(void);
PyMODINIT_FUNC initstyle_insensitive_functions(void);
PyMODINIT_FUNC initstyle_functions(void);
PyMODINIT_FUNC initstyle_activate_functions(void);
PyMODINIT_FUNC initstyle_selected_hover_functions(void);
PyMODINIT_FUNC initstyle_hover_functions(void);
PyMODINIT_FUNC initstyle_selected_idle_functions(void);
PyMODINIT_FUNC initstyle_selected_functions(void);
PyMODINIT_FUNC initstyleclass(void);
PyMODINIT_FUNC initstyle_selected_insensitive_functions(void);
PyMODINIT_FUNC initstyle_idle_functions(void);
PyMODINIT_FUNC initstyle_selected_activate_functions(void);
PyMODINIT_FUNC initftfont(void);
PyMODINIT_FUNC inittexwrap(void);
PyMODINIT_FUNC inittextsupport(void);
PyMODINIT_FUNC initrenpysound(void);

void renios_extend_inittab(void) {
    PyImport_AppendInittab("_renpy", init_renpy);
    PyImport_AppendInittab("pyobjus.pyobjus", initpyobjus);
    PyImport_AppendInittab("pygame_sdl2.font", initfont);
    PyImport_AppendInittab("pygame_sdl2.display", initdisplay);
    PyImport_AppendInittab("pygame_sdl2.mouse", initmouse);
    PyImport_AppendInittab("pygame_sdl2.key", initkey);
    PyImport_AppendInittab("pygame_sdl2.scrap", initscrap);
    PyImport_AppendInittab("pygame_sdl2.transform", inittransform);
    PyImport_AppendInittab("pygame_sdl2.draw", initdraw);
    PyImport_AppendInittab("pygame_sdl2.controller", initcontroller);
    PyImport_AppendInittab("pygame_sdl2.color", initcolor);
    PyImport_AppendInittab("pygame_sdl2.surface", initsurface);
    PyImport_AppendInittab("pygame_sdl2.rect", initrect);
    PyImport_AppendInittab("pygame_sdl2.joystick", initjoystick);
    PyImport_AppendInittab("pygame_sdl2.image", initimage);
    PyImport_AppendInittab("pygame_sdl2.gfxdraw", initgfxdraw);
    PyImport_AppendInittab("pygame_sdl2.locals", initlocals);
    PyImport_AppendInittab("pygame_sdl2.rwobject", initrwobject);
    PyImport_AppendInittab("pygame_sdl2.error", initerror);
    PyImport_AppendInittab("pygame_sdl2.pygame_time", initpygame_time);
    PyImport_AppendInittab("pygame_sdl2.render", initrender);
    PyImport_AppendInittab("pygame_sdl2.event", initevent);
    PyImport_AppendInittab("renpy.style", initstyle);
    PyImport_AppendInittab("renpy.gl.gldraw", initgldraw);
    PyImport_AppendInittab("renpy.gl.glenviron_shader", initglenviron_shader);
    PyImport_AppendInittab("renpy.gl.gl", initgl);
    PyImport_AppendInittab("renpy.gl.glrtt_fbo", initglrtt_fbo);
    PyImport_AppendInittab("renpy.gl.gltexture", initgltexture);
    PyImport_AppendInittab("renpy.gl.glrtt_copy", initglrtt_copy);
    PyImport_AppendInittab("renpy.display.accelerator", initaccelerator);
    PyImport_AppendInittab("renpy.display.render", initrender);
    PyImport_AppendInittab("renpy.styledata.stylesets", initstylesets);
    PyImport_AppendInittab("renpy.styledata.style_insensitive_functions", initstyle_insensitive_functions);
    PyImport_AppendInittab("renpy.styledata.style_functions", initstyle_functions);
    PyImport_AppendInittab("renpy.styledata.style_activate_functions", initstyle_activate_functions);
    PyImport_AppendInittab("renpy.styledata.style_selected_hover_functions", initstyle_selected_hover_functions);
    PyImport_AppendInittab("renpy.styledata.style_hover_functions", initstyle_hover_functions);
    PyImport_AppendInittab("renpy.styledata.style_selected_idle_functions", initstyle_selected_idle_functions);
    PyImport_AppendInittab("renpy.styledata.style_selected_functions", initstyle_selected_functions);
    PyImport_AppendInittab("renpy.styledata.styleclass", initstyleclass);
    PyImport_AppendInittab("renpy.styledata.style_selected_insensitive_functions", initstyle_selected_insensitive_functions);
    PyImport_AppendInittab("renpy.styledata.style_idle_functions", initstyle_idle_functions);
    PyImport_AppendInittab("renpy.styledata.style_selected_activate_functions", initstyle_selected_activate_functions);
    PyImport_AppendInittab("renpy.text.ftfont", initftfont);
    PyImport_AppendInittab("renpy.text.texwrap", inittexwrap);
    PyImport_AppendInittab("renpy.text.textsupport", inittextsupport);
    PyImport_AppendInittab("renpy.audio.renpysound", initrenpysound);
}
