# sudoku-solver
# this a personal training on backtracking
# use make to build the executable file.

# This solver calcul the cell of the map with the less possibilties,
# write one of this possibilities on the grid and restart the process.
# The moment will come you don't have any possibilty on any cell.
# This happens in two cases. You fill the grid successfully or you did
# a wrong choice at one moment.
# If is the seconde case. The program go back to the last choice it do and
# try a new possibility. If there are no more possibilty for this case. It 
# go back farther to lastest choice it did.
