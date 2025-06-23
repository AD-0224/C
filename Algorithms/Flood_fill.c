/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:54:15 by marvin            #+#    #+#             */
/*   Updated: 2025/03/26 22:54:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void    fill(char **tab, t_point size, t_point cur, char to_fill) //fonction recursive tu commences ou et tu remplie avec quoi 
{
    if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
    return;
    tab[cur.y][cur.x] = 'F'; // Remplit la position actuelle avec le caractère 'F'
    fill(tab, size, (t_point) {cur.x - 1, cur.y}, to_fill); //gauche
    fill(tab, size, (t_point) {cur.x + 1, cur.y}, to_fill); //droite
    fill(tab, size, (t_point) {cur.x, cur.y - 1}, to_fill); //haut
    fill(tab, size, (t_point) {cur.x, cur.y + 1}, to_fill); //bas
}
void    flood_fill(char **tab, t_point size, t_point begin) //t_point c'est des structures
{
    // Appelle la fonction fill avec le point de départ et le caractère à remplir
    fill(tab, size, begin, tab[begin.y][begin.x]);
}  
