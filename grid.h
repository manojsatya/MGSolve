#ifndef GRID_H
#define GRID_H

#include <cstdlib>
#include <vector>
#include <cmath>
#include <assert.h>

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
	assert (i < x_);
	assert (j < y_);
	return v_[i + j* xsize()];
}

inline real Grid::operator()(size_t i, size_t j)const {
	assert (i < x_);
	assert (j < y_);
	return v_[i + j* xsize()];
}


#endif // GRID_H
