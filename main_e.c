int     main(void)
{
        stack   a;
        stack   b;
        t_op    *op_list;

        op_list = NULL; // Wichtig: Befehlsliste für die Optimierung vorbereiten

        // 1. Initialisierung von Stack A mit unsortierten Werten
        // HINWEIS: Wenn du hier mehr als 5 Werte einträgst, erhöhe a.size entsprechend!
        a.size = 5;
        a.data = new_node(7);
        a.data->next = new_node(2);
        a.data->next->next = new_node(9);
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

        // Hier war vorher nur simple_sort. Jetzt ist hier die dynamische Weiche:
        if (a.size <= 3)
                sort_three(&a, &op_list);
        else if (a.size <= 5)
                simple_sort(&a, &b, &op_list);
        else
                medium_sort(&a, &b, &op_list);

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
