/*
 * QuadTree
 * Chillitupa Quispihuanca, Alfred Addison
 * Estructuras de Datos Avanzadas
 * CCOMP6-1
 * C++
 * KDTree.hpp
*/
#ifndef _RQTREE_HPP_
    #define _RQTREE_HPP_
    #include "Node.hpp"
    
    #include <vector>

    class RQTree {
        private:
            
            Point m_topLeft; Point m_botRight;
            void build( std::size_t , Node*&, Point, Point, std::size_t R = 1);
            
            bool insert(Point, Node*);

        public:
            Node* m_root = nullptr;
            std::size_t m_size;
            std::size_t m_dimension;
           
            /* Constructor and destructor */
            RQTree  ( std::size_t, Point, Point );
            //~RQTree ();

            /* Main functions */
            bool insert(Point);
            int query(std::vector<std::size_t>);
            /* Getters */
           
            /* Utilities */
            bool is_empty();
            
            /* Overloads */

    };

    RQTree::RQTree( std::size_t T, Point topLeft, Point botRight)
    {
        m_size = T;
        m_topLeft = topLeft;
        m_botRight = botRight;

        build(0, m_root, topLeft, botRight);
    }

    void RQTree::build( std::size_t T , Node* &node, Point topLeft, Point botRight,  std::size_t R)
    {
        node = new Node(T, topLeft, botRight, R);
        
        if ( T == m_size) return;

        Point newtopLeft = topLeft; Point newbotRight = botRight;
       
        newbotRight[0] = (topLeft[0]+botRight[0])/2; newbotRight[1] = (topLeft[1]+botRight[1])/2;
        build( T+1 , node->m_nodes[0], newtopLeft, newbotRight, 1);
      
        newtopLeft[0] = (topLeft[0] + botRight[0]) / 2;
        newbotRight[0] = botRight[0];
        build( T+1 , node->m_nodes[1], newtopLeft, newbotRight, 2);

        newtopLeft[0] = topLeft[0]; newtopLeft[1] = newbotRight[1]; 
        newbotRight[0] = (topLeft[0]+botRight[0])/2; newbotRight[1] = botRight[1];
        build( T+1 , node->m_nodes[2], newtopLeft, newbotRight, 3);

        newtopLeft[0] = newbotRight[0]; newtopLeft[1] = newtopLeft[1];
        newbotRight[0] = botRight[0];
        build( T+1 , node->m_nodes[3], newtopLeft, newbotRight, 4);
    }

    bool RQTree::insert(Point point)
    {
        return insert(point, m_root);
    }

    bool RQTree::insert(Point point, Node* node)
    {
        if (node == nullptr)
            return 0;
        
        if (overlap(node->m_topLeft, node->m_botRight, point))
            node->m_numpoints++;
        else
            return 0;

        insert(point,node->m_nodes[0]);
        insert(point,node->m_nodes[1]);
        insert(point,node->m_nodes[2]);
        insert(point,node->m_nodes[3]);

        return 1;
    }

    int RQTree::query(std::vector<std::size_t> myVectorQuery)
    {
        if (myVectorQuery.size() == 0 || myVectorQuery.size()-1>m_size)
            return -1;

        Node* i, *j = nullptr; 
        std::size_t k;

        for (i = m_root, k = 1, j = i; i && k < myVectorQuery.size() ; i = (i)->m_nodes[myVectorQuery[k]-1], j = i, k++) { }

        return j->m_numpoints;
    }

#endif