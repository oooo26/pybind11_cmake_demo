from .pybind_demo import add_demo

class demo_class:
    def __init__(self):
        pass

    def add(self, a, b):
        return add_demo(a, b)
