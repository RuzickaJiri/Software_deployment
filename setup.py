import os
os.environ["CC"] = "c++"
from distutils.core import setup, Extension
module = Extension('my_wrapper_c', ["MyWrapper.cpp","Generation.cpp","Tree.cpp","Leaf.cpp","Node.cpp", "Operation.cpp", "Operator.cpp"],include_dirs=["src"],libraries=[])
module.extra_compile_args = []#,'-pg']

setup(name='my_wrapper_c',
	  version='1.0',
	  author='Baptiste Sorin',
	  author_email='thomas.loppinet@insa-lyon.fr',
	  ext_modules=[module])
