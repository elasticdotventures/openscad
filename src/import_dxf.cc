#include "import.h"
#include "grid.h"
#include "printutils.h"
#include "calc.h"
#include "Polygon2d.h"
#include "dxfdata.h"

Polygon2d *import_dxf(const std::string &filename)
{
    //We now assume that brlcad can pass dxf data through this
    //My thought is we may create a class for each entity to store the data?
    
    //brlcad::entities_list *entities = brlcad::read_dxf_file(filename.c_str());
    //Assume we have receive a data of square with a length of a 2.
    
    //To make it simple, I will ignore other enitities. Basically just use four
    //lines to form the square

    // These are other expected values that we should get from just the line entity
    // std::string curr_layer_name
    // std::string curr_color;
    // double scale;
    
    auto poly = new Polygon2d();
	Grid2d<std::vector<int>> grid(GRID_COARSE);
    std::vector<double> xCoord = {-1, -1, 1, -1};
	std::vector<double> yCorrd = {-1, 1, 1, -1};
    int vertexNum = 4;
    Outline2d outline;
    for(size_t i = 0; i < vertexNum; i++){
        grid.align(xCoord.at(i), yCorrd.at(i));
        //what does the grid.align do?
        outline.vertices.push_back(Vector2d(xCoord.at(i),yCorrd.at(i)));
    }
    poly->addOutline(outline);
    return poly;
}
