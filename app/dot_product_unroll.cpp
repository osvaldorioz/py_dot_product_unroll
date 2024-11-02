#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>
#include <iostream>

//g++ -O2 -Wall -shared -std=c++20 -fPIC `python3.10 -m pybind11 --includes` dot_product_unroll.cpp -o dot_product_unroll`python3-config --extension-suffix` -I/path/to/eigen

namespace py = pybind11;

// Function to compute dot product with loop unrolling
double dot_product_unrolled(const double* a, const double* b, size_t n) {
    double result = 0.0;
    
    size_t i = 0;

    // Unroll the loop by a factor of 4
    for (i = 0; i <= n - 4; i += 4) {
        result += a[i] * b[i] + a[i+1] * b[i+1] + a[i+2] * b[i+2] + a[i+3] * b[i+3];
    }

    // Handle remaining elements if n is not divisible by 4
    for (; i < n; i++) {
        result += a[i] * b[i];
    }

    return result;
}

// Expose the function to Python
double dot_product_py(py::array_t<double> array_a, py::array_t<double> array_b) {
    // Get buffer info from the input arrays
    py::buffer_info a_info = array_a.request();
    py::buffer_info b_info = array_b.request();

    // Check if both arrays have the same length
    if (a_info.size != b_info.size) {
        throw std::runtime_error("Input vectors must have the same size");
    }

    // Perform dot product with loop unrolling
    return dot_product_unrolled(static_cast<double*>(a_info.ptr), static_cast<double*>(b_info.ptr), a_info.size);
}

PYBIND11_MODULE(dot_product_unroll, m) {
    m.def("dot_product", &dot_product_py, "Compute the dot product of two vectors with loop unrolling.");
}
