#include "RQTree.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    const size_t N = 2, T = 4; // coord | divisions RQT
    float limits[][N] = { {100,100} , {0,0} };
    float coord[][N] = { {100,100},{0,0},{0,-10},{-200,-50},{666,85},{85,900},{700,100}}; // List of coord
    const size_t M = sizeof(coord)/sizeof(coord[0]);
    

    Point topLeft(limits[0]); Point botRight(limits[1]);
/*
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
 */

    RQTree myRQTree(3, topLeft, botRight);


    myRQTree.m_root->m_nodes[0]->m_nodes[1]->m_nodes[0]->m_topLeft.printContent();
    myRQTree.m_root->m_nodes[0]->m_nodes[1]->m_nodes[0]->m_botRight.printContent();
    
    myRQTree.m_root->m_nodes[0]->m_nodes[1]->m_nodes[1]->m_topLeft.printContent();
    myRQTree.m_root->m_nodes[0]->m_nodes[1]->m_nodes[1]->m_botRight.printContent();
    myRQTree.m_root->m_nodes[0]->m_nodes[1]->m_nodes[2]->m_topLeft.printContent();
    myRQTree.m_root->m_nodes[0]->m_nodes[1]->m_nodes[2]->m_botRight.printContent();
    myRQTree.m_root->m_nodes[0]->m_nodes[1]->m_nodes[3]->m_topLeft.printContent();
    myRQTree.m_root->m_nodes[0]->m_nodes[1]->m_nodes[3]->m_botRight.printContent();

    //myRQTree.m_root->m_nodes[1]->m_nodes[1]->m_topLeft.printContent();
    //myRQTree.m_root->m_nodes[1]->m_nodes[1]->m_botRight.printContent();
//
    //myRQTree.m_root->m_nodes[1]->m_nodes[1]->m_nodes[1]->m_topLeft.printContent();
    //myRQTree.m_root->m_nodes[1]->m_nodes[1]->m_nodes[1]->m_botRight.printContent();



/*
    KDTree<N,int> myKDTree;

    for (i = 0; i < M; ++i)
        std::cout << "Insert Status: " << myKDTree.insert(myPoints[i]) << endl; // Insert Points with status
    
    // Status 0 punto repetido

    Node<N,int>* myNode = nullptr;
    int coord_key[2] = {75,85};  // ##### KEY

    Point<N,int> key(coord_key);

    std::cout << "\n----- Evaluate - Nearest Neighbor -----\n";
    std::cout << "KEY => ";
    key.printContent();
    double distance = myKDTree.nearest_neighbor(key,myNode); 
    std::cout << "Distance: " << distance << "\n";
    std::cout << "NN: ";
    myNode->m_point.printContent();

    std::cout << "\n----- Evaluate - K Nearest Neighbor -----\n";
    std::size_t k = 3;
    myKDTree.k_nearest_neighbor(k,key);

    std::cout << "K( "<< k << " )NN\n";

    for (std::map<double,Point<N,int>*>::iterator it=myKDTree.knn.begin(); it!=myKDTree.knn.end(); ++it)
    {    
        std::cout << it->first << " => ";
        it->second->printContent();
        std::cout << '\n';
    }

    k = 2;
    std::cout << "K( "<< k << " )NN\n";
    
    myKDTree.knn.clear();

    myKDTree.k_nearest_neighbor(k,key);

    for (std::map<double,Point<N,int>*>::iterator it=myKDTree.knn.begin(); it!=myKDTree.knn.end(); ++it)
    {    
        std::cout << it->first << " => ";
        it->second->printContent();
        std::cout << "\n";
    }

    std::cout << "\n----- Evaluate - Range Query -----\n";

    double max = 100.f;
    std::cout << "Range: " << max << "\n";
    myKDTree.range_query(max,key);

    for (std::map<double,Point<N,int>*>::iterator it=myKDTree.rq.begin(); it!=myKDTree.rq.end(); ++it)
    {    
        std::cout << it->first << " => ";
        it->second->printContent();
        std::cout << "\n";
    }

    myKDTree.rq.clear();

    std::cout << "\n----- Evaluate - Delete -----\n";
    std::cout << "Delete Status: " << myKDTree.del(myPoints[0]) << "\n";
    std::cout << "Delete Status (same Point): " << myKDTree.del(myPoints[0]) << "\n";
    std::cout << "New Root: ";
    myKDTree.get_root()->m_point.printContent();
    std::cout << "Level Root: " << myKDTree.get_root()->m_level << "\n";
*/
    return 0;
}