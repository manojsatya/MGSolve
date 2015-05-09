#ifndef GRID_H
#define GRID_H

#include <cstdlib>
#include <vector>
typedef double real ;

class Grid
{
    public:
	explicit Grid();
	explicit Grid(size_t level);
		 Grid(const Grid& grid);
	       
        Grid& operator=(const Grid& other);

	//Get functions
	inline size_t xsize();
	inline size_t ysize();
	inline real hsize();   

	//Access functions
	inline real & operator()(size_t i, size_t j);
	inline real & operator()(size_t i, size_t j) const;    
		
	void fill (real value);
	
	

   private:
	size_t y_ ;
	size_t x_ ;
	int l;
	real h_ ;
	std::vector<real> v_ ;

};

#endif // GRID_H
