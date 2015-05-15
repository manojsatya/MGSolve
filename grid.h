#ifndef GRID_H
#define GRID_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <assert.h>
#include <iostream>

using namespace std;
typedef double real ;


class Grid
{
	
    public:
	explicit Grid();
	explicit Grid(size_t level);
		 Grid(const Grid &grid);
	virtual ~Grid();       
        Grid& operator=(const Grid& other);
	//Grid& operator+=(const Grid& other);
	//Grid& operator-=(const Grid& other);
	//Grid& operator*=(const Grid& other);
	//Get functions
	inline size_t xsize() const {return x_;}
	inline size_t ysize()const {return y_;}
	inline real hsize()const {return h_;}
	inline real h2size()const {return h2_;}   

	//Access functions
	inline real& operator()(size_t i, size_t j);
	inline real operator()(size_t i, size_t j) const;    
		
	void fill (real value);
	void setBoundary();	
	void print();
	
	
   private:
	size_t y_ ;
	size_t x_ ;
	int l;
	real h_ ;
	real h2_;
	real* v_;

};

inline real& Grid::operator()(size_t i, size_t j){
	//std::cout <<"assert y_:"<< y_ <<std::endl;
	//std::cout <<"assert x_:"<< x_ <<std::endl;
	//std::cout <<"assert i:"<< i <<std::endl;
	//std::cout <<"assert j:"<< j <<std::endl;	
	assert (i < y_);
	assert (j < x_);
	
	return v_[i*x_+j];
}

inline real Grid::operator()(size_t i, size_t j)const {
	assert (i < y_);
	assert (j < x_);
	return v_[i*x_+j];
}


#endif // GRID_H
