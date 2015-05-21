#include "mgsolver.h"
#include "grid.h"
#include <iostream>

using namespace std;

MGSolve::MGSolve()
{
    //ctor
}

MGSolve::MGSolve(size_t level){levels_ = level;
for(size_t i=0;i <levels_;i++){
	std::cout << "inside resize" << std::endl;	
	
		u_[i].resizeGrid(i);
		f_[i].resizeGrid(i);
		r_[i].resizeGrid(i);
}
}

MGSolve& MGSolve::operator=(const MGSolve& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void MGSolve::setRestrictionStencil(const Stencil& stencil){
	
	R_ = stencil;
	R_.C = 0.25;
	R_.N = 0.125;
	R_.W = 0.125;
	R_.E = 0.125;
	R_.S = 0.125;
	R_.NW = 0.0625;
	R_.NE = 0.0625;
	R_.SW = 0.0625;
	R_.SE = 0.0625;
}

void MGSolve::setSmootherStencil(const Stencil& stencil){
	
	RB_ = stencil;
	RB_.N = 0.25; 
	RB_.S = 0.25;
	RB_.W = 0.25;
	RB_.E = 0.25;
}

void MGSolve::setInterpolationStencil(const Stencil& stencil){
	
	I_ = stencil;
	I_.C = 1.0;
	I_.N = 0.5;
	I_.W = 0.5;
	I_.E = 0.5;
	I_.S = 0.5;
	I_.NW = 0.25;
	I_.NE = 0.25;
	I_.SW = 0.25;
	I_.SE = 0.25;	
}

void MGSolve::solve(Grid& u,const Grid& f,size_t cycles,size_t pre,size_t post){
	pre = 2;post=1;	
	for(size_t cycle = 0;cycle<cycles;++cycle){
	smooth(u,f,pre);
	//calcResidual(u,f,r_[levels_-1]);
	}
}

void MGSolve::smooth(Grid& u,const Grid& f,size_t iter){
	//iter = 2;

	const size_t size= (u.xsize()* u.ysize());
	std::cout <<"size in Mgsolver:"<< size << std::endl;
	real h2 = u.h2size();
	std::cout <<"h2 in Mgsolver"<< h2 << std::endl;
	std::cout <<"iter:"<< iter << std::endl;
	std::cout <<"xsize:"<< u.xsize() << std::endl;
	for(size_t it = 0 ; it < iter ; ++it){

		for(size_t j=1;j<u.ysize()-1;++j)				
			for(size_t i= 1+(j%2) ; i < u.xsize()-1;i +=2)
			{
			//	std::cout <<"i:"<< i << std::endl;
			//	std::cout <<"j:"<< j << std::endl;
				u(i ,j) = 0.25 * ( h2 * f(i ,j) + 
						u(i-1,j) +
						u(i+1,j) +
						u(i,j+1) +
						u(i ,j-1));
		std::cout << u(i,j) << std::endl;}
		

	for(size_t j=1;j<u.ysize()-1;++j)
		for(size_t i= 2 - (j%2) ; i <u.xsize()-1;i+=2){

		u(i ,j) = 0.25 * ( h2 * f(i ,j) +
					u((i-1),j) +
					u((i+1),j) +
					u(i,(j+1)) +
					u(i ,(j-1)));
		//std::cout << u(i,j) << std::endl;
		}
	     		
	}

	//u.print();
}


void MGSolve::calcResidual(const Grid& u,const Grid& f,Grid& r){

	std::cout << "r_.xsize():"<< r.xsize() << std::endl; 

}


/*void MGSolve::print(Grid& u){

	const size_t size= (u.xsize()* u.ysize());	
	for(size_t j=0 ; j< size ; ++j)
	for(size_t i=0;i<size;++i){
		cout << "u["<<i + size*j<<"]="<< u(i,j) << endl ; // bottom
	}
}*/

/*void solve(Grid& u,const Grid& f,size_t cycles,size_t pre,size_t post){

	pre = 2;post=1;	
	smooth(u,f,pre);
}*/


MGSolve::~MGSolve()
{
    //dtor
}






