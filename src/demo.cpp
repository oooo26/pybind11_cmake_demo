#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

double add_demo(double a, double b) {
    return a+b;
}

PYBIND11_MODULE(pybind_demo, m) {
    m.def("add_demo", &add_demo);
}
