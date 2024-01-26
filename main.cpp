#include <Python.h>
#include <iostream>

static PyObject *hello(PyObject *self, PyObject *args)
{
    std::cout << "hello, world." << std::endl;
    
    Py_RETURN_NONE;
}


static PyMethodDef methods[] = {
  {"hello", hello, METH_VARARGS},
  {NULL, NULL},
};

PyMODINIT_FUNC PyInit_scikit_build_example(void)
{
    static struct PyModuleDef moduledef = {                   
        PyModuleDef_HEAD_INIT, "scikit_build_example", "", -1, methods,
    }; 

    PyObject *m = PyModule_Create(&moduledef);

    return m;
}

