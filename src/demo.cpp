#include <pybind11/pybind11.h>

// connect to Cpp
#include "List.h"
#include "work.h"

PYBIND11_MODULE(pybind_demo, m) {
    m.def("add_demo", &add_demo);
}
