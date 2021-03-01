import setuptools
from setuptools import setup
from setuptools.extension import Extension
from setuptools.command.build_py import build_py as setuptools_build_py
from Cython.Build import cythonize
#from distutils.command.build_ext import build_ext as du_build_ext
import os
import sys

class build_py(setuptools_build_py):
    def run(self):
        if os.system("./bootstrap") != 0:
            raise SystemExit("bootstrap failed")
        if os.system("./configure") != 0:
            raise SystemExit("configure failed, see config.log")
        self.distribution.package_data['ginac'].append('pynac.pxd')
        setuptools_build_py.run(self)

'''
class build_ext(du_build_ext):
    def run(self):
        from Cython.Build.Dependencies import cythonize
        self.distribution.ext_modules[:] = cythonize(
            self.distribution.ext_modules,
            language_level=3)
        du_build_ext.run(self)
'''

cpp_files = \
  "add archive assume basic \
  cmatcher constant context ex expair \
  expairseq exprseq fderivative function function_info \
  infinity inifcns inifcns_trig inifcns_zeta \
  inifcns_hyperb inifcns_trans inifcns_gamma inifcns_nstdsums \
  inifcns_orthopoly inifcns_hyperg inifcns_comb \
  lst matrix mpoly-giac mpoly-ginac \
  mpoly-singular mpoly mul normal numeric \
  operators power py_funcs \
  registrar relational remember \
  pseries print symbol upoly-ginac \
  utils wildcard templates infoflagbase sum \
  order useries"

libpynac_la_SOURCES = "add.cpp archive.cpp assume.cpp basic.cpp \
  cmatcher.cpp constant.cpp context.cpp ex.cpp expair.cpp \
  expairseq.cpp exprseq.cpp fderivative.cpp function.cpp function_info.cpp \
  infinity.cpp inifcns.cpp inifcns_trig.cpp inifcns_zeta.cpp \
  inifcns_hyperb.cpp inifcns_trans.cpp inifcns_gamma.cpp inifcns_nstdsums.cpp \
  inifcns_orthopoly.cpp inifcns_hyperg.cpp inifcns_comb.cpp \
  lst.cpp matrix.cpp mpoly-giac.cpp mpoly-ginac.cpp \
  mpoly-singular.cpp mpoly.cpp mul.cpp normal.cpp numeric.cpp \
  operators.cpp power.cpp py_funcs.cpp \
  registrar.cpp relational.cpp remember.cpp \
  pseries.cpp print.cpp symbol.cpp upoly-ginac.cpp \
  utils.cpp wildcard.cpp templates.cpp infoflagbase.cpp sum.cpp \
  order.cpp useries.cpp"

#libpynac_la_SOURCES = "print.cpp registrar.cpp context.cpp infoflagbase.cpp"
#libpynac_la_SOURCES += " basic.cpp"
#libpynac_la_SOURCES += " ex.cpp expairseq.cpp expair.cpp"
#libpynac_la_SOURCES += " numeric.cpp"
#libpynac_la_SOURCES += " power.cpp mul.cpp add.cpp"
#libpynac_la_SOURCES += " operators.cpp function.cpp fderivative.cpp"
#libpynac_la_SOURCES += " symbol.cpp lst.cpp relational.cpp wildcard.cpp archive.cpp utils.cpp inifcns.cpp infinity.cpp cmatcher.cpp constant.cpp py_funcs.cpp order.cpp mpoly.cpp remember.cpp"
#libpynac_la_SOURCES += " matrix.cpp pseries.cpp normal.cpp"

ginacinclude_HEADERS = "ginac.h py_funcs.h add.h archive.h assertion.h \
  basic.h class_info.h cmatcher.h constant.h container.h context.h \
  ex.h ex_utils.h expair.h expairseq.h exprseq.h \
  fderivative.h flags.h function.h \
  inifcns.h infinity.h lst.h matrix.h mpoly.h mul.h \
  normal.h numeric.h operators.h optional.hpp \
  power.h print.h pseries.h ptr.h registrar.h relational.h extern_templates.h \
  symbol.h version.h wildcard.h order.h templates.h \
  infoflagbase.h assume.h upoly.h useries.h useries-flint.h sum.h remember.h \
  tostring.h utils.h compiler.h pynac-config.h"

#ginacinclude_HEADER = "assertion.h ptr.h flags.h pynac-config.h class_info.h registrar.h context.h optional.hpp compiler.h print.h tostring.h infoflagbase.h version.h upoly.h"
#ginacinclude_HEADER += " basic.h"
#ginacinclude_HEADER += " ex.h ex_utils.h expairseq.h expair.h exprseq.h"
#ginacinclude_HEADER += " numeric.h power.h mul.h add.h operators.h function.h fderivative.h"
#ginacinclude_HEADER += " symbol.h lst.h relational.h wildcard.h archive.h utils.h inifcns.h infinity.h cmatcher.h constant.h py_funcs.h order.h mpoly.h remember.h container.h"
#ginacinclude_HEADER += " matrix.h pseries.h useries.h useries-flint.h normal.h"

cpp_files = \
  "add archive assume basic \
  cmatcher constant context ex expair \
  expairseq exprseq fderivative function function_info \
  infinity inifcns inifcns_trig inifcns_zeta \
  inifcns_hyperb inifcns_trans inifcns_gamma inifcns_nstdsums \
  inifcns_orthopoly inifcns_hyperg inifcns_comb \
  lst matrix mpoly-giac mpoly-ginac \
  mpoly-singular mpoly mul normal numeric \
  operators power py_funcs \
  registrar relational remember \
  pseries print symbol upoly-ginac \
  utils wildcard templates infoflagbase sum \
  order useries"

extensions = [
    Extension('ginac.gmptypes', sources=['ginac/gmptypes.pyx'],
        depends=['ginac/gmptypes.pxd'],
        extra_compile_args=["-lgmp", "-lgiac"],
        extra_link_args=["-lgmp" ,"-lgiac"],
        language=["c++"],
        include_dirs=[os.path.dirname(__file__) or ".", os.path.join(os.path.dirname(__file__), "ginac") or "ginac", "ginac"]
    ),
    Extension('ginac.pynac', sources=(
        ['ginac/pynac.pyx']
        #+ ['ginac/gmptypes.pyx']
        # From ginac/Makefile.am, removed .h files
        + [os.path.join('ginac/', f)
           for f in libpynac_la_SOURCES.split()]
        ),
        depends=(
        ['ginac/pynac.pxd']
        #+ ['ginac/gmptypes.pxd']
        + ['ginac/pynac_wrap.h']
        + [os.path.join('ginac/', f)
           for f in ginacinclude_HEADERS.split()]
        ),
        extra_compile_args=["-lgmp", "-lgiac", "-lflint", "-std=c++11"],
        extra_link_args=["-lgmp", "-lgiac", "-lflint", "-Lginac"],
        language=["c++"],
        include_dirs=[os.path.dirname(__file__) or ".", os.path.join(os.path.dirname(__file__), "ginac") or "ginac", "ginac"]
    ),
    ]

setup(ext_modules=cythonize(extensions),
      include_dirs = [os.path.dirname(__file__) or ".", "ginac"] + sys.path,
      packages = ['ginac'],
      package_dir = {'ginac': 'ginac'},
      package_data = {'ginac': ['*.pxd', '*.h', '*.hpp']},
      cmdclass = {'build_py': build_py}
                  #'build_ext': build_ext},
      )
