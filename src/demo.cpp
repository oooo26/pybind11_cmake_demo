#include <pybind11/pybind11.h>

// test more head files
#include <iostream>
#include <typeinfo>
#include <vector>
#include <tuple>
#include <omp.h>
#include <Eigen/Eigen>

using namespace std;
using namespace Eigen;

double add_demo(double a, double b) {
    return a+b;
}

PYBIND11_MODULE(pybind_demo, m) {
    m.def("add_demo", &add_demo);
}
