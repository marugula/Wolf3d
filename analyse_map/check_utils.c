#include "analyse_map.h"

int	strarr_len(char **arr)
// Длинна массива строк
{
	int	i;

	i = 0;
	while(arr && arr[i])
		i++;
	return (i);
}

int	is_player_ch(char ch)
{
	if (ch == 'N' || \
			ch == 'S' || \
			ch == 'E' || \
			ch == 'W')
		return (1);
	else
		return (0);
}

int	is_allowed_ch(char ch)
{
	if (ch == ' ' || \
			ch == '1' || \
			ch == '0' || \
			ch == 'C' || \
			ch == 'M' || \
			ch == 'N' || \
			ch == 'S' || \
			ch == 'E' || \
			ch == 'W')
		return (VALID_OK);
	else
		return (VALID_ERR);
}

char	get_ch_in_dot(int x, int y, char **map)
// Возвращает символ позиции или 0 если вышли за пределы карты
{

	if (map && y < strarr_len(map) && y >= 0  && x < (int)ft_strlen(map[y]) && x >= 0)
		return (map[y][x]);
	else
		return (0);
}