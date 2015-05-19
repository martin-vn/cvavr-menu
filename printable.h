#ifndef PRINTABLE_H
#define PRINTABLE_H

struct _TPrintable;
typedef void (*TPrintAction)(struct _TPrintable FLASH *);

typedef struct _TPrintable {
    TPrintAction print;
} TPrintable;

#define PRINTABLE_INIT(print_action) {print_action}
#define PRINTABLE_PRINT(obj) ((FLASH TPrintable *) obj)->print((FLASH TPrintable *) obj)

#endif
