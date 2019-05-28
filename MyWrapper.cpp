#include <Python.h>//include the "Python.h" header before any other include
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <zlib.h>
#include <errno.h>
#include <iostream>
#include "def_PyC.h"
#include"Tree.h"
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




static PyObject*  PrintGeneration(PyObject* self, PyObject* args){
  Generation*  my_Generation = GenerationPythonToC(args);
  my_Generation->PrintTree();
  Py_INCREF(Py_None);
  return Py_None;
}




static  std::vector<std::string> PythonStringtoC(PyListObject* pythonList){
	
  // get the size of the list
  int size = PyList_Size((PyObject*) pythonList);
  // iterate over the python list
  std::cout<<"size : "<<size<<std::endl;
  std::vector<std::string> xlabels;
	for (int j = 0; j < size; j++){
		// get the j-th element of the python list and convert it to long
    PyObject* obj = PyList_GetItem( (PyObject*) pythonList , (Py_ssize_t) j);//get the ellement

    //transform it to a string copied at : https://stackoverflow.com/questions/5356773/python-get-string-representation-of-pyobject

    PyObject* repr = PyObject_Repr(obj);
    PyObject* str = PyUnicode_AsEncodedString(repr, "utf-8", "~E~");
    const char *bytes = PyBytes_AS_STRING(str);
    xlabels.push_back (bytes);
    Py_XDECREF(repr);
    Py_XDECREF(str);
	}
	return xlabels;		

}

static  int* PythonListtoC(PyListObject* pythonList){
	
  // get the size of the list
  int size = PyList_Size((PyObject*) pythonList);
  // iterate over the python list
  int * clist= new int[size];
	for (int j = 0; j < size; j++){
		// get the j-th element of the python list and convert it to long
		int listItem = (int) PyLong_AsLong(PyList_GetItem( (PyObject*) pythonList , (Py_ssize_t) j));
		clist[j]=listItem;
	}
	return clist;		

}

static  bool** PythonListtoC2D(PyListObject* pythonList){
	
  // get the size of the list
  int size1 = PyList_Size((PyObject*) pythonList);
  // iterate over the python list
  int size2 = PyList_Size((PyObject*)PyList_GetItem( (PyObject*) pythonList , (Py_ssize_t) 0));
  bool** clist = new bool*[size1];
  for(int i = 0; i < size1; ++i)
    clist[i] = new bool[size2];
    
	for (int j = 0; j < size1; j++){
		for(int i=0;i<size2;++i){
			PyObject* tab = PyList_GetItem( (PyObject*) pythonList , (Py_ssize_t) j);
			PyObject* item = PyList_GetItem(tab , (Py_ssize_t) i);
			int listItem = (int) PyLong_AsLong(item);
			clist[j][i]=listItem;
		}
	}
	return clist;		

}



//Create the Python Object Generation
static PyObject* CreateGeneration(PyObject* self, PyObject* args){
	int nbr_trees;
	PyListObject* listOfString;
	
	if (!PyArg_ParseTuple(args, "hO", &nbr_trees,&listOfString)){
		printf("We have a problem my friend\n");
		return NULL;
	}
	int size = PyList_Size((PyObject*) listOfString);
	// iterate over the python list
	std::cout<<"size : "<<size<<std::endl;
	
	PythonStringtoC(listOfString); 
 	std::cout<<nbr_trees<<std::endl;
	std::vector<std::string> xlabels={"x1","x2"};
	Generation* my_Generation = new Generation((size_t)nbr_trees,true,xlabels);

	printf("dsgsdfgdsfh\n");
	PyObject* capsule = PyCapsule_New(my_Generation, NAME_CAPSULE_GENERATION ,GenerationCapsuleDestructor);
	return capsule;

return NULL;

}







static PyObject* ComputeFitness(PyObject* self, PyObject* args){
	
	Generation*  my_Generation = GenerationPythonToC(args);
	PyObject* listOfFits = PyList_New((Py_ssize_t) my_Generation->size());
	float* fitness=my_Generation->fit();
	
	for(size_t i=0;i<my_Generation->size();++i){ 
	 
	  PyList_SetItem( listOfFits, (Py_ssize_t)i, Py_BuildValue("f", fitness[i]));

	}
	

  return listOfFits;

}

static PyObject* MaxFitness(PyObject* self, PyObject* args){
	
	Generation*  my_Generation = GenerationPythonToC(args);

	float* fitness=my_Generation->fit();
	float fittest=0;
	
	for(size_t i=0;i<my_Generation->size();++i){ 
		if(fitness[i]>fittest)
			fitness[i]=fittest;
	}
	

  return Py_BuildValue("f",fittest);

}

static PyObject* Evolve(PyObject* self, PyObject* args){
  int record;
  int n;

  PyListObject* listOfBoolx;
  PyListObject* listOfInty;
  PyObject* generationPy;
  //int n, bool x[][10],int y[], int x_size, int record, std::string* bestIndividual_ 
  if (!PyArg_ParseTuple(args, "iiOOO", &record, &n,&listOfBoolx, &listOfInty,&generationPy)){
	  std::cout<<"if i see this a will be sad"<<std::endl;
	   
	  }
	  
  bool** boolxC= PythonListtoC2D(listOfBoolx);
  int* yC=PythonListtoC(listOfInty);
  int x_size = PyList_Size((PyObject*) listOfBoolx);
  std::string* bestIndividual= new std::string[n] ;
    
    std::vector<std::string> xlabels={"x1","x2"};
  Generation* thisGeneration = (Generation*) PyCapsule_GetPointer(generationPy,NAME_CAPSULE_GENERATION);	



  Generation* newone =new Generation(5,true,xlabels);
  newone = thisGeneration->Evolve(n,boolxC,yC,x_size,record,bestIndividual);
  std::cout<<"Test conformity"<<std::endl;
  newone->PrintTree();

  PyObject* capsule = PyCapsule_New(newone, NAME_CAPSULE_GENERATION ,GenerationCapsuleDestructor);
     
  return capsule;
    
}
	

  








// Module functions {<python function name>, <function in wrapper>, <parameters flag>, <doctring>}
// https://docs.python.org/3/c-api/structures.html
static PyMethodDef module_funcs[] = {
    {"create_generation", (PyCFunction)CreateGeneration, METH_VARARGS, "Create an instance of class Generation\n\nArgs:\n\tnumber of equations in your generation (size_t): the parameter\n\nReturns:\n\t capsule: Object Generation capsule"},		
    {"printTree", (PyCFunction)PrintGeneration, METH_VARARGS, "Create an instance of class Generation\n\nArgs:\n\tNon\n\nReturns:\n\t capsule: Object Generation capsule"},
    {"evolve",(PyCFunction) Evolve, METH_VARARGS, "Evolve:\n Args: boolean record,int size, 2D boolean table,result table, generation \n\nReturns : A new evolved Generation."},
    {"compute_fitness",(PyCFunction) ComputeFitness, METH_VARARGS, "Computes the fitness of every function in a given generation\n\nArgs : None\n\nReturns : an list of integers representing the fitness of every member of the generation."},
	 {"compute_best_fitness",(PyCFunction) MaxFitness, METH_VARARGS, "Computes the fitness of the best function in a given generation\n\nArgs : None\n\nReturns : an list of integers representing the fitness of every member of the generation."},
	
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
