#include "Python.h"


PyObject *have_ccall(PyObject *self, PyObject *obj)
{
    return PyBool_FromLong(Py_TYPE(obj)->tp_flags & 2);
}


PyObject *dummy_call(PyObject *self, PyObject *args, PyObject *kwds)
{
    Py_RETURN_NONE;
}


PyObject *dummy_fastcall(PyObject *self, PyObject *const *args, Py_ssize_t nargs, PyObject *kwnames)
{
    Py_RETURN_NONE;
}


static PyMethodDef Callable_methods[] = {
    {"meth", (PyCFunction)dummy_call, METH_VARARGS | METH_KEYWORDS},
    {"fastmeth", (PyCFunction)dummy_fastcall, METH_FASTCALL | METH_KEYWORDS},
    {NULL}
};


static PyMethodDef module_methods[] = {
    {"call", (PyCFunction)dummy_call, METH_VARARGS | METH_KEYWORDS},
    {"fastcall", (PyCFunction)dummy_fastcall, METH_FASTCALL | METH_KEYWORDS},
    {"have_ccall", (PyCFunction)have_ccall, METH_O},
    {NULL}
};


static PyTypeObject CallableType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "Callable",
    sizeof(PyObject),                   /* tp_basicsize */
    0,                                  /* tp_itemsize */
    0,                                  /* tp_dealloc */
    0,                                  /* tp_ccalloffset */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    0,                                  /* tp_as_async */
    0,                                  /* tp_repr */
    0,                                  /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_hash */
    dummy_call,                         /* tp_call */
    0,                                  /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    0,                                  /* tp_flags */
    0,                                  /* tp_doc */
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
    0,                                  /* tp_richcompare */
    0,                                  /* tp_weaklistoffset */
    0,                                  /* tp_iter */
    0,                                  /* tp_iternext */
    Callable_methods,                   /* tp_methods */
    0,                                  /* tp_members */
    0,                                  /* tp_getset */
    0,                                  /* tp_base */
    0,                                  /* tp_dict */
    0,                                  /* tp_descr_get */
    0,                                  /* tp_descr_set */
    0,                                  /* tp_dictoffset */
    0,                                  /* tp_init */
    0,                                  /* tp_alloc */
    PyType_GenericNew,                  /* tp_new */
};


static struct PyModuleDef callables_module = {
    PyModuleDef_HEAD_INIT,
    "callables",
    NULL,
    -1,
    module_methods,
};


PyMODINIT_FUNC
PyInit_callables(void)
{
    PyObject *m = PyModule_Create(&callables_module);
    if (m == NULL) {
        return NULL;
    }

    if (PyType_Ready(&CallableType) < 0) {
        return NULL;
    }
    Py_INCREF(&CallableType);
    PyModule_AddObject(m, "Callable", (PyObject *)&CallableType);

    return m;
}
