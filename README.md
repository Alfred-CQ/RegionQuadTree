# RegionQuadTree - Structure

### Espacio del ejemplo

- En el ejemplo del archivo main, T son las divisiones que se realizan en este caso T = 3, el limite superior topLeft{100,100} y el limite inferior es botRight{0,0}

![](https://github.com/Alfred-CQ/RegionQuadTree/blob/main/img/Allpoints.png)

### Formato de las regiones
- Para rotular las regiones utilizamos enteros del 1 al 4 que se van enumerando recursivamente.

![](https://github.com/Alfred-CQ/RegionQuadTree/blob/main/img/regions.PNG)

### Consultas de ejemplo
- Para obtener la región global, es simplemente consultar por el número 1, por la enumeración recursiva.
- La consultas siguen el siguiente formato, donde el primer elemento es la region global, y los siguientes elementos, son las subregiones enumeradas(1-4):
```c++
std::vector<std::size_t> query = {1, 1, 1, 2};
```
![](https://github.com/Alfred-CQ/RegionQuadTree/blob/main/img/queries.png)