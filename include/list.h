/*
** EPITECH PROJECT, 2018
** CPE_pushswap_bootstrap_2018
** File description:
** __DESCRIPTION__
*/

typedef struct s_list
{
    int nb;
    struct s_list *next;
}list_t;

int is_list_sorted(list_t **la);
int add_element_head(list_t **liste, int nb);
int add_element_end(list_t **liste, int nb);
void show_list(list_t *liste);
void free_list(list_t *liste);
int find_list_size(list_t *liste);
int delete_first_node(list_t **liste);
int delete_last_node(list_t **liste);
int swap_two_nodes(list_t *node1, list_t *node2);
int sort_list(list_t **la, list_t **lb);
int sa(list_t **la, list_t **lb);
int sb(list_t **la, list_t **lb);
int sc(list_t **la, list_t **lb);
int pa(list_t **la, list_t **lb);
int pb(list_t **la, list_t **lb);
int ra(list_t **la, list_t **lb);
int rb(list_t **la, list_t **lb);
int rr(list_t **la, list_t **lb);
int rra(list_t **la);
int rrb(list_t **lb);
int rrr(list_t **la, list_t **lb);
