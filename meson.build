# C poppler demo
# ******************************************************************************
# *    Project
# ******************************************************************************
project('c_poppler_demo', 'c',
         version: '0.0.1',
	 meson_version: '>=1.0.1',
	 default_options: [
            'werror=true',
            'c_std=c11',
         ],
)

# ******************************************************************************
# *    App
# ******************************************************************************
subdir('src')
gpoppler_dep = dependency('poppler-glib', version:'22.12.0', required: true)
glib_dep = dependency('glib-2.0', required: true)
gio_dep = dependency('gio-2.0',  required: true)

c_poppler_demo_deps = [gpoppler_dep, glib_dep, gio_dep]
c_poppler_demo_inc = include_directories('src')
executable('poppler_demo',
  sources,
  include_directories: c_poppler_demo_inc,
  dependencies: c_poppler_demo_deps,  
)
