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

char	get_ch_in_dot(int x, int y, char **map)
// Возвращает символ позиции или 0 если вышли за пределы карты
{

	if (map && y < strarr_len(map) && y >= 0  && x < (int)ft_strlen(map[y]) && x >= 0)
		return (map[y][x]);
	else
		return (0);
}

int	check_first_or_last_line(char *line)
{
	char	*checked_line;
	char	*temp;

	checked_line = ft_strtrim(line, " ");
	if (checked_line == NULL)
		// Собщение об ошибке
		exit(1);
	temp = checked_line;
	while (*temp)
	{
		if (!(*temp == '1' || *temp == ' '))
			return (VALID_ERR);
		temp++;
	}
	free(checked_line);
	return (0);
}

int	check_first_and_last_char(char	*str)
/* Проверка на первый и последний ряд карты (только 1 и _) */
{
	char	*checked_line;
	int		ret_val;
	checked_line = ft_strtrim(str, " ");
	if (checked_line == NULL)
		// Сообщение об ошибке
		exit(1);
	if (checked_line[0] != '1' || checked_line[0] != '1')
		ret_val = VALID_ERR;
	else
		ret_val = VALID_OK;
	free(checked_line);
	return (ret_val);
}

int	check_side_wals(char **map)
/* 2) Проверка первых символов строк (после пробелов только 1) */
{
	while(*map != NULL)
	{
		if (check_first_and_last_char(*map) == VALID_ERR)
			return (VALID_ERR);
		map++;
	}
	return (VALID_OK);
}

int check_space_around_dot(t_dot dot, char **map)
{
	char	ch_at_dot;

	ch_at_dot = get_ch_in_dot(dot.x - 1, dot.y, map);								// Символ слева
	if (!(ch_at_dot == 0 || ch_at_dot == ' ' || ch_at_dot == '1'))
		return (VALID_ERR);
	ch_at_dot = get_ch_in_dot(dot.x + 1, dot.y, map);								// Символ справа
	if (!(ch_at_dot == 0 || ch_at_dot == ' ' || ch_at_dot == '1'))
		return (VALID_ERR);
	ch_at_dot = get_ch_in_dot(dot.x, dot.y - 1, map);								// Символ сверху
	if (!(ch_at_dot == 0 || ch_at_dot == ' ' || ch_at_dot == '1'))
		return (VALID_ERR);
	ch_at_dot = get_ch_in_dot(dot.x, dot.y + 1, map);								// Символ снизу
	if (!(ch_at_dot == 0 || ch_at_dot == ' ' || ch_at_dot == '1'))
		return (VALID_ERR);
	return (VALID_OK);
}

int	check_all_space(char **map)
/* 3) В цикле проверка пробелов ( вокруг пробелов либо только пробелы либо только единицы)*/
{
	t_dot	dot;


	dot.y = 0;
	while(map[dot.y] != NULL)
	{
		dot.x = 0;
		while (map[dot.y][dot.x] != 0)
		{
			if (map[dot.y][dot.x] == ' ' && check_space_around_dot(dot, map) == VALID_ERR)
				return (VALID_ERR);
			dot.x++;
		}
		dot.y++;
	}
	return (VALID_OK);
}

int	check_game_map(char **map)
// 0 if map is correct, 1 if is not
{
	if (strarr_len(map) < 3)
		return (VALID_ERR);
	if (check_first_or_last_line(map[0]) == VALID_ERR || \
		check_first_or_last_line(map[strarr_len(map) - 1]) == VALID_ERR || \
		check_side_wals(map) == VALID_ERR || \
		check_all_space(map) == VALID_ERR)
		// Проверка на лишние символы и
		// ЕДИНСТВЕННОЕ обозначение игрока
		return (VALID_ERR);
	return (VALID_OK);
}
