
Prototipo de Realidad Aumentada para clases de geometría 3D
-------------------------------------------------------------------

Este programa utiliza una combinación de herramientas open source, y técnicas, 
para mostrar una figura geométrica 3D sobre un vídeo en tiempo real.

Una posible aplicación de este proyecto es en educación, cuando 
se explican diferentes conceptos relativos a figuras 3D en clases 
de álgebra y geometría.

El sistema presenta la figura 3D seleccionada por el usuario a la 
altura de la cintura de quien dicta la clase. Tambien rota
la misma en base a la postura de un smartphone. La profesora (o profesor)
puede entonces colocar la figura 3D en la posición que desee, al momento
de explicar diferentes conceptos geométricos relacionadas con la misma.

La figura geométrica se desplaza junto a la profesora, para mantener
la realidad aumentada.


Técnica
-------

Se utilizan diferentes técnicas para obtener la actitud y posición 
del lugar exacto donde presentar la figura 3d.

El smartphone envía por UDP en tiempo real los datos crudos de sus acelerómetro.
Con estos datos la aplicación calcula la postura (actitud) del smartphone,
que luego se utiliza para rotar la figura 3D a la postura equivalente
del móvil.

Se utiliza detección de rostros para identificar el ancho del rostro
de la profesora (o profesor). En base a este cálculo, se puede estimar
a qué distancia está la persona de la cámara, y además, lograr identificar
la ubicación de la cintura del profesor en la escena.

Describimos ahora la ténica para obtener la actitud del smarthone:

Cuando un móvil está quieto, el acelerómetro mide principalmente la aceleración debida a la gravedad. Esta tiene una magnitud de unos 9.81 m/s² y su dirección indica hacia dónde está el "suelo" en el sistema de coordenadas del dispositivo. A partir de ese vector, se puede estimar la actitud (orientación) en términos de inclinación: pitch (inclinación frontal) y roll (lateral). El yaw (rotación sobre el eje vertical) no puede determinarse con el acelerómetro solo.

El acelerómetro entrega un vector:

a = [ax, ay, az]

Primero se normaliza:

norm = sqrt(ax^2 + ay^2 + az^2)
gx = ax / norm
gy = ay / norm
gz = az / norm

Los ángulos se calculan así:

roll = atan2(gy, gz)
pitch = atan2(-gx, sqrt(gy^2 + gz^2))

Estos ángulos indican cómo se orienta el móvil respecto a la gravedad. Por ejemplo, si gz ≈ -1, la pantalla está hacia arriba; si gy ≈ 1, el móvil está de canto. Solo con este sensor, podemos conocer cómo de inclinado está el dispositivo, pero no su orientación norte-sur.

