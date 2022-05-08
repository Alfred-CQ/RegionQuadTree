/*
 * Node RQTree
 * Chillitupa Quispihuanca, Alfred Addison
 * Estructuras de Datos Avanzadas
 * CCOMP6-1
 * C++
 * Node.hpp
*/

#ifndef _NODE_HPP_
    #define _NODE_HPP_

    #include "Point.hpp"

    class Node {
        public:
            Point m_topLeft, m_botRight;

            Node* m_nodes[4];

            // 1 -> TopLeft
            // 2 -> TopRight
            // 3 -> BotLeft
            // 4 -> BotRight
            
            std::size_t m_region;
            std::size_t m_level;
            std::size_t m_numpoints;

            Node();
            Node(std::size_t level, Point topLeft, Point botRight, std::size_t region)
            {
                m_level = level;
                m_region = region;
                m_topLeft = topLeft;
                m_botRight = botRight;
                m_numpoints = 0;
                m_nodes[0] = nullptr; m_nodes[1] = nullptr;
                m_nodes[2] = nullptr; m_nodes[3] = nullptr;
            };
    };

#endif