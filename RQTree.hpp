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
    
    #include <limits>
    #include <map>
    #include <utility>

    class RQTree {
        private:
            //Point topLeft; Point botRight;
            

        public:
            Node* m_root = nullptr;
            std::size_t m_size;
            std::size_t m_dimension;
           
            /* Constructor and destructor */
            RQTree  ( std::size_t, Point, Point );
            //~RQTree ();

            /* Main functions */
            void build( std::size_t , Node*&, Point, Point, std::size_t R = 1);
            /* Getters */
           
            /* Utilities */
            bool is_empty();
            
            /* Overloads */

    };

    RQTree::RQTree( std::size_t T, Point topLeft, Point botRight)
    {
       m_size = T;
       m_root = nullptr; 
       build(0, m_root, topLeft, botRight);
    }

    void RQTree::build( std::size_t T , Node* &node, Point topLeft, Point botRight,  std::size_t R)
    {
        node = new Node(T, topLeft, botRight);
        
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

#endif