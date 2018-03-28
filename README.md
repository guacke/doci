DOCI: Doubly Occupied Configuration Interaction for ab initio quantum chemistry
===============================================================================

Building
--------

DOCI can be built with CMake and depends on BLAS and LAPACK.

It is parallelized for shared memory architectures with the Open Multi-Processing (OpenMP) API.

In your terminal, do:

    > cd /sourcefolder
    > git clone 'https://github.com/klgunst/doci.git'
    > cd doci
    > mkdir build
    > cd build
    > cmake ..
    > make

On the UGent HPC, use the cluster_compilation.sh script (no qsub required). Make sure to import the Intel modules before running the doci executable.

    > module load CMake/3.7.1-intel-2016b

To build with intermediate printing of energies of the davidson solver, do:

    > cmake -DDAVIDIT=ON ..

Building the documentation then happens by:

    > make doc


The number of threads used by openMP can be specified by setting the OMP_NUM_THREADS variable. e.g.:

    > export OMP_NUM_THREADS=4

To see the help for doci do:

    > ./doci --help

input-file
----------

A template for the input-file and some FCIDUMPS are given in the tests/ directory.

FCIDUMP          = path to the FCIDUMP file.

SOLVER           = The sparse solver to be used. (D for Davidson, CG for
                   conjugate gradient and CGP for conjugate gradient with
                   diagonal preconditioner). (default: D)

MAX_ITS          = Maximum number of iterations. (default: 200)

TOL              = The tolerance for convergence. (default: 1e-8)

DAVIDSON_KEEP    = The vectors to be kept after deflation in the Davidson
                   algorithm. (default: 2)

DAVIDSON_MAX_VEC = The maximum dimension of the subspace optimization before
                   Davidson deflates. (default: 30)
HF_INIT          = Set to 1 if initial guess should be the Hartree-Fock
                   solution. Set to 0 if the initial guess should be random.
                   (default: 1)
