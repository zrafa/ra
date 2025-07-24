
#ifndef FIGURAS_H
#define FIGURAS_H

void dibujar_cubo(float size);
void dibujar_esfera(float radius, int slices, int stacks);
void dibujar_cono(float base, float height, int slices, int stacks);
void dibujar_cilindro(float radius, float height, int slices, int stacks);
void dibujar_toroide(float innerRadius, float outerRadius, int sides, int rings);
void dibujar_taza(float radius, float height, int slices, int stacks);

#endif // FIGURAS_H
