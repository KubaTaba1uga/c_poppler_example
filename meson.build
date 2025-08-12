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
poppler_dep = dependency('poppler', version:'22.12.0', required: true)
fontconfig_dep = dependency('fontconfig', required: true)

c_poppler_demo_deps = [poppler_dep, fontconfig_dep]
c_poppler_demo_inc = include_directories('src')
executable('poppler_demo',
  sources,
  include_directories: c_poppler_demo_inc,
  dependencies: c_poppler_demo_deps,  
)
