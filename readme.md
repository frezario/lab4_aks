# Lab work 4: Parallelization using thread-safe deque.

Authors (team): 
Demchuk Nazar: https://github.com/frezario
Oleksiuk Liubomyr: https://github.com/Liubavaa

### Prerequisites

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

To write a clean code, we've made a strong assumption that user will chose only those amount of points per interval, which is reasonable to build a rectangle interval with. That's because in the opposite case the computations used to determine the size of each subinterval become too complex and boilerplate. Also, the subintervals would be of different size and in some cases will be unrepresantable as rectangles.

### Results

We've made an alternative to prvious integral computating program using thread-safe queue. Although, the result is not better than previous one, we've learned another good general way to parallelize computations.
