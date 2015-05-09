#include "grid.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <vector>
#include <assert.h>


using namespace std;

size_t ll,nov;

int main(int argc , char **argv)
{

if(argc != 3){ cout << "Improper input " << endl ; exit(EXIT_FAILURE);}

if(argc == 3){ 
ll = atoi(argv[1]);
nov = atoi(argv[2]); }

Grid A(ll);


    cout << "Hello world!" << endl;
    return 0;
}
