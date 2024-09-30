# FdF
Mi primer desarrollo de código para representación gráfica, utilizando la libreria ***MinilibX***, desarrollada por **42**.

Se trata de la creación de un modelo tridimensional de estructura alámbrica, mediante la unión de puntos según sus coordenadas x, y, z, a partir de un archivo de entrada de extensión ***.fdf***.

Dicho archivo contiene la relación de coordenadas que conforman el modelo. Cada elemento del modelo se encuentra identificado por la posición en X e Y que ocupa, con la altura en Z correspondiente al valor del elemento, de acuerdo a lo siguiente:

~~~
$>cat 42.fdf
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0
0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
~~~

Con la ejecución, se debe obtener una representación tridimensional alámbrica del modelo, en perspectica isométrica:

![Image text](https://github.com/Muriber/Inception/blob/master/img/example.png)
