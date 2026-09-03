/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroeker <ebroeker@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:23:59 by ebroeker          #+#    #+#             */
/*   Updated: 2026/08/17 18:30:26 by ebroeker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add_op(t_op **head, char *cmd) {
    t_op *new_node;
    t_op *last;

    if (!head) return (0);
    new_node = malloc(sizeof(t_op));
    if (!new_node) return (0); // Error-Handling für Malloc-Fehler

    new_node->cmd = cmd; // Verweist direkt auf den String-Literal (z.B. "ra")
    new_node->next = NULL;

    if (!*head) {
        new_node->prev = NULL;
        *head = new_node;
        return (1);
    }
    last = *head;
    while (last->next) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    return (1);
}

// Hilfsfunktion: Löscht zwei Knoten aus der Liste, wenn sie sich aufheben
void delete_nodes(t_op **head, t_op *first, t_op *second) {
    if (first->prev) first->prev->next = second->next;
    else *head = second->next; // Wenn 'first' der Kopf der Liste war

    if (second->next) second->next->prev = first->prev;

    free(first);
    free(second);
}

void combine_nodes(t_op *first, t_op *second, char *new_cmd) 
{
    first->cmd = new_cmd;
    first->next = second->next;
    if (second->next) second->next->prev = first;
    free(second);
}

// Die Hauptoptimierungs-Funktion
void optimize_operations(t_op **head) 
{
    if (!head || !*head) return;

    t_op *curr = *head;
    while (curr && curr->next) {
        t_op *next = curr->next;

        // FALL 1: Befehle heben sich gegenseitig auf (z.B. ra und rra)
        if ((strcmp(curr->cmd, "ra") == 0 && strcmp(next->cmd, "rra") == 0) ||
            (strcmp(curr->cmd, "rra") == 0 && strcmp(next->cmd, "ra") == 0) ||
            (strcmp(curr->cmd, "rb") == 0 && strcmp(next->cmd, "rrb") == 0) ||
            (strcmp(curr->cmd, "rrb") == 0 && strcmp(next->cmd, "rb") == 0) ||
            (strcmp(curr->cmd, "pa") == 0 && strcmp(next->cmd, "pb") == 0) ||
            (strcmp(curr->cmd, "pb") == 0 && strcmp(next->cmd, "pa") == 0)) {

            t_op *prev_node = curr->prev;
            delete_nodes(head, curr, next);
            // Nach dem Löschen gehen wir einen Schritt zurück, um neue Nachbarn zu prüfen
            curr = prev_node ? prev_node : *head;
            continue;
        }

        // FALL 2: Befehle können kombiniert werden (z.B. ra + rb -> rr)
        if ((strcmp(curr->cmd, "ra") == 0 && strcmp(next->cmd, "rb") == 0) ||
            (strcmp(curr->cmd, "rb") == 0 && strcmp(next->cmd, "ra") == 0)) {
            combine_nodes(curr, next, "rr");
            continue; // curr bleibt gleich, prüft im nächsten Durchlauf das neue "rr" mit dem danach
        }
        if ((strcmp(curr->cmd, "rra") == 0 && strcmp(next->cmd, "rrb") == 0) ||
            (strcmp(curr->cmd, "rrb") == 0 && strcmp(next->cmd, "rra") == 0)) {
            combine_nodes(curr, next, "rrr");
            continue;
        }
        if ((strcmp(curr->cmd, "sa") == 0 && strcmp(next->cmd, "sb") == 0) ||
            (strcmp(curr->cmd, "sb") == 0 && strcmp(next->cmd, "sa") == 0)) {
            combine_nodes(curr, next, "ss");
            continue;
        }

        curr = curr->next;
    }
}
void print_and_free_ops(t_op *head)
{
    t_op *tmp;

    while (head) 
    {
        tmp = head->next;
        printf("%s\n", head->cmd); // Befehl ausgeben
        free(head);                // Struktur-Knoten befreien
        head = tmp;
    }
}
