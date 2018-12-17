int		bactrack(char **grid, int index_pos)
{
	int i;
	int j;
	int check;

	if (index_pos == 9 * 9)
		return (TRUE);
	i = index_pos / 9;
	j = index_pos % 9;
	if (grid[i][j] != '0')
		return (backtrack(grid, index_pos + 1));
	check = '1';
	while (check <= '9')
	{
		if (check_in(check, i, j, grid) == TRUE)
		{
			grid[i][j] = check;
			if (backtrack(grid, index_pos + 1) == TRUE)
				return (TRUE);
		}
		check++;
	}
	grid[i][j] = '0';
	return (FALSE);
}
