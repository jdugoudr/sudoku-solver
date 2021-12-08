# sudoku-solver
this a personal training on backtracking
use make to build the executable file.

# Algorythm
This solver find cells on the map with the less possibilties,
write one of this possibilities on the grid and restart the process.
The moment will come it don't have any possibilty on any cells.
This happens in two cases. The grid is filled successfully or it did a wrong choice.
In the second case. The program go back to the last choice it have done and try a new possibility.
If there are no more possibilty for this cell. It go back farther to lastest choice it did.
