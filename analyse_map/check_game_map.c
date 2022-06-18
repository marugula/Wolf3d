#include "analyse_map.h"




typedef struct t_move_on_map
{
	int	x;
	int	y;
} t_dot;


int	strarr_len(char **arr)
// Длинна массива строк
{
	int	i;

	i = 0;
	while(arr && arr[i])
		i++;
	return (i);
}

char	get_ch_in_dot(t_dot dot, char **map)
// Возвращает символ позиции или 0 если вышли за пределы карты
{

	if (map && dot.y <= strarr_len(map) && dot.x <= ft_strlen(map[dot.y]))
		return (map[dot.y][dot.x]);
	else
		return (0);
}

int	find_first_wall



int	check_game_map(char **map)
// 1 if map is correct, 0 if is not
{
	int		i;
	t_dot	dot;

	i = 0;
	dot.x = 0;
	dot.y = 0;
	if (strarr_len(map) < 3)
		return (0)




}