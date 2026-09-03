#include "push_swap.h"
#include <stdio.h>

// Hilfsfunktion: Gibt den aktuellen Inhalt eines Stacks im Terminal aus
void    print_stack(char *name, stack *s)
{
        t_list  *current;

        printf("Stack %s (Size: %d): ", name, s->size);
        if (!s || !s->data)
        {
                printf("[Leer]\n");
                return ;
        }
        current = s->data;
        while (current)
        {
                printf("%d ", current->content);
                current = current->next;
        }
        printf("\n");
}

// Hilfsfunktion: Erstellt manuell eine neue Node
t_list  *new_node(int value)
{
        t_list  *node;

        node = malloc(sizeof(t_list));
        if (!node)
                return (NULL);
        node->content = value;
        node->next = NULL;
        return (node);
}

// Hilfsfunktion: Gibt den gesamten Stack am Ende wieder frei
void    free_stack(stack *s)
{
        t_list  *current;
        t_list  *next;

        if (!s || !s->data)
                return ;
        current = s->data;
        while (current)
        {
                next = current->next;
                free(current);
                current = next;
        }
        s->data = NULL;
        s->size = 0;
}

int     main(void)
{
        stack   a;
        stack   b;
        t_op    *op_list;

        op_list = NULL; // Wichtig: Befehlsliste für die Optimierung vorbereiten

        // 1. Initialisierung von Stack A mit unsortierten Werten (z. B. 5, 2, 1, 4, 3)
        // Du kannst diese Werte hier beliebig ändern, um verschiedene Fälle zu testen!
        a.size = 5;
        a.data = new_node(5);
        a.data->next = new_node(2);
        a.data->next->next = new_node(1);
        a.data->next->next->next = new_node(4);
        a.data->next->next->next->next = new_node(3);

        // 2. Initialisierung von Stack B: Komplett LEER nach 42-Regel
        b.size = 0;
        b.data = NULL;

        // --- TESTPHASE ---
        printf("--- STARTZUSTAND ---\n");
        print_stack("A", &a);
        print_stack("B", &b);
        printf("\n--- STARTE SORTIERUNG ---\n");

        // Führe deinen echten Sortieralgorithmus aus
        simple_sort(&a, &b, &op_list);

        printf("--- ENDZUSTAND ---\n");
        print_stack("A", &a); // Sollte nun aufsteigend sortiert sein
        print_stack("B", &b); // Sollte am Ende wieder komplett leer sein
        printf("\n");

        printf("--- OPTIMIERTE BEFEHLSAUSGABE ---\n");
        // Befehle durch den Post-Processor jagen, ausgeben und Speicher befreien
        optimize_operations(&op_list);
        print_and_free_ops(op_list);

        // 3. Speicher der Stacks sauber freigeben
        free_stack(&a);
        free_stack(&b);

        return (0);
}
