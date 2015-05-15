#ifndef MGSOLVER_H
#define MGSOLVER_H
#include "grid.h"

#include <vector>
#include <iostream>
typedef double real;

using namespace std;

struct Stencil{
	
	//explicit inline stencil();
	real C;
	real N;
	real E;
	real W;
	real S;
	real NW;
	real NE;
	real SW;
	real SE;
};

class MGSolve
{
    private:
	//Grid* Grids;
	 //Grids* = new real [Grid(levels_)*Grid(levels_)]
	typedef std::vector<Grid> Grids;
		
    public:
        MGSolve();
        virtual ~MGSolve();
        MGSolve& operator=(const MGSolve& other);
	void setSmootherStencil(const Stencil& stencil);
	void setRestrictionStencil(const Stencil& stencil);
    	void setInterpolationStencil(const Stencil& stencil);
    private:
	void smooth(Grid& u,Grid& f,size_t iter);
	size_t levels_ ;
	//Grids = new real*
	Grids u_ ;
	Grids f_ ;
	Grids r_ ;
	Stencil RB_ ;
	Stencil R_ ;
	Stencil I_ ;
};

#endif // MGSOLVE_H
