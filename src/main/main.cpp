#include <spdlog/spdlog.h>

int main()
{
	spdlog::set_level(spdlog::level::trace);

	spdlog::debug("Hello world");
	return 0;
}