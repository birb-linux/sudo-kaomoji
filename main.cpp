#include <array>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

/* Source: http://kaomoji.ru/en/ */
const std::array kaomoji {
	"(*・ω・)ﾉ", "(^-^*)/", "ヾ(*'▽ '*)", "(^０^)ノ", "(*°ｰ°)ﾉ",
	"(￣ω￣)/", "(≧▽ ≦)/", "(￣▽ ￣)ノ", "(＠´ー`)ﾉﾞ", "~ヾ(・ω・)",
	"(・_・)ノ", "( ´ ω ` )ノﾞ", "(°▽ °)/", "(´• ω •`)ﾉ",
	"(・∀・)ノ", "(o´ω`o)ﾉ", "(⌒ ω ⌒ )ﾉ", "(o´▽ `o)ﾉ", "( ´ ∀ ` )ﾉ",
	"( ° ∀ ° )ﾉﾞ", "( ´ ▽ ` )ﾉ", "ヾ(・ω・*)", "( ´ ▽ ` )/",
	"(o^ ^o)/", "(￣▽ ￣)/"
};

const std::string message = "Mayw I hav ur passwrd sir";

int main(void)
{
	unsigned int seed = 0;

	/* Read a few bytes from /dev/urandom */
	std::ifstream urandom("/dev/urandom", std::ios::binary);
	if (urandom.is_open())
	{
		urandom.read(reinterpret_cast<char*>(&seed), sizeof seed);
		urandom.close();
	}

	srand(seed);

	int random_kaomoji = std::rand() / ((RAND_MAX + 1u) / kaomoji.size());
	std::cout << kaomoji[random_kaomoji] << " " << message << ": \n";

	return 0;
}
