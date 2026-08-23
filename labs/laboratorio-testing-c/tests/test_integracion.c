#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_compra_con_descuento(void) {
    printf("\n[integracion: compra con 10%% de descuento]\n");
    Carrito c;
    carrito_init(&c);
    
    Producto p1 = {"Pan", 200, 3};    /* $600 */
    Producto p2 = {"Leche", 350, 2};  /* $700 */
    
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    
    int total = carrito_total(&c);
    
    /* El total esperado es 600 + 700 = 1300 */
    ASSERT_IGUAL(1300, total);
    
    /* El total con descuento del 10% esperado es 1170 */
    ASSERT_IGUAL(1170, carrito_descuento(total, 10));
}
/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_agregar_hasta_llenar(void) {
    printf("\n[integracion: agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Queso", 1500, 1};
    
    /* 1. Llenar el carrito hasta su capacidad máxima (4 productos) */
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    
    /* 2. Verificar que el conteo es MAX_ITEMS (4) */
    ASSERT_IGUAL(4, carrito_contar(&c));
    
    /* 3. Verificar que intentar agregar uno más devuelve 0 */
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
    
    /* 4. Verificar que el conteo sigue siendo MAX_ITEMS (no cambió) */
    ASSERT_IGUAL(4, carrito_contar(&c));
}
/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
