/*
 * Punto N Dimensional
 * Chillitupa Quispihuanca, Alfred Addison
 * Estructuras de Datos Avanzadas
 * CCOMP6-1
 * C++
 * Point.hpp
*/

#ifndef _POINT_HPP_
    #define _POINT_HPP_

    #include <iostream>

    #include <math.h>
    
    class Point{
        
        private:
            
            std::size_t m_size   = 2;
            std::size_t beg      = 0;
            std::size_t end      = m_size - 1;

            float m_coordinates[2];
        
        public:
            /* Constructors and Destructor */
            Point  ();
            Point  (float*);
            
            ~Point ();
            
            /* Setters */
            bool setIndexValue (std::size_t, float);

            /* Getters */
            std::size_t get_size()    const;
            float*   get_content() const;

            /* Overloads */
            bool      operator ==  (const Point&);
            bool      operator !=  (const Point&);
            bool      operator >=  (const Point&);
            bool      operator <=  (const Point&);

            Point& operator =   (const Point&);
            float  operator []  (std::size_t) const;
            float& operator []  (std::size_t);

            /* Utilities */
            void printContent ();
            bool outOfBounds  (std::size_t);
    };

    /* Implementation - Constructors and Destructor */
    Point::Point()
    { 
        std::size_t i;
        for ( i = 0; i < m_size; ++i)
            m_coordinates[i] = 0;
    }

    Point::Point(float coordinates[])
    { 
        std::size_t i;
        for ( i = 0; i < m_size; ++i)
            m_coordinates[i] = coordinates[i];
    }

    Point::~Point()
    { 
       
    }

    /* Implementation - Setters */
    bool Point::setIndexValue(std::size_t index, float value)
    { 
        if (outOfBounds(index))
            return 0;
        
        m_coordinates[index] = value;
    }

    /* Implementation - Getters */
    std::size_t Point::get_size() const
    {
        return m_size;
    }
           

    /* Implementation - Overloads */
    bool Point::operator == (const Point& point) 
    {
        std::size_t i;

        for ( i = 0; i < m_size; ++i)
            if (m_coordinates[i] != point[i])
                return 0;
        
        return 1;
    }

    bool Point::operator != (const Point& point) 
    {
        return !(*this == point);
    }

    bool Point::operator >= (const Point& point) 
    {
        return (m_coordinates[0] >= point[0]) && (m_coordinates[1] >= point[1]);
    }

    bool Point::operator <= (const Point& point) 
    {
        return (m_coordinates[0] <= point[0]) && (m_coordinates[1] <= point[1]);;
    }

    Point& Point::operator = (const Point& point)
    {
        if (*this == point)
            return *this;
        
        std::size_t i;
        for ( i = 0; i < m_size; ++i)
            m_coordinates[i] = point[i];

        return *this;
    }

    float Point::operator[] (size_t index) const{
        return m_coordinates[index];
    }

    float& Point::operator[] (size_t index){
        return m_coordinates[index];
    }

    /* Implementation - Utilities */
    bool Point::outOfBounds(std::size_t index)
    { 
        if (index >= m_size) 
        {
            std::cout << "Array index out of bound, exiting...\n";
            return 1;
        }
        return 0;
    }

    void Point::printContent()
    { 
        std::size_t i;
        
        std::cout << "{ ";
        for ( i = 0; i < m_size; ++i)
            std::cout << m_coordinates[i] << " ";
        std::cout << "}\n";
    }

    // Implementation - Adicional 
    bool overlap(Point topLeft, Point botRight, Point point)
    {
        return (point <= topLeft && point >= botRight);
    }
      

#endif