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
cmake = import('cmake')
opt_var = cmake.subproject_options()
opt_var.add_cmake_defines({'ENABLE_GPGME':'OFF',
                           'ENABLE_QT5':'OFF',
			   'ENABLE_QT6':'OFF',
			   'ENABLE_LCMS':'OFF',
			   'ENABLE_LIBCURL':'OFF',
			   })
# opt_var.append_compile_args('c', '-D_GNU_SOURCE')
poppler_proj = cmake.subproject('poppler', options: opt_var)
poppler_dep = poppler_proj.dependency('poppler')

poppler_dep = dependency('poppler',
  fallback: ['poppler', 'poppler_dep'],
  required: true,
)

c_poppler_demo_deps = [poppler_dep]
c_poppler_demo_inc = include_directories('include', 'src')
executable('poppler_demo',
  sources,
  include_directories: c_poppler_demo_inc,
  dependencies: c_poppler_demo_deps,  
)
