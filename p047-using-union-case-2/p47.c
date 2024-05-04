// A store sells two kinds of items:- Books & Shirts. 
// Store owners want to keep records of the above mentioned items along with the relevant information.
// Books: Title, Author, number of pages, price
// Shirts: Color, size, design, price
#include <stdio.h>
struct store{
    double price;
    union {
        struct {
            char *title;
            char *author;
            int no_pages;
        }book;
        struct shirt{
            char *color;
            int size;
            char *design;
        }shirt;
    }item;
};
void main(){
    struct store s;
    s.item.book.title = "History of Mankind";
    s.item.book.author = "Elvin J Alapatt";
    s.item.book.no_pages = 499;
    s.price = 1299;

    printf("Details\n");
    printf("-------\n");
    printf("Title : %s\n", s.item.book.title);
    printf("Author : %s\n", s.item.book.author);
    printf("No. Pages : %d\n", s.item.book.no_pages);
    printf("Title : %f\n", s.price);
}