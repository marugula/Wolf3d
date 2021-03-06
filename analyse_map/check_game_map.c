#include "analyse_map.h"

int	check_game_map(char **map)
// 0 if map is correct, 1 if is not
{
	if (strarr_len(map) < 3)
		return (VALID_ERR);
	if (check_first_or_last_line(map[0]) == VALID_ERR || \
		check_first_or_last_line(map[strarr_len(map) - 1]) == VALID_ERR || \
		check_side_wals(map) == VALID_ERR || \
		check_all_dot(map) == VALID_ERR)
		return (VALID_ERR);
	return (VALID_OK);
}
