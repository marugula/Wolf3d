#include "analyse_map.h"




typedef struct t_move_on_map
{
	int	x;
	int	y;
} t_dot;


char	strarr_len(char **arr)
{
	int	i;

	i = 0;
	while(arr && arr[i])
		i++;
	return (i);
}


char	get_ch_in_dot(t_dot dot, char **map)
{

	if (dot.y > strarr_len(map) || dot.x > ft_strlen(map[dot.y]))
		return (0);

	





}




int	check_game_map(char **map)
{
	int		i;
	t_dot	dot;
	i = 0;



}