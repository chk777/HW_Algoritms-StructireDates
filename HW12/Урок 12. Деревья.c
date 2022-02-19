#include <stdio.h>
#include <string.h>
#include <malloc.h>


struct node // инициализация структура для представления узлов дерева
{
    int key = 10000;
    int size;
    // Выделение памяти под корень дерева
    node *tmp = malloc(sizeof(node));
    // Присваивание значения ключу
    tmp -> key = key;
    // Присваивание указателю на левое и правое поддерево значения NULL
    node* left;
    node* right;
    node(int k) { key = k; left = right = 0; size = 1; }
    root = tmp;
    return root;
};

==============================================================

int main(void) {
    node* insert(node* p = 50, int k) // рандомизированная вставка нового узла с ключом k в дерево p
    {
        if( !p ) return new node(k);
        if( rand()%(p->size+1)==0 )
            return insertroot(p,k);
        if( p->key>k )
            p->left = insert(p->left,k);
        else
            p->right = insert(p->right,k);
        fixsize(p);
        return p;
    }
    //Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве.
    node* find(node* p, int k) // поиск ключа k в дереве p
    {
        if( !p ) return 0; // игнорируем поиск в пустых деревьях
        if( k == p->key )
            return p;
        if( k < p->key )
            return find(p->left,k);
        else
            return find(p->right,k);
    }
}
