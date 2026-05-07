./sorting_lab all

./sorting_lab insertion.random
./sorting_lab insertion.random insertion.falling
./sorting_lab quicksort_median3.rising stdsort.random


source .venv/bin/activate
python plot_graphs.py
