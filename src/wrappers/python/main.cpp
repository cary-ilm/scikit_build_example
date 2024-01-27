#include <Python.h>
#include <iostream>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

static PyObject *hello(PyObject *self, PyObject *args)
{
    std::cout << "hello, world." << std::endl;
    
    Py_RETURN_NONE;
}

static PyMethodDef methods[] = {
  {"hello", hello, METH_VARARGS},
  {NULL, NULL},
};

PyMODINIT_FUNC PyInit_Hello(void)
{
    static struct PyModuleDef moduledef = {                   
        PyModuleDef_HEAD_INIT, "Hello", "", -1, methods,
    }; 

    PyObject *m = PyModule_Create(&moduledef);

    PyModule_AddStringConstant(m, "__version__", MACRO_STRINGIFY(VERSION_INFO));

    return m;
}

