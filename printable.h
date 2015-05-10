#ifndef PRINTABLE_H
#define PRINTABLE_H

FLASH struct _TPrintable;
typedef void (*TPrintAction)(FLASH struct _TPrintable FLASH *);

typedef FLASH struct _TPrintable {
    TPrintAction print;
} TPrintable;

#define PRINTABLE_INIT(print_action) {print_action}
#define PRINTABLE_PRINT(obj) ((FLASH TPrintable *) obj)->print((FLASH TPrintable *) obj)

#endif
