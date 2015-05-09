#ifndef MGSOLVER_H
#define MGSOLVER_H
#include "grid.h"

#include <vector>
class MGSolve
{
    private:
	typedef std::vector<Grid> Grids;	
    public:
        MGSolve();
        virtual ~MGSolve();
        MGSolve& operator=(const MGSolve& other);
    
    private:
};

#endif // MGSOLVE_H
