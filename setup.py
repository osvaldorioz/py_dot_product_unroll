from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        "dot_product_unroll",  # Name of the module
        ["dot_product_unroll.cpp"],  # Source file
        include_dirs=[pybind11.get_include()],
        language="c++"
    ),
]

setup(
    name="dot_product_unroll",
    ext_modules=ext_modules
    #cmdclass={"build_ext": pybind11.setup_helpers.build_ext},
)