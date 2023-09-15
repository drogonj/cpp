
#include "includes.hpp"

std::string	collect_data(char *filename)
{
	std::ifstream	file(filename);
	std::string		buffer = "";
	std::string		line = "";

	if (!file.is_open())
	{
		std::cerr << "error: can't open input file" << std::endl;
		exit(EXIT_FAILURE);
	}
	while (std::getline(file, line))
		buffer += line + '\n';
	file.close();
	return (buffer);
}

void	create_replace(char **argv, std::string data)
{
	std::string		new_filename = (std::string)argv[1] + ".replace";
	std::ofstream	output(new_filename);
	long long int	i;

	if (!output.is_open())
	{
		std::cerr << "error: can't open or create output file" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (long long int j = 0; j < (long long int)data.size(); j++)
	{
		i = data.find(argv[2], j);
		if (i == j)
		{
			output << argv[3];
			j += std::string(argv[2]).size() - 1;
		}
		else
			output << data[j];
	}
	output.close();
}

int main(int argc, char **argv)
{
	std::string	buffer;

	if (argc != 4)
	{
		std::cerr << "error: bad number of arguments" << std::endl;
		return (1);
	}
	buffer = collect_data(argv[1]);
	create_replace(argv, buffer);
	return (0);
}