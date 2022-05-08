#include "RQTree.hpp"

#include <iostream>
#include <vector>


int main()
{

    const size_t N = 2, T = 3; // coord | divisions RQT
    float limits[][N] = { {100,100} , {0,0} };

    float coord[][N] ={ {20.07,83.52},{80.22,91.68},{84.86,95.95},{84.12,82.22},{81.52,70.89},{90.43,54.74},    
                        {80.59,32.09},{20,20},{41.42,45.09},{37.5,75},{75,37.5},{25,25},
                        {900,900},{-12,1},{-2.1,-1}
                        }; // List of coord | 

    const std::size_t M = sizeof(coord)/sizeof(coord[0]);
    

    Point topLeft(limits[0]); Point botRight(limits[1]);

    std::vector<Point> myPoints(M); // Points

    std::size_t i;

    std::cout << "Points: \n";
    for (i = 0; i < M; ++i)
        myPoints[i] = Point(coord[i]); // Make Points
    
    RQTree myRQTree(T, topLeft, botRight);

    for (i = 0; i < M; ++i)
        std::cout << "Insert Status: " << myRQTree.insert(myPoints[i]) << std::endl;

    std::vector<std::size_t> query = {1};
    std::cout << "Query All: " << myRQTree.query(query) << std::endl;

    std::vector<std::size_t> query2 = {1, 1, 1, 2};
    std::cout << "Query All: " << myRQTree.query(query2) << std::endl;

    std::vector<std::size_t> query3 = {1,2};
    std::cout << "Query All: " << myRQTree.query(query3) << std::endl;

    std::vector<std::size_t> query4 = {1,3,4};
    std::cout << "Query All: " << myRQTree.query(query4) << std::endl;

    std::vector<std::size_t> query5 = {1,4,4,1};
    std::cout << "Query All: " << myRQTree.query(query5) << std::endl;

    return 0;
}