#include <Python.h>//include the "Python.h" header before any other include
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <zlib.h>
#include <errno.h>
#include <iostream>
#include "def_PyC.h"

#include "Generation.h"

// Name for the cpp object "capsules"
#define NAME_CAPSULE_GENERATION "Generation"

// Receives a Python capsule for object Generation, and extracts the pointer of the C++ object


static Generation* GenerationPythonToC(PyObject* args){
  Generation* my_Generation ;
  PyObject* capsule;
  if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_Generation = (Generation*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_GENERATION);
	return my_Generation;
}

// Frees object Generation Python capsule

void GenerationCapsuleDestructor(PyObject* capsule){
  //Generation* my_Generation = (Generation*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_GENERATION);
  //delete my_Generation;
}

/* Calls the Print function of object A
static PyObject*  PrintA(PyObject* self, PyObject* args){
    A*  my_A = APythonToC(args);
    my_A->Print();
    Py_INCREF(Py_None);
    return Py_None;
}
*/


static PyObject*  PrintGeneration(PyObject* self, PyObject* args){
    Generation*  my_Generation = GenerationPythonToC(args);
    my_Generation->PrintTree();
    Py_INCREF(Py_None);
    return Py_None;
}


/*

static PyObject* SumAsInPyList(PyObject* self, PyObject* args){
    PyListObject* listOfAs;
    int a = 0;
    if (!PyArg_ParseTuple(args, "O", &listOfAs)){
        return NULL;
    }
    int size = PyList_Size((PyObject*) listOfAs);
    for (int i = 0; i < size; i++){
        PyObject* capsule = (PyObject*) PyList_GetItem( (PyObject*) listOfAs, (Py_ssize_t) i);
        A* my_A = (A*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
        a += my_A->a;
    }
    A* my_A = new A(a);
  	PyObject* capsule = PyCapsule_New(my_A, NAME_CAPSULE_A, ACapsuleDestructor);
  	return Py_BuildValue("Oi",capsule,a);
}
*/

//Create the Python Object Generation
static PyObject* CreateGeneration(PyObject* self, PyObject* args){
	int nbr_trees;
	if (!PyArg_ParseTuple(args, "h", &nbr_trees)){
		return NULL;
	}
	std::cout<<nbr_trees<<std::endl;
		Generation* my_Generation = new Generation((size_t)nbr_trees);
	printf("dsgsdfgdsfh\n");
	PyObject* capsule = PyCapsule_New(my_Generation, NAME_CAPSULE_GENERATION ,GenerationCapsuleDestructor);
	return capsule;

return NULL;

}





// Module functions {<python function name>, <function in wrapper>, <parameters flag>, <doctring>}
// https://docs.python.org/3/c-api/structures.html
static PyMethodDef module_funcs[] = {
    {"create_generation", (PyCFunction)CreateGeneration, METH_VARARGS, "Create an instance of class Generation\n\nArgs:\n\tnumber of equations in your generation (size_t): the parameter\n\nReturns:\n\t capsule: Object Generation capsule"},		
    {"printTree", (PyCFunction)PrintGeneration, METH_VARARGS, "Create an instance of class Generation\n\nArgs:\n\tNon\n\nReturns:\n\t capsule: Object Generation capsule"},
		{NULL, NULL, METH_NOARGS, NULL}
};

static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "my_wrapper_c",
        "my_wrapper_c module is simple example of C++ extension for python",
        sizeof(PyObject*),
				module_funcs,
				NULL,
        NULL,
        NULL,
        NULL
};

PyMODINIT_FUNC PyInit_my_wrapper_c(void){
    PyObject* module = PyModule_Create(&moduledef);
		return module;
}
