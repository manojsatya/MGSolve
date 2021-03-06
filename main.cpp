#include "grid.h"
#include "mgsolver.h"

#include <iostream>
#include <cstdlib>



using namespace std;

size_t ll,nov,pre,post;

int main(int argc , char **argv)
{

if(argc != 3){ cout << "Improper input " << endl ; exit(EXIT_FAILURE);}

if(argc == 3){ 
ll = atoi(argv[1]);
nov = atoi(argv[2]); }

Grid initialGrid(ll);
initialGrid.setBoundary();
Grid f(ll);
Grid u(initialGrid);
u.setBoundary();
MGSolve solution;
solution.solve(u,f,nov,pre,post);
u.print();


    cout << "Hello world!" << endl;
    return 0;
}
