#include "RQTree.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    const size_t N = 2, T = 4; // coord | divisions RQT
    float limits[][N] = { {100,100} , {0,0} };

    float coord[][N] = {    {25,10},{70,0},{0,-10},{-200,-50},{666,85},{85,900},{700,100}
                            ,{23.5,19.8}}; // List of coord

    const size_t M = sizeof(coord)/sizeof(coord[0]);
    

    Point topLeft(limits[0]); Point botRight(limits[1]);

    vector<Point> myPoints(M); // Points

    size_t i;

    std::cout << "Points: \n";
    for (i = 0; i < M; ++i)
        myPoints[i] = Point(coord[i]); // Make Points
    
    for (i = 0; i < M; ++i)
        myPoints[i].printContent();

    cout << "......." << endl;
    for (i = 0; i < M; ++i)
        cout << overlap(topLeft,botRight,myPoints[i]) << endl; 


    RQTree myRQTree(3, topLeft, botRight);

    for (i = 0; i < M; ++i)
        std::cout << "Insert Status: " << myRQTree.insert(myPoints[i]) << endl;

    vector<size_t> query = {1,4,4,4};
    std::cout << myRQTree.m_root->m_nodes[2]->m_nodes[0]->m_numpoints << endl;
    
    std::cout << "Query Status: " << myRQTree.query(query) << endl;

    return 0;
}