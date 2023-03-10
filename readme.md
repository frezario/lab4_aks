# Lab work 4: Parallelization using thread-safe deque.

Authors (team): 
Demchuk Nazar: https://github.com/frezario
Oleksiuk Liubomyr: https://github.com/Liubavaa

## Prerequisites

C/C++ compiler, CMake, python3

### Compilation

```
./comile.sh
```

### Usage

To run a script, use the following command:

```
python3 estimate_points.py
```

To run the c++ program, compile it and run as:

```
./comile.sh
cd bin
./integrate_parallel_queue
```


### Important!

To write a clean code, we've made a strong assumption that user will chose only those amount of points per interval, which can be factorized so that it will form a rectangle, and the sides of this rectangle are the factors of the init_steps_x and init_steps_y in .cfg file. That's because in the opposite case the computations used to determine the size of each subinterval become too complex and boilerplate. Also, the subintervals would be of different size and in some cases will be unrepresantable as rectangles.

### Results

<mark>DESCRIBE THE RESULTS OF THE WORK YOU DID. WHAT DID YOU LEARN OR FIND INTERESTING?</mark>
