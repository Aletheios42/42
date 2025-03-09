#include "libft.h"

void *ft_realloc(void *old_ptr, size_t chunk_size, size_t num_chunks) {
    void *new_ptr;
    size_t total_size;

    total_size = chunk_size * num_chunks;

    // Si old_ptr es NULL, malloc de nuevo el espacio
    if (!old_ptr)
        return malloc(total_size);

    // Intentamos hacer realloc en el puntero original
    new_ptr = realloc(old_ptr, total_size);
    
    // Si realloc falla, el valor de new_ptr es NULL
    if (!new_ptr) {
        // Si realloc falla, devolvemos NULL, y old_ptr sigue siendo válido
        return NULL;
    }

    return new_ptr;
}

