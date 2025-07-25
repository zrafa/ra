
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

## Cómo utilizar

0. Instalar en la laptop o PC opengl, opencv, y un compilador de c++
1. Instalar en el celular la aplicación sensagram https://github.com/umer0586/SensaGram
2. Configurar sensagram: seleccionar como sensor acelerometro. y Colocar la IP de la laptop o PC
3. Compilar y ejecutar la aplicación:

```
git clone http://github.com/zrafa/ra
cd ra
./compilar.sh
./figuras_camara 2 toroide
```

## Técnica

Se utilizan diferentes técnicas para obtener la actitud y posición 
del lugar exacto donde presentar la figura 3d.

#### Potura

El smartphone envía por UDP en tiempo real los datos crudos de sus acelerómetro.
Con estos datos la aplicación (en la laptop o PC) calcula la postura (actitud) 
del smartphone, que luego se utiliza para rotar la figura 3D a la postura equivalente del móvil.

#### Distancia y ubicación

Se utiliza detección de rostros para identificar el ancho del rostro
de la profesora (o profesor). En base a este cálculo, se puede estimar
a qué distancia está la persona de la cámara, y además, lograr identificar
la ubicación de la cintura del profesor en la escena.

Con el tamaño del rostro el sistema calcula también el tamaño ideal para
la figura 3D, por lo que si el profesor se acerca o aleja de la cámara
la figura dibujada tendrá un tamaño proporcional, continuando con una
visión de realidad aumentada acorde.

#### Video proyectado

Con la información calculada: postura, tamaño del rostro de la profesora,
distancia de la profesora a la cámara, tamaño ideal para el objeto 3D,
ubicación de la profesora en la escena, ubicación calculada para el objeto 
3D, la aplicación realiza lo siguiente:

1. toma la foto que provino de la cámara,
2. dibuja la figura 3D seleccionada por el usuario utilizando opengl
3. Rota la figura 3D para que coincida con la postura del smartphone
4. Traslada la figura 3D a al ubicación de la cintura de la profesora
5. Muestra en pantalla la imagen final 
6. Se repite desde el paso 1. para lograr el video en tiempo real de la
realidad aumentada.

#### En profundidad algunos aspectos...

Describimos ahora la ténica para obtener la actitud del smarthone:

Cuando un móvil está quieto, el acelerómetro mide principalmente la aceleración debido a la gravedad. Esta tiene una magnitud de unos 9.81 m/s² y su dirección indica hacia dónde está el "suelo" en el sistema de coordenadas del dispositivo. A partir de ese vector, se puede estimar la actitud (orientación) en términos de inclinación: pitch (inclinación frontal) y roll (lateral). El yaw (rotación sobre el eje vertical) no puede determinarse con el acelerómetro.

EL smartphone envía los datos del acelerómetro como un vector:

![a = [ax, ay, az]](https://latex.codecogs.com/png.image?\dpi%7B120%7D%20%5Cvec%7Ba%7D%20%3D%20%5Ba_x%2C%20a_y%2C%20a_z%5D)

Primero se normaliza:

![norma de a](https://latex.codecogs.com/png.image?\dpi%7B120%7D%20%5C%7C%5Cvec%7Ba%7D%5C%7C%20%3D%20%5Csqrt%7Ba_x%5E2%20%2B%20a_y%5E2%20%2B%20a_z%5E2%7D)

![gx](https://latex.codecogs.com/png.image?\dpi{120}g_x%20%3D%20\frac{a_x}{\|\vec{a}\|})
![gy](https://latex.codecogs.com/png.image?\dpi{120}g_y%20%3D%20\frac{a_y}{\|\vec{a}\|})
![gz](https://latex.codecogs.com/png.image?\dpi{120}g_z%20%3D%20\frac{a_z}{\|\vec{a}\|})

Entonces se calcula el roll y pitch de la postura del móvil: 

![roll](https://latex.codecogs.com/png.image?\dpi%7B120%7D%20roll%20%3D%20%5Carctan2%28g_y%2C%20g_z%29)

![pitch](https://latex.codecogs.com/png.image?\dpi%7B120%7D%20pitch%20%3D%20%5Carctan2%28-g_x%2C%20%5Csqrt%7Bg_y%5E2%20%2B%20g_z%5E2%7D%29)

Con estos ángulos el sistema ya puede rotar la figura 3D para que coincida
con la postura del móvil. Veamos un ejemplo de de la orientación del
teléfono con respecto a la gravedad. Si gz ≈ -1, la pantalla está hacia arriba; si gy ≈ 1, el móvil está de costado. 
No podemos conocer la orientación cartesiana con sólo dos acelerómetros. 
Se deja como trabajo futuro dos ideas de como se puede lograr si se extiende
este prototipo.


